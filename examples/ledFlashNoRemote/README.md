## TcMenu Example: Control the built in LED with the Menu

This example assumes a configuration with a LCD 20x4 display and a rotary encoder. It assumes the LCD display is connected exactly as per DFRobot spec. It assumes you have a rotary encoder connected on pins 2 & 3, with the push button on pin 10. It could easily be reconfigured to 16x2 using the tcMenu designer UI.

This example has two menu items, one that changes the status of the built in LED, and another that shows the analog voltage on the A0 pin.

I've assumed this will be built on either an Uno or MEGA boards, but should work equally well on any other Arduino board with only minor changes.

To get started you can either build the circuit exactly as below and run without loading the menu designer, alternatively, just load the `ledFlashNoRemote.emf` file into the designer, select Code / Generate option and change to match your display.

## Files in the example and their purpose:

* `ledFlashNoRemote.cpp` contains the actual menu item definitions and code needed to start the menu. Do not edit this file, it is regenerated every time you run the designer.
* `ledFlashNoRemote.h` contains the declarations of the menu items, this allows you to access the menu items in your code.
* `ledFlashNoRemote.ino` the sketch, this is not fully regenerated every time you run the designer, instead only new callback functions are added if needed.
* `tcMenuLiquidCrystal.cpp` and `.h` are plugins that are managed by the library, these files are put into your code by the designer.
* `ledFlashNoRemote.emf` is the file where the designer saves the menu structure. It is not used at runtime, only by the designer.