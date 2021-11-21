/*
   types:
   0 = Home
   1 = Food ( restaurant / cafe )
   2 = Point Of Interest
   3 = Transport ( Port/Airport/Train)
   4 = Hotel
   5 = Work
   6 = Shopping
   Images Generated on https://xbm.jazzychad.net/
*/


// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 96)
const int epd_bitmap_allArray_LEN = 2;

// Food, 10x10px
const unsigned char epd_bitmap_food [] PROGMEM = {
  0x24, 0x00, 0x48, 0x00, 0xfe, 0x00, 0x82, 0x03, 0x82, 0x02, 0x82, 0x03,
  0x44, 0x00, 0x38, 0x00, 0x83, 0x01, 0xfe, 0x00
};
// Home, 10x10px
const unsigned char epd_bitmap_home [] PROGMEM = {
  0x30, 0x00, 0x78, 0x00, 0xcc, 0x00, 0x86, 0x01, 0x02, 0x01, 0x02, 0x01,
  0x5a, 0x01, 0x5a, 0x01, 0x1a, 0x01, 0xfe, 0x01
};

// 'Point Of Interest, 10x10px
const unsigned char epd_bitmap_hotel [] PROGMEM = {
  0x89, 0x00, 0xc9, 0x01, 0xef, 0x03, 0x29, 0x02, 0xa9, 0x02, 0x20, 0x02,
  0xa0, 0x02, 0x20, 0x02, 0xa0, 0x02, 0xe0, 0x03
};
// 'Transport', 10x10px
const unsigned char epd_bitmap_transport [] PROGMEM = {
  0x30, 0x00, 0xfc, 0x00, 0x84, 0x00, 0xfe, 0x01, 0x32, 0x01, 0x86, 0x01,
  0x84, 0x00, 0xcc, 0x00, 0x78, 0x00, 0x30, 0x00
};
// 'Hotel, 10x10px
const unsigned char epd_bitmap_poi [] PROGMEM = {
  0x78, 0x00, 0x84, 0x00, 0x32, 0x01, 0x4a, 0x01, 0x32, 0x01, 0x84, 0x00,
  0x48, 0x00, 0x48, 0x00, 0x30, 0x00, 0x30, 0x00
};

// 'Office', 10x10px
const unsigned char epd_bitmap_office [] PROGMEM = {
  0xc6, 0xfd, 0xc4, 0xff, 0x8e, 0xff, 0xd8, 0xfe, 0x70, 0xfc, 0x30, 0xfc,
  0x78, 0xfc, 0xcc, 0xfd, 0x86, 0xfc, 0x83, 0xfd
};

// 'shoopping', 10x10px
const unsigned char epd_bitmap_shopping [] PROGMEM = {
  0x01, 0xfc, 0xfe, 0xfd, 0x02, 0xfe, 0x02, 0xfe, 0x02, 0xfe, 0xfe, 0xfd,
  0x01, 0xfc, 0x01, 0xfc, 0xfe, 0xfd, 0x84, 0xfc
};

// 'Petrol Pump', 10x10px
const unsigned char epd_bitmap_petrol [] PROGMEM = {
  0x00, 0xfc, 0x38, 0xff, 0x44, 0xfd, 0x44, 0xfd, 0xd4, 0xfd, 0x54, 0xfd,
  0x54, 0xfd, 0x44, 0xfd, 0x44, 0xfc, 0xfe, 0xfc
};

// 'Traffic Signal', 10x10px
const unsigned char epd_bitmap_traffic_signal [] PROGMEM = {
  0xfc, 0xfc, 0x87, 0xff, 0xb6, 0xfd, 0xb4, 0xfc, 0x87, 0xff, 0xb6, 0xfd,
  0xb4, 0xfc, 0x84, 0xfc, 0xb6, 0xfd, 0xfc, 0xfc
};


const unsigned char* symbols_bitmap[] = {
  epd_bitmap_home,
  epd_bitmap_food,
  epd_bitmap_poi,
  epd_bitmap_transport,
  epd_bitmap_hotel,
  epd_bitmap_office,
  epd_bitmap_shopping,
  epd_bitmap_petrol,
  epd_bitmap_traffic_signal

};


const char* wp_type[] = { "Home", "Food", "POI", "Transport", "Hotel", "Office", "Shopping", "Petrol Pump", "Traffic Signal", "School" };
const char* points_page[] = { "Marked Points", "Waypoints"};
const char* menu_a[] = { "Display", "Position Info", "Position Info", "Position Info", "Rename WP", "-", "Confirm", "Confirm", "Confirm" };
const char* menu_b[] = { "-", "Zoom in", "-", "-", "Move WP", "-", "Delete", "-" , "-" };
const char* menu_c[] = { "Compass", "Zoom out", "Sat info", "Sat Info", "Delete WP", "-", "Cancel", "Cancel", "Cancel" };


void print_sat_info(int x, int y) {
  M5.Lcd.fillRect(220, 131, 100, 95, BLACK);
  M5.Lcd.drawLine(220, 130, 220, 180, RED);
  M5.Lcd.drawLine(220, 180, 320, 180, RED);
  M5.Lcd.setCursor(x + 5, y + 20);
  M5.Lcd.print("Sat: ");
  M5.Lcd.print(mygps.nsat);
  M5.Lcd.setCursor(x + 5, y + 40);
  M5.Lcd.print("Fixed: ");
  M5.Lcd.print(mygps.nsat_t);
}

void print_pos_info(int x, int y) {
  // x = 220
  // y = 130
  M5.Lcd.fillRect(x, y + 2, 100, 110, BLACK);
  M5.Lcd.drawLine(x, y + 1, x + 100, y + 1, RED);
  M5.Lcd.drawLine(x, y + 1, x, y + 110, RED);
  M5.Lcd.drawLine(x - 1, y + 1, x - 1, y + 110, RED);
  M5.Lcd.drawLine(x, y + 45, x + 100, y + 45, RED);
  M5.Lcd.drawLine(x, y + 46, x + 100, y + 46, RED);

  M5.Lcd.setCursor(x + 5, y + 65);
  M5.Lcd.print("Alt: ");
  M5.Lcd.print(int(current.high));
  M5.Lcd.print("M");
  M5.Lcd.setCursor(x + 5, y + 85);
  M5.Lcd.print("Lat: ");
  M5.Lcd.print(current.lat);
  M5.Lcd.setCursor(x + 5, y + 105);
  M5.Lcd.print("Lon: ");
  M5.Lcd.print(current.lon);


}


void print_time() {
  M5.Lcd.setCursor(20, 210);
  M5.Lcd.print(mygps.rawdate);
}

int getBatteryLevel() {
  Wire.beginTransmission(0x75);
  Wire.write(0x78);
  if (Wire.endTransmission(false) == 0 && Wire.requestFrom(0x75, 1)) {
    switch (Wire.read() & 0xF0) {
      case 0xE0: return 25;
      case 0xC0: return 50;
      case 0x80: return 75;
      case 0x00: return 100;
      default: return 0;
    }
  }
  return -1;
}

void print_top_bar() {
  int level = getBatteryLevel();
  // M5.Lcd.fillRect(220,0, level ,15,GREEN);
  M5.Lcd.fillRect(222, 0, 100, 20, BLACK);
  M5.Lcd.progressBar(270, 4, 43, 12, level);
  M5.Lcd.fillRect(313, 7, 3 , 6, 0x09F1);
  if ( mygps.fix == 1 ) {
    M5.Lcd.drawCircle(230, 10, 2, GREEN);
    M5.Lcd.drawLine(226, 6, 234, 14, GREEN);
    M5.Lcd.drawLine(224, 8, 228, 4, GREEN);
    M5.Lcd.drawLine(232, 16, 236, 12, GREEN);
  }
  else {
    M5.Lcd.drawCircle(230, 10, 2, RED);
    M5.Lcd.drawLine(226, 6, 234, 14, RED);
    M5.Lcd.drawLine(224, 8, 228, 4, RED);
    M5.Lcd.drawLine(232, 16, 236, 12, RED);
  }
  // Dynamic compass
  if ( movement.dist < 10) {
    M5.Lcd.drawCircle(250, 10, 8, RED);
    M5.Lcd.fillTriangle(242, 10, 254, 6, 250, 18, RED);
    M5.Lcd.fillTriangle(243, 11, 249, 11, 249, 17, BLACK);
  } else
  {
    M5.Lcd.drawCircle(250, 10, 8, GREEN);
    M5.Lcd.fillTriangle(242, 10, 254, 6, 250, 18, GREEN);
    M5.Lcd.fillTriangle(243, 11, 249, 11, 249, 17, BLACK);
  }
}


/*
   Draw compass heading to moving direction
*/
void print_compass() {
  float dx, dy;
  int x1, x2, x3, x4, y1, y2, y3, y4;
  int xh1, yh1, xh2, yh2, xh3, yh3, xh4, yh4;
  int north;
  north = - movement.azimuth;
  M5.Lcd.fillRect(0, 0, 219, 225, BLACK);
  M5.Lcd.fillCircle(100, 100, 90, WHITE);
  // M5.Lcd.drawLine(10,10,190,190,BLACK);
  //  M5.Lcd.drawLine(10,190,190,10,BLACK);
  M5.Lcd.drawCircle(100, 100, 91, BLACK);
  M5.Lcd.drawCircle(100, 100, 80, BLACK);
  M5.Lcd.drawCircle(100, 100, 79, BLACK);
  M5.Lcd.drawCircle(100, 100, 51, RED);

  dx = float(90) * sin(float(north / 57.2958));
  dy =  float(90) * cos(float(north / 57.2958));
  // Calculate only one point, generating remaining by difference
  x1 = 100 + dx / 9;
  y1 = 100 - dy / 9;
  x2 = 100 - dy / 9;
  y2 = 100 - dx / 9;
  x3 = 100 - dx / 9;
  y3 = 100 + dy / 9;
  x4 = 100 + dy / 9;
  y4 = 100 + dx / 9;

  xh1 = 100 + dx;
  yh1 = 100 - dy;
  xh2 = 100 - dy;
  yh2 = 100 - dx;
  xh3 = 100 - dx;
  yh3 = 100 + dy;
  xh4 = 100 + dy;
  yh4 = 100 + dx;

  M5.Lcd.drawLine(100, 100, xh1, yh1, GREEN);
  M5.Lcd.fillTriangle(x1, y1, x3, y3, xh2, yh2, 0xB5B6);
  M5.Lcd.fillTriangle(x4, y4, x2, y2, xh3, yh3, 0xB5B6);
  M5.Lcd.fillTriangle(x1, y1, x3, y3, xh4, yh4, 0xB5B6);
  M5.Lcd.fillTriangle(x4, y4, x2, y2, xh1, yh1, RED);
  M5.Lcd.fillCircle(100, 100, 10, BLACK);

}

void print_compass_mini() {
  float dx, dy;
  int x = 270;
  int y = 115;
  int size = 45;
  int x1, x2, x3, x4, y1, y2, y3, y4;
  int xh1, yh1, xh2, yh2, xh3, yh3, xh4, yh4;
  int north;
  north = - movement.azimuth;
  M5.Lcd.fillRect(x - 49, y - 49, 100, 100 , BLACK);
  M5.Lcd.fillCircle(x, y, size, WHITE);

  M5.Lcd.drawCircle(x, y, int(size * 0.9), BLACK);
  M5.Lcd.drawCircle(x, y, int(size * 0.5), BLACK);


  dx = float(size) * sin(float(north / 57.2958));
  dy =  float(size) * cos(float(north / 57.2958));
  // Calculate only one point, generating remaining by difference
  x1 = x + dx / 9;
  y1 = y - dy / 9;
  x2 = x - dy / 9;
  y2 = y - dx / 9;
  x3 = x - dx / 9;
  y3 = y + dy / 9;
  x4 = x + dy / 9;
  y4 = y + dx / 9;

  xh1 = x + dx;
  yh1 = y - dy;
  xh2 = x - dy;
  yh2 = y - dx;
  xh3 = x - dx;
  yh3 = y + dy;
  xh4 = x + dy;
  yh4 = y + dx;

  M5.Lcd.drawLine(x, y, xh1, yh1, GREEN);
  M5.Lcd.fillTriangle(x1, y1, x3, y3, xh2, yh2, 0xB5B6);
  M5.Lcd.fillTriangle(x4, y4, x2, y2, xh3, yh3, 0xB5B6);
  M5.Lcd.fillTriangle(x1, y1, x3, y3, xh4, yh4, 0xB5B6);
  M5.Lcd.fillTriangle(x4, y4, x2, y2, xh1, yh1, RED);
  M5.Lcd.fillCircle(x, y, 2, BLACK);

}



/*
   Draw the direction of the waypoint, heading the direction of moving
*/
void print_go_wp() {
  offset_m off;
  String tmp;
  off = calc_movement(waypoints[wp_pos], current );
  tmp = waypoints[wp_pos].name;



  int x, y, x1, y1, x2, y2, dx, dy;
  int to_azimut = off.azimuth - movement.azimuth;
  M5.Lcd.fillRect(0, 0, 219, 225, BLACK);
  M5.Lcd.fillCircle(100, 100, 90, WHITE);
  M5.Lcd.drawLine(10, 10, 190, 190, BLACK);
  M5.Lcd.drawLine(10, 190, 190, 10, BLACK);
  M5.Lcd.drawLine(100, 10, 100, 190, BLACK);
  M5.Lcd.drawLine(10, 100, 190, 100, BLACK);
  M5.Lcd.drawCircle(100, 100, 91, BLACK);
  M5.Lcd.drawCircle(100, 100, 80, BLACK);
  M5.Lcd.drawCircle(100, 100, 79, BLACK);
  M5.Lcd.drawCircle(100, 100, 51, RED);

  dx = int(float(90) * sin(float(-movement.azimuth / 57.2958)));
  dy = int(float(90) * cos(float(-movement.azimuth / 57.2958)));
  x = 100 + dx;
  y = 100 - dy;
  x1 = 100 + dy / 9;
  y1 = 100 + dx / 9;
  x2 = 100 - dy / 9;
  y2 = 100 - dx / 9;
  M5.Lcd.fillTriangle(x, y, x1, y1, x2, y2, RED);
  x = 100 - dx;
  y = 100 + dy;
  M5.Lcd.fillTriangle(x, y, x1, y1, x2, y2, 0xB5B6);

  dx = int(float(90) * sin(float(to_azimut / 57.2958)));
  dy = int(float(90) * cos(float(to_azimut / 57.2958)));
  x = 100 + dx;
  y = 100 - dy;
  x1 = 100 + dy / 9;
  y1 = 100 + dx / 9;
  x2 = 100 - dy / 9;
  y2 = 100 - dx / 9;
  M5.Lcd.fillTriangle(x, y, x1, y1, x2, y2, GREEN);
  M5.Lcd.drawLine(100, 100, x, y, RED);
  M5.Lcd.fillCircle(100, 100, 10, BLACK);


  M5.Lcd.drawLine(0, 200, 220, 200, RED);
  M5.Lcd.drawLine(0, 201, 220, 201, RED);
  // Distance of WP
  M5.Lcd.fillRect(221, 71, 99, 39, BLACK);
  M5.Lcd.drawLine(220, 70, 220, 130, RED);
  M5.Lcd.drawLine(219, 70, 219, 130, RED);
  M5.Lcd.drawLine(220, 130, 320, 130, RED);
  M5.Lcd.setCursor(230, 85);
  if (off.dist < 5000) {
    M5.Lcd.print(off.dist);
    M5.Lcd.print(" M");
  } else if (off.dist < 100000)
  {
    M5.Lcd.print(off.dist / 1000);
    M5.Lcd.print(" Km");

  } else {
    M5.Lcd.print(int(off.dist / 1000));
    M5.Lcd.print(" Km");
  }
  M5.Lcd.setCursor(230, 105);
  M5.Lcd.print("Dir: ");
  M5.Lcd.print(off.azimuth);
  M5.Lcd.print("'");
  M5.Lcd.setCursor(5, 215);
  M5.Lcd.print(tmp);
}

void print_odometer() {
  M5.Lcd.fillRect(220, 20, 100, 45, BLACK);
  M5.Lcd.drawLine(220, 20, 320, 20, RED);
  M5.Lcd.drawLine(220, 20, 220, 64, RED);
  M5.Lcd.drawLine(219, 21, 219, 65, RED);
  M5.Lcd.drawLine(220, 65, 320, 65, RED);
  M5.Lcd.setCursor(230, 37);
  M5.Lcd.print("Trip: ");
  M5.Lcd.setCursor(230, 57);
  if (distance < 5000) {
    M5.Lcd.print(distance);
    M5.Lcd.print(" M");
  } else if (distance < 100000)
  {
    M5.Lcd.print(distance / 1000);
    M5.Lcd.print(" Km");

  } else {
    M5.Lcd.print(int(distance / 1000));
    M5.Lcd.print(" Km");
  }
  /*
    M5.Lcd.setCursor(230, 80);
    M5.Lcd.print("Direction: ");
    M5.Lcd.setCursor(230, 100);
    M5.Lcd.print(movement.azimuth);
    M5.Lcd.print("'");
  */
}


void sat_circle() {
  int i, x, y;
  M5.Lcd.fillRect(0, 0, 219, 240, BLACK);
  M5.Lcd.setTextSize(0);
  M5.Lcd.setTextFont(0);
  M5.Lcd.drawCircle(100, 100, 90, RED);
  M5.Lcd.drawCircle(100, 100, 91, RED);
  M5.Lcd.drawCircle(100, 100, 92, RED);
  M5.Lcd.drawCircle(100, 100, 2, RED);
  for (i = 1; i <= mygps.nsat ; i++) {
    x = 100 + int(float(mysat[i].elevation) * cos(float(mysat[i].azimuth / 57.2958)));
    y = 100 + int(float(mysat[i].elevation) * sin(float(mysat[i].azimuth / 57.2958)));
    M5.Lcd.drawRect(x - 8, y - 8 , 16, 16, BLUE);
    M5.Lcd.setCursor(x - 6, y - 4);
    M5.Lcd.print(mysat[i].sat_n);
  }
  M5.Lcd.setTextSize(0);
  M5.Lcd.setFreeFont(FSB9);
}




void draw_grid() {
  int i;
  M5.Lcd.fillRect(0, 0, 219, 225, WHITE);
  for ( i = 10; i < 220; i += 25) {
    M5.Lcd.drawLine(i, 0, i, 225, BLACK);
  }
  for ( i = 20; i < 225; i += 25) {
    M5.Lcd.drawLine(0, i, 220, i, BLACK);
  }
  M5.Lcd.drawLine(0, 119, 220, 119, BLACK);
  M5.Lcd.drawLine(109, 0, 109, 225, BLACK);
}

void draw_grid_mini() {
  int i;
  int xs = 220;
  int ys = 130;
  M5.Lcd.fillRect(xs + 1, ys + 1 , 100, 95, WHITE);
  for ( i = xs; i < 320; i += 25) {
    M5.Lcd.drawLine(i, ys, i, ys + 95, BLACK);
  }
  for ( i = ys ; i < ys + 95; i += 25) {
    M5.Lcd.drawLine(xs, i, 320, i, BLACK);
  }
  M5.Lcd.drawLine(xs, ys + 49, 320,  ys + 49, BLACK);
  M5.Lcd.drawLine(xs + 49, xs + 49, 269, 225, BLACK);
}

void sat_stats() {
  M5.Lcd.fillRect(220, 20, 100, 130, BLACK);
  /*  M5.Lcd.drawLine(0,205,219,205,RED);
    M5.Lcd.drawLine(0,204,219,204,RED);*/
  M5.Lcd.drawLine(220, 20, 220, 130, RED);
  M5.Lcd.drawLine(219, 20, 219, 130, RED);
  M5.Lcd.drawLine(220, 130, 320, 130, RED);
  M5.Lcd.drawLine(220, 20, 320, 20, RED);
  M5.Lcd.drawLine(220, 21, 320, 21, RED);

  M5.Lcd.drawRect(225, 25, 10, 40, GREEN);
  M5.Lcd.fillRect(225, 65 - int(mysat[1].snr / 2.5) , 10 , int(mysat[1].snr / 2.5) , GREEN);
  M5.Lcd.drawRect(240, 25, 10, 40, GREEN);
  M5.Lcd.fillRect(240, 65 - int(mysat[2].snr / 2.5) , 10 , int(mysat[2].snr / 2.5) , GREEN);
  M5.Lcd.drawRect(255, 25, 10, 40, GREEN);
  M5.Lcd.fillRect(255, 65 - int(mysat[3].snr / 2.5) , 10 , int(mysat[3].snr / 2.5) , GREEN);
  M5.Lcd.drawRect(270, 25, 10, 40, GREEN);
  M5.Lcd.fillRect(270, 65 - int(mysat[4].snr / 2.5) , 10 , int(mysat[4].snr / 2.5) , GREEN);
  M5.Lcd.drawRect(285, 25, 10, 40, GREEN);
  M5.Lcd.fillRect(285, 65 - int(mysat[5].snr / 2.5) , 10 , int(mysat[5].snr / 2.5) , GREEN);
  M5.Lcd.drawRect(300, 25, 10, 40, GREEN);
  M5.Lcd.fillRect(300, 65 - int(mysat[6].snr / 2.5) , 10 , int(mysat[6].snr / 2.5) , GREEN);
  M5.Lcd.drawRect(225, 85, 10, 40, GREEN);
  M5.Lcd.fillRect(225, 125 - int(mysat[7].snr / 2.5) , 10 , int(mysat[7].snr / 2.5) , GREEN);
  M5.Lcd.drawRect(240, 85, 10, 40, GREEN);
  M5.Lcd.fillRect(255, 125 - int(mysat[8].snr / 2.5) , 10 , int(mysat[8].snr / 2.5) , GREEN);
  M5.Lcd.drawRect(255, 85, 10, 40, GREEN);
  M5.Lcd.fillRect(255, 125 - int(mysat[9].snr / 2.5) , 10 , int(mysat[9].snr / 2.5) , GREEN);
  M5.Lcd.drawRect(270, 85, 10, 40, GREEN);
  M5.Lcd.fillRect(270, 125 - int(mysat[10].snr / 2.5) , 10 , int(mysat[10].snr / 2.5) , GREEN);
  M5.Lcd.drawRect(285, 85, 10, 40, GREEN);
  M5.Lcd.fillRect(285, 125 - int(mysat[11].snr / 2.5) , 10 , int(mysat[11].snr / 2.5) , GREEN);
  M5.Lcd.drawRect(300, 85, 10, 40, GREEN);
  M5.Lcd.fillRect(300, 125 - int(mysat[12].snr / 2.5) , 10 , int(mysat[12].snr / 2.5) , GREEN);

}
void list_points() {
  int i, j, i_initial, i_max;
  struct points *tmp_point;

  offset_m off;
  M5.Lcd.fillRect(0, 0, 320, 240, BLACK);
  M5.Lcd.drawLine(0, 30, 320, 30, RED);
  M5.Lcd.drawLine(220, 0, 220, 240, RED);
  M5.Lcd.setCursor(10, 18);
  M5.Lcd.setTextColor(GREEN);
  M5.Lcd.print(groups[menu_x].name);
  M5.Lcd.setCursor(225, 18);
  M5.Lcd.print("Details");
  //M5.Lcd.setCursor(40,i*20+50);
  tmp_point = waypoints;
  point_select = &wp_pos;
  point_max = &wp_t;

  off = calc_movement(tmp_point[*point_select], current );
  i_initial = 0;
  i_max = *point_max;
  if ((*point_max > 10) && (*point_select > 5))  {
    i_initial = *point_select - 5;
    i_max = *point_select + 5;
    if ( i_max > *point_max ) {
      i_max = *point_max;
    };

  }
  for (i = i_initial; i < i_max; i++) {
    j = tmp_point[i].type;

    if (i == *point_select) {
      M5.Lcd.setTextColor(GREEN);
      M5.Lcd.drawXBitmap(10,  (i - i_initial) * 18 + 40 , symbols_bitmap[j], 10, 10, GREEN, BLACK);
    }
    else {
      M5.Lcd.setTextColor(WHITE);
      M5.Lcd.drawXBitmap(10,  (i - i_initial)  * 18 + 40 , symbols_bitmap[j], 10, 10, ORANGE, BLACK);
    }

    M5.Lcd.setCursor(30, (i - i_initial)  * 18 + 50);
    M5.Lcd.print(tmp_point[i].name);
  }
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(225, 48);
  M5.Lcd.print("Latitude:");
  M5.Lcd.setCursor(225, 66);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.print(tmp_point[*point_select].lat, 6);
  M5.Lcd.setCursor(225, 85);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.print("Longitude:");
  M5.Lcd.setCursor(225, 103);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.print(tmp_point[*point_select].lon, 6);
  M5.Lcd.setCursor(225, 122);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.print("Altitude:");
  M5.Lcd.setCursor(225, 140);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.print(tmp_point[*point_select].high, 0);
  M5.Lcd.print(" M");
  M5.Lcd.setCursor(225, 159);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.print("Type:");
  M5.Lcd.setCursor(225, 177);
  M5.Lcd.setTextColor(RED);
  j = tmp_point[*point_select].type;
  M5.Lcd.print(wp_type[j]);


  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(225, 196);
  M5.Lcd.print("Distance:");
  M5.Lcd.setCursor(225, 214);
  M5.Lcd.setTextColor(RED);
  if (off.dist < 5000) {
    M5.Lcd.print(off.dist);
    M5.Lcd.print(" M");
  } else if (off.dist < 100000)
  {
    M5.Lcd.print(off.dist / 1000);
    M5.Lcd.print(" Km");

  } else {
    M5.Lcd.print(int(off.dist / 1000));
    M5.Lcd.print(" Km");
  }
  M5.Lcd.setTextColor(WHITE);
}

void print_wp() {

  int x, y, i, j, old_x, old_y;
  offset_m off;
  for ( i = 0; i < wp_t ; i++) {
    off = calc_movement(waypoints[i], current );
    x = 110 + int((off.x / zoom[c_zoom])) + display_offset.x;
    y = 120 + int((off.y / zoom[c_zoom])) + display_offset.y;
    if ((x >= 0) && (x <= 220) && (y >= 0) && (y <= 240)) {
      if ( i == wp_pos) {
        j = waypoints[i].type;
        M5.Lcd.drawXBitmap(x,  y , symbols_bitmap[j], 10, 10, GREEN, BLACK);
        // M5.Lcd.fillCircle(x, y , 7, RED);

      }
      else
      {
        j = waypoints[i].type;
        M5.Lcd.drawXBitmap(x,  y , symbols_bitmap[j], 10, 10, ORANGE, BLACK);

      }
    }
  }

}

void print_wp_single() {
  offset_m off;
  int x, y, i, j;
  off = calc_movement(waypoints[wp_pos], current );
  x = 110 + int((off.x / zoom[c_zoom])) + display_offset.x;
  y = 120 + int((off.y / zoom[c_zoom])) + display_offset.y;
  if ((x >= 0) && (x <= 220) && (y >= 0) && (y <= 240)) {
    j = waypoints[wp_pos].type;
    M5.Lcd.drawXBitmap(x,  y , symbols_bitmap[j], 10, 10, GREEN, BLACK);
  }
}



void print_wp_mini() {

  int x, y, i, j, old_x, old_y;
  int xs = 220;
  int ys = 130;
  offset_m off;
  for ( i = 0; i < wp_t ; i++) {
    off = calc_movement(waypoints[i], current );
    x = xs + 50 + int(off.x / (zoom[c_zoom] * 3) ) + display_offset.x;
    y = ys + 50 + int(off.y / (zoom[c_zoom] * 3) ) + display_offset.y;
    if ((x >= xs) && (x <= 320) && (y >= ys) && (y <= 225)) {
      if ( i == wp_pos) {
        j = waypoints[i].type;
        M5.Lcd.drawXBitmap(x,  y , symbols_bitmap[j], 10, 10, GREEN, BLACK);

      }
      else
      {
        j = waypoints[i].type;
        M5.Lcd.drawXBitmap(x,  y , symbols_bitmap[j], 10, 10, ORANGE, BLACK);
      }
    }
  }
}


/* Draw the grip and stored points */
void print_track() {
  int x, y, i, old_x, old_y;
  offset_m off;
  draw_grid();
  off = calc_movement(current,  track[track_pos]);
  x = int((off.x / zoom[c_zoom])) + display_offset.x;
  y = int((off.y / zoom[c_zoom])) + display_offset.y;
  M5.Lcd.fillCircle(110 + x, 120 + y , 4, RED);
  for ( i = 0; i <= track_pos ; i++) {
    off = calc_movement(track[i],  track[track_pos]);
    x = 110 + int((off.x / zoom[c_zoom])) + display_offset.x;
    y = 120 + int((off.y / zoom[c_zoom])) + display_offset.y;
    if ((x >= 0) && (x <= 220) && (y >= 0) && (y <= 240)) {
      M5.Lcd.fillCircle(x, y , 5, BLUE);
      if (i > 0) {
        M5.Lcd.drawLine(x, y, old_x, old_y, GREEN);
      }
    }
    old_x = x;
    old_y = y;

  }
}

/* Draw the grip and stored points */
void print_track_mini() {
  int x, y, i, old_x, old_y;
  int xs = 220;
  int ys = 130;
  offset_m off;
  //draw_grid();
  draw_grid_mini();
  off = calc_movement(current,  track[track_pos]);
  x = int(off.x / (zoom[c_zoom] * 3)) + display_offset.x;
  y = int(off.y / (zoom[c_zoom] * 3)) + display_offset.y;
  M5.Lcd.fillCircle(xs + 50 + x, ys + 50 + y , 2, RED);
  for ( i = 0; i <= track_pos ; i++) {
    off = calc_movement(track[i],  track[track_pos]);
    x = xs +  50 + int(off.x / (zoom[c_zoom] * 3)) + display_offset.x;
    y = ys + 50 + int(off.y / (zoom[c_zoom] * 3)) + display_offset.y;
    if ((x >= xs) && (x <= 320) && (y >= ys) && (y <= 225)) {
      M5.Lcd.fillCircle(x, y , 3, BLUE);
      if (i > 0) {
        M5.Lcd.drawLine(x, y, old_x, old_y, GREEN);
      }
    }
    old_x = x;
    old_y = y;

  }
}

void print_speed() {
  int speed;
  speed = int(movement.dist * 0.36);
  M5.Lcd.fillRect(220, 111, 320, 129, BLACK);
  M5.Lcd.setCursor(225, 125);
  M5.Lcd.print(speed);
  M5.Lcd.print(" Km/h");

}
void print_zoom() {
  int x = 220;
  int y = 205;
  M5.Lcd.fillRect(x, y + 1, 320, 19, BLACK);
  M5.Lcd.setCursor(x + 5, y + 15);
  M5.Lcd.print("Zoom: ");
  M5.Lcd.print(c_zoom);

}

void print_to_wp(float dist) {
  M5.Lcd.fillRect(220, 111, 320, 129, TFT_LIGHTGREY);
  M5.Lcd.setCursor(225, 125);
  M5.Lcd.print("WP: ");
  M5.Lcd.print(dist);

}


void print_menu() {
  M5.Lcd.fillRect(0, 225, 320, 240, 0xC618);
  M5.Lcd.setTextSize(0);
  M5.Lcd.setTextFont(2);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(27, 223);
  M5.Lcd.print(menu_a[page]);
  M5.Lcd.setCursor(130, 223);
  M5.Lcd.print(menu_b[page]);
  M5.Lcd.setCursor(230, 223);
  M5.Lcd.print(menu_c[page]);
  M5.Lcd.setTextSize(0);
  M5.Lcd.setFreeFont(FSB9);
  M5.Lcd.setTextColor(WHITE);
}
