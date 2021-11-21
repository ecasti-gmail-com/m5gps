#include <M5Stack.h>
#include "Free_Fonts.h"
#include <SD.h>
#include <sqlite3.h>
#define KEYBOARD_I2C_ADDR     0X08
#define KEYBOARD_INT          5



// Store last position
struct gps {
  int fix;
  float lat;
  float lon;
  float high;
  int nsat;
  int nsat_t;
  String fixtime;
  String rawdate;
  float distance;
};

// Store satellites info
struct sat {
  int sat_n;
  int elevation;
  int azimuth;
  int snr;

};



// Store points parts of track
struct points {
  float lat;
  float lon;
  float high;
  int type;
  int groups;
  String name;
  int id;
};



// Distance, expressed in meters, between two points
struct offset_m {
  float x;
  float y;
  float dist;
  int azimuth;
};

struct groups_type {
  String name;
  String description;
  int group_id;
};

sqlite3 *db1;
struct gps mygps;
struct sat mysat[32];


// Waypoints loaded from SD
struct points waypoints[50];
struct groups_type groups[20];
int groups_t = 0;
int tmp_group = 0;

// Points from current track
struct points track[2000];
// Pointer to latest stored position inside the track
int track_pos = -1;

// Latest position received from GPS
struct points current;

// Latest movement
struct offset_m movement;

// Position on last 10 seconds
// Used to get more precision on movement
struct points lasts[10];

// Marked points to use navigating back
//struct points marked[100];
//int mark_p = 0;
//int mark_t = 0;

// Menu offsets
int menu_x;
int menu_y;
int *point_select;
int *point_max;
// Distance covered
float distance = 0;

// Switch to turn off display and block keyboard
int disp_on = 1;
// Return code from sqllite
int rc;
// Waypoint selected from the list
int wp_pos = 0;
// Number of Waypoints loaded into the array
int wp_t = 0;


// NUmber of satellite received from sentence GPGSV
int sv;
// Page displayed
int page = 0;
// Background page, used in pop-up menu
int bg_page = 0;
// Zoom array: meter per pixel
const int zoom[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
// Zoom selected
int c_zoom = 0;
struct offset_m display_offset;

HardwareSerial GPSRaw(2);
String str = "";
// Substring parsed from full GPS sentences
String parsed;

String tmp_name;
int char_position = 0;


void setup() {
  sv = 0;
  //mark_p = 0;
  menu_y = 0;
  menu_x = 0;
  display_offset.x = 0;
  display_offset.y = 0;
  M5.begin();
  M5.Power.begin();
  GPSRaw.begin(9600);
  pinMode(KEYBOARD_INT, INPUT_PULLUP);
  Wire.begin();
  M5.Lcd.setTextFont(0);
  M5.Lcd.setTextSize(0);
  M5.Lcd.setFreeFont(FSB9);
  clear_screen();
  sqlite3_initialize();
  if (openDb("/sd/gps_track.db", &db1))
    return;
  read_waypoints();
  read_position();
  read_groups();
  //read_track();
}
void clear_screen() {
  M5.Lcd.clear(BLACK);
  M5.Lcd.setCursor(0, 140);

}



void refresh() {
  switch (page) {
    case 0:
      // Gps Stat

      sat_circle();
      sat_stats();
      // print_pos_info(220, 130);
      print_sat_info(220, 130);
      print_top_bar();
      print_time();
      print_menu();
      break;
    case 1:
      //track

      // if ( track_pos >= 0)  {
      print_track();
      print_wp();
      //print_wp_single();
      //print_marks();

      // }
      print_odometer();
      print_zoom();

      print_top_bar();
      // print_pos_info(220, 130);
      //print_sat_info(220, 130);
      print_compass_mini();
      print_menu();
      break;
    case 2:
      // if( (mygps.fixtime.endsWith("0")) and ( mygps.fix == 1)) {
      print_compass();
      //}
      print_speed();
      print_odometer();
      print_top_bar();
      print_track_mini();
      print_wp_mini();
      print_menu();
      break;
    case 3:
      print_speed();
      print_odometer();
      print_go_wp();
      print_top_bar();
      print_track_mini();
      print_wp_mini();
      print_menu();
      //print_pos_info(220, 130);
      break;
    case 4:
      //list_wp();
      list_points();
      print_menu();
      break;
    case 5:
      print_position();

      break;
    case 6:
      rename_wp();
      print_menu();
      break;
    case 7:
      delete_wp();
      print_menu();
      break;
    case 8:
      list_groups();
      print_menu();
      break;
    default:

      break;
  }
}

void loop() {

  int i;
  /*
        Input from core buttons and from face keyboard

  */

  M5.update();
  if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200)) {
    button_top_a();
  } else if (M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200)) {
    button_top_b();

  } else if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200)) {
    button_top_c();
  }
  if (digitalRead(KEYBOARD_INT) == LOW) {
    get_data();
  }
  if (GPSRaw.available()) {
    int ch = GPSRaw.read();
    char card;
    str.concat(char(ch));
    if (ch == 10 ) {

      String sent = str.substring(1, 6);



      if (sent ==  "GPRMC") {

        find_term(str, 9);
        mygps.rawdate = parsed.substring(4, 6);
        mygps.rawdate += "-";
        mygps.rawdate += parsed.substring(2, 4);
        mygps.rawdate += "-";
        mygps.rawdate += parsed.substring(0, 2);
        find_term(str, 1);
        mygps.fixtime = parsed.substring(0, 6);
        mygps.rawdate += " ";
        mygps.rawdate += parsed.substring(0, 2);
        mygps.rawdate += ":";
        mygps.rawdate += parsed.substring(2, 4);
        mygps.rawdate += ":";
        mygps.rawdate += parsed.substring(4, 6);

      }
      else if (sent ==  "GPGSV") {

        find_term(str, 3);
        mygps.nsat = parsed.toInt();

        //sat 1
        sv++;

        find_term(str, 4);
        mysat[sv].sat_n = parsed.toInt();
        find_term(str, 5);
        mysat[sv].elevation = parsed.toInt();
        find_term(str, 6);
        // Serial.print(parsed);
        mysat[sv].azimuth = parsed.toInt();
        find_term(str, 7);
        mysat[sv].snr = parsed.toInt();
        //sat 2
        sv++;

        find_term(str, 8);
        mysat[sv].sat_n = parsed.toInt();
        find_term(str, 9);
        mysat[sv].elevation = parsed.toInt();
        find_term(str, 10);
        mysat[sv].azimuth = parsed.toInt();
        find_term(str, 11);
        mysat[sv].snr = parsed.toInt();
        //sat 3
        sv++;

        find_term(str, 12);
        mysat[sv].sat_n = parsed.toInt();
        find_term(str, 13);
        mysat[sv].elevation = parsed.toInt();
        find_term(str, 14);
        mysat[sv].azimuth = parsed.toInt();
        find_term(str, 15);
        mysat[sv].snr = parsed.toInt();
        //sat 4
        sv++;

        find_term(str, 16);
        mysat[sv].sat_n = parsed.toInt();
        find_term(str, 17);
        mysat[sv].elevation = parsed.toInt();
        find_term(str, 18);
        mysat[sv].azimuth = parsed.toInt();
        find_term(str, 19);
        mysat[sv].snr = parsed.toInt();


      }
      else if (sent ==  "GPGGA") {

        find_term(str, 6);
        mygps.fix = parsed.toInt();
        if ( mygps.fix == 1) {
          find_term(str, 7);
          mygps.nsat_t = parsed.toInt();
          find_term(str, 3);
          card = parsed.charAt(1);
          find_term(str, 2);
          if (card != 'S') {
            current.lat =  parse_n(parsed);
          }
          else
          {
            current.lat = -  parse_n(parsed);
          }
          find_term(str, 5);
          card = parsed.charAt(1);
          find_term(str, 4);
          //parse_n(parsed);
          if (card == 'W') {
            //mygps.lon = parsed.toFloat()/100;
            current.lon = parse_n(parsed);
          }
          else
          {
            // mygps.lon = - parsed.toFloat()/100;
            current.lon = - parse_n(parsed);
          }
          find_term(str, 9);
          current.high = parsed.toFloat();
        }


        check_movement();
        if ( (mygps.fixtime.endsWith("0")) and ( mygps.fix == 1)) {
          store_position();
          log_position();
        }
        if (disp_on > 0) {
          refresh();

        }
        sv = 0;
      }
      else if (sent ==  "GPGLL") {
        // print_sat(parsed);
        //refresh();
        // sv=0;
      }
      else {
        // statements
        // Serial.println(str.substring(1,6));

      }




      str = "";
    }
    //Serial.write(ch);
    //termPutchar(ch);
  }
}
