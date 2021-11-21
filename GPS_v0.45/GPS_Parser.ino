/* Vars containing GPS infos */




void find_term(String str, int f) {
  int i, tmp_patt = 0;
  parsed = "";
  int max = str.length();

  for (i = 0; i < max; i++) {
    if ((str.charAt(i) == ',') || (str.charAt(i) == '*')) {
      tmp_patt++;
    }
    else if (tmp_patt == f) {

      parsed += str.charAt(i);

    }
    else if (tmp_patt > f) {
      break;

    }
  }
}

float parse_n(String nmea) {
  int a;
  float t, t1;
  String b;
  a = nmea.indexOf('.');
  //Serial.print(a);
  if ( a == 5 ) {
    b = nmea.substring(0, 3);
    t = b.toFloat();
    b = nmea.substring(3);
  } else {
    b = nmea.substring(0, 2);
    t = b.toFloat();
    b = nmea.substring(2);
  }

  t1 = b.toFloat();
  t += (t1 / 60.0);
  return t;
}
