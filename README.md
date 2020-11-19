# Raspberry Pi 3B+
This repository contains "bare metal" software examples coded in C and Aarch64 assembly that run on a Raspberry Pi 3B+ as embedded software without an operating system and without the standard library. These examples include a build.bat file that works under Windows 10 to cross compile and run on the Raspberry Pi 3B+. The examples can be built on other operating systems by using your own build script.

Please note that this software is not guaranteed to work on the older Raspberry Pi 3B because the 3B and the 3B+ boards differ in some ways. Specifically, the ACT LED of the 3B is not controlled the same as the 3B+ which means the blinker examples will not work on the 3B.

The files in the rpi3bp/firmware/ directory must be included in the root directory of the SD card for code to execute. These files are copies of the most up-to-date files found on the official Raspberry Pi github page, as of the time of upload. Alternatively, you can download the official firmware files here: https://github.com/raspberrypi/firmware/tree/master/boot 

You can read an explanation of the files here: https://www.raspberrypi.org/documentation/configuration/boot_folder.md

Additionally, the SD card must contain a config.txt file with specific settings to run correctly. A valid config.txt file can be found just above the /src/ directory of each project. For example, the config.txt file needed to run the blinker64 example can be found at rpi3bp/blinker64/config.txt and should be placed at the same level as the firmware files in the root directory of the SD card.

If you are curious about the boot sequence of the Raspberry Pi please read this: https://elinux.org/RPi_Software#Overview

# blinker32
 This will blink the ACT LED infinitely, coded to run in 32bit mode. This relies on the arm-none-eabi-gcc compiler and other programs found in the GNU Arm Embedded Toolchain here: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads Update the /src/build.bat file to point to your local tool chain folder.

# blinker64 
 This will blink the ACT LED infinitely, coded to run in 64bit mode. This relies on the aarch64-linux-gnu-gcc compiler and other programs found in the Linaro Toolchain here: https://releases.linaro.org/archive/14.09/components/toolchain/binaries/ Update the /src/build.bat file to point to your local tool chain folder.
