void print_wp_menu() {
  M5.Lcd.fillRect(0, 225, 320, 240, 0xC618);
  M5.Lcd.setTextSize(0);
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(30, 228);
  M5.Lcd.print(menu_a[page]);
  M5.Lcd.setCursor(130, 228);
  M5.Lcd.print(menu_b[page]);
  M5.Lcd.setCursor(230, 228);
  M5.Lcd.print(menu_c[page]);
  M5.Lcd.setTextSize(0);
  M5.Lcd.setFreeFont(FSB9);
  M5.Lcd.setTextColor(WHITE);
}

void print_position() {
  int x = 60;
  int y = 70;

  M5.Lcd.fillRect(50, 70, 220, 100, 0xC618);

  M5.Lcd.setCursor(x + 5, y + 20);
  M5.Lcd.print("Altitude: ");
  M5.Lcd.print(int(current.high));
  M5.Lcd.print("M");
  M5.Lcd.setCursor(x + 5, y + 40);
  M5.Lcd.print("Latitude: ");
  M5.Lcd.print(current.lat, 6);
  M5.Lcd.setCursor(x + 5, y + 60);
  M5.Lcd.print("Longitude: ");
  M5.Lcd.print(current.lon, 6);




}


void rename_wp() {

  int x = 60;
  int y = 70;
  String pre_c, post_c;
  char middle_c;

  pre_c = tmp_name.substring(0, char_position);
  middle_c = tmp_name.charAt(char_position);
  if (middle_c == ' ') {
    middle_c = '_' ;
  };
  post_c = tmp_name.substring(char_position + 1, tmp_name.length());

  M5.Lcd.fillRect(50, 70, 220, 100, 0xC618);


  M5.Lcd.setCursor(x + 5, y + 20);
  M5.Lcd.print("New Name for WP: ");
  M5.Lcd.print(waypoints[wp_pos].id);
  M5.Lcd.setCursor(x + 5, y + 60);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.print(pre_c);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.print(middle_c);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.print(post_c);



}

void delete_wp() {

  int x = 60;
  int y = 70;
  String pre_c, post_c;
  char middle_c;

  pre_c = tmp_name.substring(0, char_position);
  middle_c = tmp_name.charAt(char_position);
  if (middle_c == ' ') {
    middle_c = '_' ;
  };
  post_c = tmp_name.substring(char_position + 1, tmp_name.length());

  M5.Lcd.fillRect(50, 70, 220, 100, 0xC618);


  M5.Lcd.setCursor(x + 5, y + 20);
  M5.Lcd.print("Confirm to delete WP: ");
  M5.Lcd.print(waypoints[wp_pos].id);
  M5.Lcd.setCursor(x + 5, y + 60);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.print(waypoints[wp_pos].name);
  M5.Lcd.setTextColor(WHITE);


}

void list_groups() {

  int x = 60;
  int y = 30;
  int i, initial_i, max_i;
  String pre_c, post_c;
  char middle_c;

  pre_c = tmp_name.substring(0, char_position);
  middle_c = tmp_name.charAt(char_position);
  if (middle_c == ' ') {
    middle_c = '_' ;
  };
  post_c = tmp_name.substring(char_position + 1, tmp_name.length());

  M5.Lcd.fillRect(x, y, 220, 180, 0xC618);

  M5.Lcd.setTextColor(RED);
  M5.Lcd.setCursor(x + 5, y + 20);
  M5.Lcd.print("Select new group for WP: ");
  M5.Lcd.setTextColor(WHITE);
  if (( groups_t > 7 ) && (tmp_group > 4)) {
    initial_i = tmp_group - 3;
  }
  else {
    initial_i = 0;
  }
  if (initial_i + 7 > groups_t ) {
    max_i = groups_t;
  } else {
    max_i = initial_i + 7;
  }
  
  for (i = initial_i; i < max_i ; i++) {
    if ( tmp_group == i) {
      M5.Lcd.setTextColor(GREEN);
    }
    else {
      M5.Lcd.setTextColor(WHITE);
    }

    M5.Lcd.setCursor(x + 5, y + 40 + (i - initial_i ) * 20);
    M5.Lcd.print( groups[i].name );
  }


}
