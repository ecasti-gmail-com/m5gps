/*
   types:
   0 = Home
   1 = Food ( restaurant / cafe )
   2 = Point Of Interest
   3 = Transport ( Port/Airport/Train)
   4 = Hotel
   5 = Work
   6 = Shopping

*/
/*

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
  0x9f, 0x80, 0xdf, 0x40, 0x8e, 0xc0, 0xe5, 0xc0, 0xf3, 0xc0, 0xe1, 0xc0, 0xc4, 0xc0, 0x8e, 0x00, 
  0x1e, 0x80, 0x3f, 0xc0
};

// 'shoopping', 10x10px
const unsigned char epd_bitmap_shoopping [] PROGMEM = {
  0xff, 0xc0, 0x7f, 0xc0, 0x87, 0xc0, 0xb8, 0x00, 0xbf, 0x80, 0xbf, 0x80, 0x80, 0x40, 0xdf, 0xc0, 
  0xc0, 0x40, 0xee, 0xc0
};

const unsigned char* symbols_bitmap[] = {
  epd_bitmap_home,
  epd_bitmap_food,
  epd_bitmap_poi,
  epd_bitmap_transport,
  epd_bitmap_hotel,
  epd_bitmap_office,
  epd_bitmap_shoopping
  
};
*/