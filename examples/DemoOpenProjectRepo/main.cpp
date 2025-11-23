#include <Arduino.h>
#include <DigiKeyboardMultilang.h>
#include <extendedLanguages.h>  // ExtendedLanguages - provides lang_de, lang_fr, lang_gr so far

DigiKeyboardMultilang keyboard(lang_de); // IMPORTANT Declare keyboard layout! e.g., lang_us for US English

/*
This code is automaticaly nested inside the main() function by the Arduino build system.

Below, the user-defined setup() and loop() functions are defined.

The default example payload here opens the Windows Run dialog and types a URL to open in the default browser.

*/

const char* runCmdPld = "https://github.com/3mrgnc3/attiny85_ducky"; // ScattRoll URL Example

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

void loop() {
    // the loop function is intentionally left empty But if you want to repeat the payload,
    // you can add code here with your desired logic and delays instead of in setup().
}