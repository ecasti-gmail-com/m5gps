# M5GPS

M5GPS is a graphic GPS for hiking.
It's able to guide to stored waypoints, mark points during the track and use them as destination.
It's based to M5Stack Faces Kit using GameBoy keyboard.
## Requirement
### Required libraries:
https://github.com/siara-cc/esp32_arduino_sqlite3_lib
You can install from Arduino IDE as **Sqlite3 Esp32**

### Hardware
M5Stack Faces with Gameboy keyboard
Serial GPS module connected to pin 16 (RX2)
Sd card not bigger than 16GB formatted with vfat.
I'm using a 32GB but it is not officially supported by M5stack

## Installation
Copy the file **/SD/gps_track.db** into the SD card in the root folder
Build and upload the code from the folder **GPS_v0.45**
