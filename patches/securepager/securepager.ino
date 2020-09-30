#include <SmartResponseXE.h>
#include <CC1101.h>

// THIS IS NOT DONE!!!

// https://github.com/ea/SmartResponseXE
// https://github.com/ea/CC1101 - should I change pins to work with pogo-pins?

void setup() {
  SRXEInit(0xe7, 0xd6, 0xa2); // initialize display
  SRXEWriteString(0,120,"Hello World!", FONT_LARGE, 3, 0); // draw large black text at x=0,y=120, fg=3, bg=0

  // read privkey-hash from external-flash, or generate a new privkey
  // look up friends-list
  // require password for new key or message-reading (with option to keep it in RAM)

  // mostly sleep & wake up on power-button or POCSAG with my ID
  // save (encrypted) message in external-flash when it comes in
  // menu for managing friends, messages, key, and mode (all POCSAG, just me, etc)
  
}

void loop() {}
