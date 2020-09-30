# smartxe

Resources for working with Smart Response XE and custom code with CC1101 radio module.

## Setup

* use ICSP on [pogo-pins](https://github.com/securelyfitz/smartresponse) through (existing) holes in battery compartment to to do initial arduino bootloader programming (so you can use serial instead of ICSP)
* The arduino hardware-definition matches [this](https://learn.sparkfun.com/tutorials/atmega128rfa1-dev-board-hookup-guide/overview)
* Program the arduino bootloader with ICSP, then use serial to make it work more like regular arduino, set the programming port to serial 1
* Connect a CC1101 board (with little antenna) to SPI (`MISO`, `MOSI`, `SCK`, `VCC`, `GND` on ICSP test-pads) and GD0 (labeled `CS_flash`) & CSN pins (left pin of `R34`)
* Connect serial TX/RX of `RS232` to connector for serial adapter and solder-bridge pins 3,4,5 on `U6` trace.
* Drill hole in case to fit antanna, cut little bit out of fin inside to fit the board
* use [arduino lib](https://github.com/bitbank2/SmartResponseXE)
* use [CC1101 lib](https://github.com/ea/CC1101)

![cc1101 hookup](https://github.com/ea/srxe_cc1101/raw/master/photos/board_annot.png)

![serial hookup](https://github.com/ea/srxe_cc1101/raw/master/photos/uart.png)

![case mod](https://github.com/ea/srxe_cc1101/raw/master/photos/cc1101_fits.png)

## arduino patches

* [pager](https://github.com/ea/srxe_cc1101/tree/master/srxe_cc1101_pager)
* [spectrum analyzer](https://github.com/ea/srxe_cc1101/tree/master/srxe_specan)
* 

## needs investigation

* A small plug like [this](https://www.sparkfun.com/products/14050) built-in to case might make it more arduino-like, and easier for non-tech (and tech) people to use
* Need to work out how to use the SPI flash & CC1101 at same time (I think it's either/or right now)
* Need to see if I can get the built-in radio doing something useful.
* Figure out all the GPIO I can access and wire them to a port. It would be neat to be abel to do i2c, etc. Some are easier to get at (like JTAG, speaker pins, and top-4 pogo pins)
* I think auto-reset doesn't work right, on program
* Add (real) power switch
* Try to wire CC1101 into pogo board for 0-soldering?


## Thanks

* [useful pinout docs](https://pastebin.com/uFfBCQDG)
* Image-credit: [@ce](https://github.com/ea/srxe_cc1101). Lots of great notes on putting it together, too.
* [arduino lib](https://github.com/bitbank2/SmartResponseXE) is very useful.
* [This](https://github.com/fdufnews/SMART-Response-XE-Low_level) has some good notes & setup for easier arduino
* [this](https://community.arduboy.com/t/smart-response-xe-re-purposed-into-arduboy/6094) has notes about running arduboy on the XE