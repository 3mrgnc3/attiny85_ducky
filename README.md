# ATTiny85 Ducky

### A CheapDisposable Alternative to the Hak5 USB RubberDucky

This Platformio Project Repository transforms the AZ-Delivery ATTiny85 Digispark Rev.3 Kickstarter into a USB RubberDucky-like device capable of executing pre-programmed keystroke injection attacks. It leverages the DigiKeyboardMultilang library to simulate keyboard inputs, allowing for versatile payload delivery.

![ATTiny85 Ducky](rev3.png)

## Features
- Utilizes the DigiKeyboardMultilang library for *multi-language keyboard support (no DE Lang yet).
- Simple setup and programming process using the PlatformIO project environment provided.
- A selection of pre-programmed payload `examples` are provided for common attack vectors, easily customizable.

## Roadmap
- [ ] Add support for additional keyboard layouts (e.g., German, French).
- [ ] include more complex payload examples.
- [ ] Include customizable micronucleus bootloader with modifiable USB VID/PID & vendor/device names for stealth.

## Getting Started
1. Clone this repository to your local machine.
3. Open the included project workspace file `attiny85_ducky.code-workspace` in Visual Studio Code.
3. Install the PlatformIO extension if you haven't already. (https://platformio.org/install/ide?install=vscode)
4. In the PlatformIO toolbar, click the `build` button to ensure that the build works and does an auto-setup / download of the **digispark-tiny** and **DigiKeyboardMultilang** code to the `.pio` directory in the project.
5. ONLY IF build says it SUCCEEDS, proceed to try uploading: using the `upload` button in the PlatformIO toolbar with the DigiSpark ATTiny85 device disconnected. you have 60 seconds to connect the device where it's bootloader is listening for upload.
6. Once uploaded, the device will execute the pre-programmed payload when plugged into a target machine.
## Customization
To customize the payload, modify the `setup()` and `loop()` functions in `src/main.cpp`. 

-----
## Simple Example Payload to execute a RickRoll URL on Windows:

Modify the `src/main.cpp` file as follows:

```cpp
#include <Arduino.h>
#include <DigiKeyboardMultilang.h>

DigiKeyboardMultilang keyboard(lang_us); // IMPORTANT Declare keyboard layout! e.g., lang_us for US English

const char* runCmdPld = "https://youtu.be/dQw4w9WgXcQ"; // RickRoll URL Example

int redLED = 1;

void setup() {
    pinMode(redLED, OUTPUT); // Initialize the RED LED pin as an output
    digitalWrite(redLED, HIGH); // Turn on the RED LED while executing payload
    // --- THE HID PAYLOAD STARTS HERE ---
    keyboard.delay(5000); // Wait 5 seconds to allow the OS to recognize the device
    keyboard.sendKeyStroke(KEY_R, 0x08); // Win+R (0x08 = Left GUI/Windows key modifier)
    keyboard.delay(800); // Wait 0.8 seconds for the run dialog to open
    keyboard.println(runCmdPld); // Open a RickRoll url in the run dialog
    keyboard.delay(3000); // Wait 3 seconds for the browser to open
    keyboard.println("f");// YouTube fullscreen shortcut key = 'f'
    // --- THE HID PAYLOAD ENDS HERE ---
    digitalWrite(redLED, LOW); // Turn off the RED LED after executing payload
}

void loop() {
    // the loop function is intentionally left empty But if you want to repeat the payload,
    // you can add code here with your desired logic and delays instead of in setup().
}
```

Now you can plug in the device to a Windows machine, and it will open the RickRoll URL in the default web browser after a short delay.


-----


### Be sure to test your payloads in a safe and legal environment!

## Disclaimer
This project is intended for educational purposes only. Unauthorized use of this device on systems without explicit permission is illegal and unethical. The author is not responsible for any misuse or damage caused by this project.

