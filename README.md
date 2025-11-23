# ATTiny85 Ducky

### A Cheap Disposable Alternative to the Hak5 USB RubberDucky

This Platformio Project Repository utilizes the [AZ-Delivery ATTiny85 Digispark Rev.3 Kickstarter](https://www.az-delivery.de/en/products/digispark-board) as a USB RubberDucky-like device capable of executing pre-programmed keystroke injection attacks. It leverages the DigiKeyboardMultilang library to simulate keyboard inputs, allowing for versatile payload delivery.

![ATTiny85 Ducky](images/rev3.png)



# :warning: Disclaimer Warning :warning:
This project is intended for authorised security testing and educational purposes only. Unauthorized use of this device on systems without explicit permission is illegal and unethical. The author does NOT endorse and is NOT responsible for any misuse or damage caused by improper use of the code and examples in this project.

## :rotating_light: Only test/use your payloads in a safe and legal environment! :rotating_light:


## Features
- Utilizes the DigiKeyboardMultilang library for multi-language keyboard support.
- **ExtendedLanguages library** - Custom library that extends DigiKeyboardMultilang with additional keyboard layouts for German, French, and Greek Keyboards
- **Example Payloads** - Pre-configured examples in the `examples/` directory.
- **Simple setup and programming process** using the PlatformIO project environment provided.

## Getting Started

Clone this repository to your local machine.

```
git clone https://github.com/yourusername/attiny85_ducky.git

```


Open the included project workspace file `attiny85_ducky.code-workspace` in [Visual Studio Code](https://code.visualstudio.com/).

```
cd attiny85_ducky
code .vscode/attiny85_ducky.code-workspace
```

#### Setup Extensions Dependencies & Drivers
Install the [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) and [PlatformIO IDE VS Code Extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) if you haven't already. (see: [PlatformIO Intsall Guide](https://platformio.org/install/ide?install=vscode)

![C/C++ Extension Pack](images/cpp_extension_pack.png)
![PlatformIO IDE](images/platformio_ide.png)

During setup, drivers and required libraries will be automatically downloaded to the `.pio` directory in the project folder. however if there are any issue with driver installation, a copy of the bootloader drivers is provided in the `drivers/` folder as a backup option for manual installation. a README with instructions is also provided in the `drivers/` folder to guide you through the manual installation process if needed.

#### Uploading the Default Payload
It is recommended to try out the default payload first to check that everything is working. This is in the `src/main.cpp` file by default and opens the GitHub project URL in the default browser. this is that same payload provide in the `examples/DemoOpenProjectRepo/` directory. 

:exclamation: `Remember to set the correct keyboard layout.`
e.g. change `DigiKeyboardMultilang keyboard(lang_de);` to `DigiKeyboardMultilang keyboard(lang_us);` for US English Keyboard layouts insted of using the default German QWERTZ layout provided.

Default Payload Code Section in `src/main.cpp`:
```cpp
const char* runCmdPld = "https://github.com/3mrgnc3/attiny85_ducky"; // Open URL Example

int redLED = 1;

void setup() {
    pinMode(redLED, OUTPUT); // Initialize the RED LED pin as an output
    digitalWrite(redLED, HIGH); // Turn on the RED LED while executing payload
    
    // --- THE HID INJECTION STARTS HERE ---
    keyboard.delay(6000); // Wait 6 seconds to allow the OS to recognize the device and install drivers if needed
    keyboard.sendKeyStroke(KEY_R, KEY_E); // Win+R (0x08 = Left GUI/Windows key modifier)
    keyboard.delay(800); // Wait 0.8 seconds for the run dialog to open
    keyboard.println(runCmdPld); // Opens the Project Github URL using the run dialog
    // --- THE HID INJECTION ENDS HERE ---
    
    digitalWrite(redLED, LOW); // Turn off the RED LED after executing payload
}
```


#### Building & Uploading the example Payload
In the PlatformIO toolbar, click the `build` button to ensure that the build works and does an auto-setup / download of the **digispark-tiny** and **DigiKeyboardMultilang** code to the `.pio` directory in the project.
![Build Button](images/build_test.png)

**ONLY IF the build test says `SUCCESS`**, proceed to the upload to device step, else debug and retest until it is successfull!

IMPORTANT!: `Disconnect the DigiSpark ATTiny85 device`, then without anything plugged in, **click** the `upload` button in the PlatformIO toolbar. 
![Upload Button](images/upload_button.png)

On a successfull compilation, `you will have 60 seconds to connect the device` where its bootloader is listening for upload.
![Connect Device](images/connect_device.png)

Unlike other PlatformIO projects, you must manually connect the DigiSpark ATTiny85 device **after** clicking the upload button, as the bootloader only listens for a short time after connection. This is because it uses the Micronucleus bootloader which has this limitation.

Micronucleus is different from typical USB bootloaders in that it only listens for a short period after the device is plugged in using its own dedicated interface available when the correct drivers are installed. No Serial interface is available during this time and the Micronucleus driver does not create a COM port like other bootloaders.

This means you need to connect the device within 60 seconds after clicking the upload button in PlatformIO.


Once uploaded, the device will execute the pre-programmed payload when plugged into a target machine. The default provided and all the example payloads are designed for Windows systems and will pause for 6 seconds to allow the OS to recognize the device and auto-install any required drivers before executing the payload. If you don'y want to execute the payload immediately, you simply need to unplug it within 6 secomd of the RED LED lighting up.

## Customization
To customize the payload, modify the `setup()` and `loop()` functions in `src/main.cpp`. 

In addition to the 6 second delay before payload execution, you can also add your own delays in the payload code itself using `keyboard.delay(ms);` where `ms` is the number of milliseconds to wait.

#### Building & Uploading the Your Own Payloads
Once the demo payload was successful, you should then proceed to modify the payload or try out other example payloads provided in the `examples/` directory. The simplest way to do this is to copy the `main.cpp` file from the example folder you want to try into the `src/` directory, replacing the existing `main.cpp` file. 

When developing your own payloads, you can refer to the example payloads for guidance, but should start by modifiying the lines between the comment lines `// --- THE HID INJECTION STARTS HERE ---` & `// --- THE HID INJECTION ENDS HERE ---` to create the logic of your HID injection commands. 

Custom values such as adjustable string parameters can be set in the top of the file. e.g. `const char* runCmdPld = "https://youtu.be/Hy8kmNEo1i8";` or `cmd.exe /c netsh wlan show profile` etc.

Check out the `WiFiCredsDemo` or `AddRDPAdminAccount` for two example of execution in a administrator context in powershell with minimal user interaction to bypass UAC.

-----
## Simple Example Payload to execute a ScattRoll URL on Windows:

Modify the `src/main.cpp` file as follows:

```cpp
#include <Arduino.h>
#include <DigiKeyboardMultilang.h>
#include <extendedLanguages.h> // Include ExtendedLanguages for additional layouts

DigiKeyboardMultilang keyboard(lang_de); // Use lang_de for German QWERTZ layout (or lang_us for US English)

const char* runCmdPld = "https://youtu.be/Hy8kmNEo1i8"; // ScattRoll URL Example

int redLED = 1;

void setup() {
    pinMode(redLED, OUTPUT); // Initialize the RED LED pin as an output
    digitalWrite(redLED, HIGH); // Turn on the RED LED while executing payload
    
    // --- THE HID PAYLOAD STARTS HERE ---
    keyboard.delay(5000); // Wait 5 seconds to allow the OS to recognize the device
    keyboard.sendKeyStroke(KEY_R, KEY_MOD_GUI); // Win+R (0x08 = Left GUI/Windows key modifier)
    keyboard.delay(800); // Wait 0.8 seconds for the run dialog to open
    keyboard.println(runCmdPld); // Open a ScattRoll URL in the run dialog
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

Detailed Payload Explanations and Syntax can be found in the [Creating Custom Payloads](https://github.com/3mrgnc3/attiny85_ducky/wiki/Creating-Custom-Payloads) wiki page.


Else, further inspiration for creating your payloads can be found by alternatively checking out the preexisting ones made available already by [**CedArctic** in the **DigiSpark-Scripts** repo](https://github.com/CedArctic/DigiSpark-Scripts). 


**Available Keyboard Layouts:**
- `lang_us` - US English (from DigiKeyboardMultilang)
- `lang_de` - German QWERTZ (from ExtendedLanguages) ✅ **TESTED & WORKING with the examples provided**
- `lang_fr` - French AZERTY (from ExtendedLanguages)
- `lang_gr` - Greek (from ExtendedLanguages)
- More layouts available in the DigiKeyboardMultilang library documentation

----

Have Fun 

![ATTiny85 Ducky](images/rev3_board.png)
