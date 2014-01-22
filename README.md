TinyFox

This is a way to make a fox for amateur radio foxhunting, using an inexpensive HT and low cost electronic parts.

The fox is designed to connect to the Baofeng UV-5R, but it is easily adjustable to alternate radios. The UV-5R was
selected due to its high availability in W3VC, but also its low (and constantly falling) cost.

The software is easily changable, with the #define's at the top of the single C file. The various constants
were selected to produce a pleasant sounding CW signal. However, they can be adjusted to suit your preferences.

The callsign is changed in the main loop. Please change this to your callsign before using. Also remember to edit
the next line, which sets the length of the callsign (yes, I could make this automatic, but thats a future version).

If you want to use a different radio, check the schematics for their speaker-mic connector. It may use the same connector
as specified here, or a different one that may just include rearranging the pins.

The schematics are for the fox circuit. A separate programming circuit for the ATTiny will be required. 

Key Parts:
1 2k resistor
1 12k resistor
1 Atmel AVR ATTiny 25/45/85 (they all are the same chip with different amounts of flash, but all work here)
1 DIP 8-pin socket (so you can program the chip separately, and then insert into the fox)
1 2.5mm TRS plug
1 3.5mm TRS plug

The design and code assumes you are capable of programming the circuit with pure C, using either Atmel Studio or avrdude, via
an AVR programmer (usually an AVR ISP MkII). If you are more comfortable with the Arduino environment, it may be possible to build
this circuit using the Adafruit Trinket (https://www.adafruit.com/products/1500). Make sure you get the 3.3V version, because that
is closer to the voltage supplied by the radio. I HAVE NOT TESTED THIS, but I believe it should work. You'll have to modify the code
slightly to use the Arduino environment (but not necessarily the pin numbers). An added advantage of using the Trinket is you can
program via USB, and you don't need an AVR programmer.

You can also use other AVR microcontrollers or Arduino boards. You will have to change the pin numbers. I chose the ATTiny25 because
it costs approximately $1.05. Otherwise, feel free to pick one that you have available. 

If you want any assistance, feel free to contact me: ben@benwasserman.com (KB1SZH).