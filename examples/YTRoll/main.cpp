#include <Arduino.h>
#include <DigiKeyboardMultilang.h>
#include <extendedLanguages.h>  // ExtendedLanguages - provides lang_de, lang_fr, lang_gr so far

DigiKeyboardMultilang keyboard(lang_us); // IMPORTANT Declare keyboard layout! e.g., lang_us for US English

const char* runCmdPld = "https://youtu.be/Hy8kmNEo1i8"; // ScattRoll URL Example

int redLED = 1;

void setup() {
    pinMode(redLED, OUTPUT); // Initialize the RED LED pin as an output
    digitalWrite(redLED, HIGH); // Turn on the RED LED while executing payload
    
    // --- THE HID INJECTION STARTS HERE ---
    keyboard.delay(3000); // Wait 3 seconds to allow the OS to recognize the device
    keyboard.sendKeyStroke(KEY_R, 0x08); // Win+R (0x08 = Left GUI/Windows key modifier)
    keyboard.delay(800); // Wait 0.8 seconds for the run dialog to open
    keyboard.println(runCmdPld); // Open a RickRoll url in the run dialog
    keyboard.delay(3000); // Wait 3 seconds for the browser to open
    keyboard.println("f");// YouTube fullscreen shortcut key = 'f'
    keyboard.delay(3000); // Wait 3 seconds for the browser to open
    // --- THE HID INJECTION ENDS HERE ---
    
    digitalWrite(redLED, LOW); // Turn off the RED LED after executing payload
}

void loop() {
    // the loop function is intentionally left empty But if you want to repeat the payload,
    // you can add code here with your desired logic and delays instead of in setup().
}