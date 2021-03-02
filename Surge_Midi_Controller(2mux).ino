#include <Control_Surface.h>  // Include the library
 
USBMIDI_Interface midi;  // Instantiate a MIDI Interface to use

// Three Banks to change the channel of the pot
Bank<3> bank(7); // 1st number is # of banks, 2nd is # of tracks per bank

// Selector to change banks
IncrementDecrementSelectorLEDs<3> bankSelector = {
    bank,       // Bank to manage
    {0, 1},    //push button pins (inc/dec)
    {6, 9, 10}, //LED Pins
};
 
// Instantiate a multiplexer
CD74HC4067 mux = {
  A5,              // analog pin
  {2, 3, 4, 5}, // Address pins S0, S1, S2, S3
   7, // Optionally, specify the enable pin
};

Bankable::CCPotentiometer oscpotentiometers[] = {
  {{bank, BankType::CHANGE_ADDRESS}, mux.pin(0), { MIDI_CC::Sound_Controller_1 } },
  {{bank, BankType::CHANGE_ADDRESS}, mux.pin(1), { MIDI_CC::Sound_Controller_2 } },
  {{bank, BankType::CHANGE_ADDRESS}, mux.pin(2), { MIDI_CC::Sound_Controller_3 } },
  {{bank, BankType::CHANGE_ADDRESS}, mux.pin(3), { MIDI_CC::Sound_Controller_4 } },
  {{bank, BankType::CHANGE_ADDRESS}, mux.pin(4), { MIDI_CC::Sound_Controller_5 } },
  {{bank, BankType::CHANGE_ADDRESS}, mux.pin(5), { MIDI_CC::Sound_Controller_6 } },
  {{bank, BankType::CHANGE_ADDRESS}, mux.pin(6), { MIDI_CC::Sound_Controller_7 } },
};

CCPotentiometer adsrpots[] = {
  {mux.pin(7), {MIDI_CC::General_Purpose_Controller_1}},
  {mux.pin(8), {MIDI_CC::General_Purpose_Controller_2}},
  {mux.pin(9), {MIDI_CC::General_Purpose_Controller_3}},
  {mux.pin(10), {MIDI_CC::General_Purpose_Controller_4}},
  {mux.pin(11), {MIDI_CC::General_Purpose_Controller_5}},
  {mux.pin(12), {MIDI_CC::General_Purpose_Controller_6}},
  {mux.pin(13), {MIDI_CC::General_Purpose_Controller_7}},
};

CCPotentiometer MainVolume = {A3, {MIDI_CC::Channel_Volume, CHANNEL_1}};
CCPotentiometer SendFX1 = {A1, {MIDI_CC::Effect_Control_1}};
CCPotentiometer SendFX2 = {A2, {MIDI_CC::Effect_Control_2}};

void setup() {
  Control_Surface.begin();  // Initialize the Control Surface
  mux.begin();
}
 
void loop() {
  Control_Surface.loop();  // Update the Control Surface
}
