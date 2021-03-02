# Surge_Midi_Controller
Midi controller specifically designed with hardware and software for the open-source Surge Synthesizer.

Huge kudos to the Surge Synthesizer team and all of their hardwork and updates. Please check out their work at: [Surge Synth Github](https://github.com/surge-synthesizer)

Update 3/2/2020:

This project is about a month old, and a bit slow going since my son is only a few days old. Current features of mux1 file:
* Code is intended for the oscillator section (far left of screen)
* 3 buttons connected to TeensyLC Digital Pins 0 & 1 allow for cycling through the 3 different oscillators
* LED will light up when each bank (corresponding to each oscillator) is selected
* Your screen does NOT need to show the highlighted oscillator - the bank will change regardless of what is on the screen, allowing sound manipulation with minimal mouse clicking. 
* 3 pots using analog pins A1, A2, and A3, are permanent (non-banked) analog inputs for the main volume and FX 1 and FX 2 (top right of the screen). 

Plans/Next Steps:
* mux2 file is in progress and may be buggy/non-operational
* splitting one of the multiplexers into 7 bankables inputs (for the 3 oscillators) and 7 non-bankable variables (for the mixer just to the right of the oscillators). 
* Adding code for a second multiplexer that will be inevitably needed for the future pots. 
* To possibly limit the size of the controller and number of analog inputs needed, I'm considering creating another bankable set of analog inputs and combine lesseer used sliders on the synth. 

Grandiose plans/ideas:
* Create a pull request for surge that allows midi input/control of buttons (like mutes and osc selection)
* If the above is not possible, mimic surge's wavetable presets with physical preset buttons that automatically adjust the OSC sliders to the correct values. 
* add OLED display for certain menu functions. 
