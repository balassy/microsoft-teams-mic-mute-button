// Based on the code of JH Jeong (https://www.thingiverse.com/thing:3551855)

#include <HID.h>
#include <Keyboard.h>

// Connect switch between PIN8 and GND.
const int switch_pin        = 8;

int button_state            = 0;
int previous_button_state   = HIGH;
long last_debounce_time     = 0;
const long debounce_delay   = 50;

void setup() 
{
  pinMode(switch_pin,INPUT_PULLUP); 
  digitalWrite(switch_pin, HIGH);
  
  Keyboard.begin();
}


void loop() 
{
  button_state = digitalRead(switch_pin);
  if ((button_state != previous_button_state) && (button_state == HIGH)) 
  {
    if ((millis() - last_debounce_time) > debounce_delay) 
    {
      // Keyboard shortcuts for Microsoft Teams: https://support.microsoft.com/en-us/office/keyboard-shortcuts-for-microsoft-teams-2e8e2a70-e8d8-4a19-949b-4c36dd5292d2
      // Use KEY_LEFT_GUI on Mac and KEY_LEFT_CTRL on Windows.
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('m');
      delay(100);
      Keyboard.releaseAll();
      last_debounce_time = millis();
    }
  }
  previous_button_state = button_state;
}
