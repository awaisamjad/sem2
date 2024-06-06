#include "Keyboard.h"

boolean automatic = true;  // Toggle to automatically open apps on plug-in

/*
If true - Make sure you have buttons plugged in to the Arduino otherwise it will loop forever!
Do not turn on unless you need to experiment with buttons!
*/
boolean buttons = false;

uint8_t clock_app = 'a';  //Calendar

void setup() {
  Keyboard.begin();

  //This delay is necessary for the library to init for automatic demo
  delay(2000);
}

void openAndClose(uint8_t key) {
  Keyboard.write(key);
  delay(1000);
  Keyboard.write(KEY_RETURN);
  delay(500);
}

void openApp(uint8_t key) {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(key);
  Keyboard.releaseAll();
}

void loop() {
  if (automatic) {
    //   Keyboard.press(KEY_LEFT_GUI);

    //   openAndClose(clock_app);

    //   Keyboard.release(KEY_LEFT_GUI);

    //   Keyboard.write(KEY_TAB);
    //   delay(1000);
    //   Keyboard.println(" techtalkies.in");
    //   automatic = false;
    // }

    // if (buttons) {
    //   if (digitalRead(2) == HIGH)
    //     openApp(App2);

    //   if (digitalRead(3) == HIGH)
    //     openApp(App3);

    //   if (digitalRead(4) == HIGH)
    //     openApp(App4);
    // }
    openApp(clock_app);
    delay(1000);
  }
}
