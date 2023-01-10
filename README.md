This is an Arduino IDE Sketch that harnesses a [Teensy microcontroller](https://www.pjrc.com/teensy/) to turn a [GRS Arcade Spinner for Arcade1Up](https://thunderstickstudio.com/products/grs-arcade-spinner) from Thunderstick Studios into a USB game controller with game, select and reset buttons.

The default mappings are designed to work with [Atari 2600 Stella Emulator](https://stella-emu.github.io/) defaults.

## Installation

  1. Download and install [Arduino IDE](https://www.arduino.cc/en/software). I recommend version 2.0 or above.
  1. Open up `rooster.ino` in the IDE.
  1. Choose your board from the Tools Menu. I used a Teensy LC, but any Teensy should be fine.
  1. Again from the Tools Menu, choose a USB Type of "Keyboard + Mouse + Joystick" or "Serial + Keyboard + Mouse + Joystick"
  1. Wire your custom controller. The power wire (typically red) from the spinner PCB's 4-pin port should go to the Teensy's 5V pin, and the ground wire (typically black) should go to the Teensy's ground pin. The RX1 serial pin wire (typically yellow) should go to digital pin zero on the Teensy. The TX1 serial pin wire (typically white) should go to digital pin 1 on the Teensy. One wire for each button should go to a free digital pin on the Teensy, and the other should connect to the Teensy's ground pin.
  1. Edit `rooster.ino` for your own button pin mappings, or to remove anything not in your setup.
  1. Plug the Teensy into your computer's USB and Upload. 