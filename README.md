# platform-wch-ch55x
WCH (CH55x) : development platform for PlatformIO

# Usage 
1. [ Install PlatformIO ]( https://platformio.org/ )
2. Create PlatformIO project and configure a platform option in [platformio.ini](https://docs.platformio.org/en/latest/projectconf/index.html) file : 


```ini
[env:development]
platform = https://github.com/amn97pi/platform-wch-ch55x.git
board = ch559
build_flags = 
    --model-small
    -Iinclude
upload_protocol = custom
#monitor_port = COM8 
#monitor_speed = 57600 
```

Or install locally cloning  https://github.com/amn97pi/platform-wch-ch55x.git in C:\%SUERNAME%\.platformio\platforms

```ini
[env:ch559]
platform = wch-ch55x
board = ch559
build_flags = 
    --model-small
    -Iinclude
upload_protocol = custom
#monitor_port = COM8 # Select serial port
#monitor_speed = 57600  
```

## Upload 

1. Download chflasher.exe from https://github.com/atc1441/chflasher 
2. Download [hex2bin.exe](https://sourceforge.net/projects/gnuwin32/files/hex2bin/1.02/hex2bin-1.02-bin.zip/download?use_mirror=deac-fra&download=)
3. On windows install [zadig](https://zadig.akeo.ie/) and install libusb-win32 driver
4. Copy chflasher.exe and hex2bin.exe (or add to the path)in your project folder for upload from vscode with platformio 