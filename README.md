# smartxe

Resources for working with Smart Response XE and custom code with CC1101 radio module.

## Setup

* use ICSP on [pogo-pins](https://github.com/securelyfitz/smartresponse) through (existing) holes in battery compartment to to do initial arduino bootloader programming (so you can use serial instead of ICSP)
* The arduino hardware-definition matches [this](https://learn.sparkfun.com/tutorials/atmega128rfa1-dev-board-hookup-guide/overview)
* Program the arduino bootloader with ICSP, then use serial to make it work more like regular arduino, set the programming port to serial 1
* Connect a CC1101 board (with little antenna) to SPI (`MISO`, `MOSI`, `SCK`, `VCC`, `GND` on ICSP test-pads) and GD0 (labeled `CS_flash`) & CSN pins (left pin of `R34`)
* Connect serial TX/RX of `RS232` to connector for serial adapter and solder-bridge pins 3,4,5 on `U6` trace.
* Drill hole in case to fit antanna, cut little bit out of fin inside to fit the CC1101 board
* use [arduino lib](https://github.com/bitbank2/SmartResponseXE). It has LCD, keyboard functions, and `SRXESleep` which can use power button + interrupts to make device power off work right
* use [CC1101 lib](https://github.com/ea/CC1101)

![cc1101 hookup](https://github.com/ea/srxe_cc1101/raw/master/photos/board_annot.png)

![serial hookup](https://github.com/ea/srxe_cc1101/raw/master/photos/uart.png)

![case mod](https://github.com/ea/srxe_cc1101/raw/master/photos/cc1101_fits.png)

## arduino

* [wireless bootloader](https://github.com/bitbank2/SMART_bootloader) it's kinda big & requires sacraficial XE, but might be good for some situations, and maybe I could do something with RTL-SDR, with a little work
* [pager](https://github.com/ea/srxe_cc1101/tree/master/srxe_cc1101_pager)
* [another pager](https://github.com/pdxbadgers/5ohBEE-2019)
* [spectrum analyzer](https://github.com/ea/srxe_cc1101/tree/master/srxe_specan)
* [BASIC Interpretor](https://github.com/akkera102/07_tiny_basic)
* [arduboy2 core](https://pastebin.com/1uWmkqGT)
* [arduboy2 core + Virus LQP-79 game](http://mrblinky.net/smartresponse/smartresponse-xe-interlaced-paintscreen.zip)


## needs investigation

* A small plug like [this](https://www.sparkfun.com/products/14050) built-in to case might make it more arduino-like, and easier for non-tech (and tech) people to use. Another option would be to solder  MAX3221 and 0.1uF to board (using existing RS232 traces)
* Need to work out how to use the SPI flash & CC1101 at same time (I think it's either/or right now)
* Need to see if I can get the built-in radio doing something useful.
* Figure out all the GPIO I can access and wire them to a port. It would be neat to be able to do i2c, etc. Some are easier to get at (like JTAG, speaker pins, and top-4 pogo pins)
* Work out programmer RESET. I needs a 0.1uF capacitor, an d a little soldering
* Try to wire CC1101 into pogo board for 0-soldering?
* keep multiple "roms" on flash and swap them out with menu bootloader


## Thanks

* [useful pinout docs](https://pastebin.com/uFfBCQDG)
* [useful forum thread](https://community.arduboy.com/t/smart-response-xe-re-purposed-into-arduboy/6094)
* Image-credit: [@ce](https://github.com/ea/srxe_cc1101). Lots of great notes on putting it together, too.
* [arduino lib](https://github.com/bitbank2/SmartResponseXE) is very useful.
* [Detailed setup](https://docs.google.com/document/d/1TT3Tmx0-dsvzmA0lSYiwq4LR293aMV1dJWhriqxD-Po/edit)
* [This](https://github.com/fdufnews/SMART-Response-XE-Low_level) has some good notes & setup for easier arduino
* [this](https://community.arduboy.com/t/smart-response-xe-re-purposed-into-arduboy/6094) has notes about running arduboy on the XE