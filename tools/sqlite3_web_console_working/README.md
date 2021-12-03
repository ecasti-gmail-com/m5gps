# M5GPS Web Console
This console works as a separated software to deploy on the M5stack when is required to manipulate or analize the data collected on the SD card.
Maybe in the future it will be integrated to the main software.

# Installation
Edit the code by adding you wifi credentials on [Line 46 and 47](https://github.com/ecasti-gmail-com/m5gps/blob/92003a552e9acf04ae832566619a0cddb3725a50/tools/sqlite3_web_console_working/sqlite3_web_console_working.ino#L46)
Build and deploy on the M5stack.
Get your ip address from serial console.
Connect to the web and run you queries there.
### Note: 
Specify as database file  **/sd/gps_track.db**
