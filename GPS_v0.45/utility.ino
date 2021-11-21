void stop_monitor() {
  M5.Lcd.writecommand(ILI9341_DISPOFF);
  M5.Lcd.setBrightness(0);
}

void start_monitor() {
  M5.Lcd.writecommand(ILI9341_DISPON);
  M5.Lcd.setBrightness(128);
}

void button_top_a() {
  switch (page) {
    case 0: // Gps Stat
      page++;
      break;
    case 1: //track
      bg_page = page;
      page = 5;
      break;
    case 2: // Compass
      bg_page = page;
      page = 5;
      break;
    case 3: // Go Waypoint
      bg_page = page;
      page = 5;
      break;
    case 4: // Waypoints
      tmp_name = waypoints[wp_pos].name;
      page = 6;
      break;
    case 5: //
      page = bg_page;
      bg_page = 0;
      break;
    case 6: //
      rename_wp( waypoints[wp_pos].id, tmp_name);
      read_waypoints();
      page = 4;
      break;
    case 7:
      delete_wp(waypoints[wp_pos].id);
      read_waypoints();
      page = 4;
      break;
    case 8:
      move_wp(waypoints[wp_pos].id , tmp_group);
      menu_x = tmp_group;
      read_waypoints();
      page = 4;
    default:
      break;
  }
}


void button_top_b() {
  switch (page) {
    case 0: // Gps Stat

      break;
    case 1: //track
      c_zoom--;
      if (c_zoom < 0) c_zoom = 0;
      break;
    case 2: // Compass

      break;
    case 3: // Go Waypoint

      break;
    case 4: // Waypoints
      tmp_group = menu_x;
      page = 8;
      break;
    case 5: // ?

      break;
    case 6: //Rename WP
      tmp_name = "Aaaaaaaaaaaaa";
      break;

    default:
      break;
  }
}

void button_top_c() {
  switch (page) {
    case 0: // Gps Stat
      page = 2;
      break;
    case 1: //track
      c_zoom++;
      if (c_zoom > 12) c_zoom = 12;
      break;
    case 2: // Compass
      page = 0;
      break;
    case 3: // Go Waypoint
      page = 0;
      break;
    case 4: // Waypoints
      page = 7;
      break;
    case 5: //Navigate ?

      break;
    case 6: //Rename wp
      page = 4;
      break;
    case 7:
      page = 4;
      break;
    case 8:

      page = 4;
      break;
    default:
      break;
  }
}




void button_select() {
  if ( disp_on == 0) {
    start_monitor();
    disp_on = 1;
  }
  else {
    stop_monitor();
    disp_on = 0;
  }
  switch (page) {
    case 0: // Gps Stat
      break;
    case 1: //track
      break;
    case 2: // Compass
      break;
    case 3: // Go Waypoint
      break;
    case 4: // Waypoints
      break;
    case 5: //Navigate ?
      break;
    default:
      break;
  }
}

void button_start() {
  switch (page) {
    case 0: // Gps Stat
      page = 3;
      break;
    case 1: //track
      page = 3;
      break;
    case 2: // Compass
      page = 3;
      break;
    case 3: // Go Waypoint
      page = 1;
      break;
    case 4: // Waypoints
      page = 3;
      break;
    case 5: //Navigate ?
      break;
    default:
      break;
  }
}

void button_b() {
  switch (page) {
    case 0: // Gps Stat
      page = 4;
      break;
    case 1: //track
      page = 4;
      break;
    case 2: // Compass
      page = 4;
      break;
    case 3: // Go Waypoint
      page = 4;
      break;
    case 4: // Waypoints
      break;
    case 5: //Navigate ?
      break;
    default:
      break;
  }
}

void button_a() {
  switch (page) {
    case 0: // Gps Stat
      // mark_point();
      store_wp(current, 2, 0);
      break;
    case 1: //track
      // mark_point();
      store_wp(current, 2, 0);
      break;
    case 2: // Compass
      //mark_point();
      store_wp(current, 2, 0);
      break;
    case 3: // Go Waypoint
      //mark_point();
      store_wp(current, 2, 0);
      break;
    case 4: // Waypoints
      break;
    case 5: //Navigate ?
      break;
    default:
      break;
  }
}

void button_up() {
  char middle_c;
  switch (page) {
    case 0: // Gps Stat
      break;
    case 1: //track
      display_offset.y += 10;
      break;
    case 2: // Compass
      break;
    case 3: // Go Waypoint
      display_offset.y += 10;
      break;
    case 4: // Waypoints
      *point_select = *point_select - 1;
      if (*point_select < 0) {
        *point_select = 0;
      };
      break;
    case 5: //Navigate ?
      break;
    case 6: // ?
      middle_c = tmp_name.charAt(char_position) + 1;
      if (middle_c > 122) {
        middle_c = 122;
      };
      if (middle_c < 32) {
        middle_c = 32;
      };
      tmp_name.setCharAt(char_position, middle_c);
    case 7:
      break;
    case 8:
      if (tmp_group > 0) tmp_group --;
      break;
    default:
      break;
  }
}

void button_down() {
  char middle_c;
  switch (page) {
    case 0: // Gps Stat
      break;
    case 1: //track
      display_offset.y -= 10;
      break;
    case 2: // Compass
      break;
    case 3: // Go Waypoint
      display_offset.y -= 10;
      break;
    case 4: // Waypoints
      *point_select = *point_select + 1;
      Serial.println(*point_select);
      if (*point_select > *point_max) {
        *point_select = *point_max;
      };
      break;
    case 5: // ?
      break;
    case 6: // ?
      middle_c = tmp_name.charAt(char_position) - 1 ;
      if (middle_c < 32) {
        middle_c = 32;
      };
      tmp_name.setCharAt(char_position, middle_c);
      break;
    case 7:
      break;
    case 8:
      if ( tmp_group < groups_t - 1 ) tmp_group ++;
      break;

    default:
      break;
  }
}

void button_left() {
  switch (page) {
    case 0: // Gps Stat
      break;
    case 1: //track
      display_offset.x += 10;
      break;
    case 2: // Compass
      break;
    case 3: // Go Waypoint
      display_offset.x += 10;
      break;
    case 4: // Waypoints
      menu_x--;

      if (menu_x < 0 ) {
        menu_x = 0;
      };
      Serial.println(menu_x);
      read_waypoints();
      break;
    case 5: // ?
      break;
    case 6: // ?

      char_position --;
      if (char_position < 0 ) {
        char_position = 0;
      };
      break;
    default:
      break;
  }
}

void button_right() {
  switch (page) {
    case 0: // Gps Stat
      break;
    case 1: //track
      display_offset.x -= 10;
      break;
    case 2: // Compass
      break;
    case 3: // Go Waypoint
      display_offset.x -= 10;
      break;
    case 4: // Waypoints
      menu_x++;

      if (menu_x >= groups_t  ) {
        menu_x = groups_t - 1;
      };
      Serial.println(menu_x);
      read_waypoints();
      break;
    case 5: //Navigate ?
      break;
    case 6: // ?
      char_position ++;
      if (char_position < 0 ) {
        char_position = 0;
      };
      break;
    default:
      break;
  }
}


void get_data() {

  while (digitalRead(KEYBOARD_INT) == LOW) {
    Wire.requestFrom(KEYBOARD_I2C_ADDR, 1);  // request 1 byte from keyboard
    while (Wire.available()) {
      //  Serial.print((char)key_val);
      uint8_t key_val = Wire.read();                  // receive a byte as character
      //Serial.print(key_val);
      switch (key_val) {
        case 0xFE:
          button_up();
          break;
        case 0xFD:
          button_down();
          break;
        case 0xFB:
          button_left();
          break;
        case 0xF7:
          button_right();
          break;
        case 0xBF:
          button_select();
          break;
        case 0x7F:
          button_start();
          break;
        case 0xEF:
          button_a();
          break;
        case 0xDF:
          button_b();
          break;
        default:

          break;
      }
    }
  }
}
















/*

  if (key_val >= 0x20 ) {
  if (key_val == 0x7F ) { // ASCII String
    start_monitor();
    disp_on = 1;
  }
  else if (key_val == 0xBF ) {
    stop_monitor();
    disp_on = 0;
  }
  else if (key_val == 0xFB  ) {
    if (page < 4) {
      display_offset.x += 10;
    }
    else {

    }
  }
  else if (key_val == 0xF7 ) {
    display_offset.x -= 10;
  }
  else if (key_val ==  0xFE ) {
    display_offset.y += 10;
  }
  else if (key_val ==  0xFD) {
    display_offset.y -= 10;
  }
  // Button B
  else if (key_val ==  0xDF) {
    page = 4;
  }
  // Button A
  else if (key_val ==  0xEF) {
    mark_point();
  }
  // Button Start
  else if (key_val ==  0x7F) {
    page = 3;
  }
  }
  }
  }
  }
*/
/*
  void mark_point() {
  char tmp[20];
  marked[mark_t].lat = current.lat;
  marked[mark_t].lon = current.lon;
  marked[mark_t].high = current.high;
  marked[mark_t].type = 2;
  if (mark_t == 0 ) {
    sprintf(tmp, "Initial_point");
  }
  else {
    sprintf(tmp, "Mark_%d", mark_t);
  }
  marked[mark_t].name = tmp;
  mark_t++;
  Serial.println(mark_t);
  }
*/
offset_m calc_movement(points p2, points p1) {
  float dist, x, y, radius, circ;
  offset_m result;
  // Calculate radius from the axis of the earth to the current latitude
  radius = (6378.0 * cos( p1.lat / 57.2958));
  circ = 2 * radius * 3.1415926535;
  result.y = 1000.0 * ((p1.lat - p2.lat) * 40007 ) / 360.0;
  result.x = 1000.0 * ((p1.lon - p2.lon) * circ  ) / 360.0;
  result.dist = sqrt((result.x * result.x) + (result.y * result.y));
  if (result.dist < 10) {
    result.azimuth = 0;
  }
  else {
    result.azimuth = int(atan2(result.x, -result.y) * 57.2958);
  }
  return result;
}

/*
  float check_move(){
  float dist,x,y,radius,circ;
  radius = (6378.0 * cos( current.lat/57.2958));
  circ = 2 * radius * 3.1415926535;
  y = 1000.0 * ((current.lat - track[track_pos].lat) * 40007 ) /360.0;
  x = 1000.0 * ((current.lon - track[track_pos].lon) * circ  ) /360.0;
  dist=sqrt((x*x)+(y*y));
  return dist;
  }
*/

void check_movement() {
  int l = mygps.fixtime.length() - 1;
  int i = mygps.fixtime[l] - '0';
  //offset_m tmp;
  movement = calc_movement(current, lasts[i]);
  lasts[i] = current;
  //Serial.println(i);

}
void   set_current_point() {
  waypoints[wp_t].lat = current.lat;
  waypoints[wp_t].lon = current.lon;
  waypoints[wp_t].name = "Temp";
  wp_t++;
}
