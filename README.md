# My-Projects
Projects for embedded system learning.
## Abstract

An **embedded system** is a computer system—a combination of a [computer processor computer memory peripheral devices—that has a dedicated function within a larger mechanical or electrical system.

The aim of this project is to design and build an embedded system to
measure human eye flicker fusion threshold using a **Teensy 3.2** microcontroller.
I have designed and implemented this and my flicker fusion threshold was tested.

This is my first embedded system project and it helped me gain further knowledge about the functionality and applications of microcontrollers.

## Introduction

The **flicker fusion threshold**, or **flicker fusion rate**, is a concept in the psychophysics of vision. It is defined as the frequency at which an intermittent light stimulus appears to be completely steady to the average human [observer]. Flicker fusion threshold is related to [persistence of vision]. Although flicker can be detected for many waveform representing time-variant fluctuations of intensity, it is conventionally, and most easily, studied in terms of sinusoidal modulation of intensity.

The requirements of the project are:
 A flashing LED(50 percent duty cycle) should serve as the visual stimulus.
 A potentiometer should be used to adjust the LED’s blink
frequency.
A button should be connected which when pressed a hardware
interrupt is to be triggered and the currently set blink
frequency should be displayed in a serial monitor or PC.
No delay() function to be used and debouncing of the button to be done.

I have used a **Teensy 3.2** Microcontroller, which is a small but very capable 
USB development board.
Its Arduino IDE compatible and I have used VSCode to code the program to the Teensy 3.2.

## Hardware Details

**Teensy 3.2** microcontroller
A **5mm** Green **LED**
A **10 kilo-ohm** linear **potentiometer** (B10K)
A **330 ohm** resistor for **pull up**
Some connecting wires and breadboard.

**Calculations for hardware:**
Voltage Drop across led =Vdrop=1.8V(assuming normal standard)
Teensy supply voltage =Vin= 3.3V
LED max curennt pin limit=Imax= 25mA (20~25mA)
R=(Vin-Vdrop)/Imax= 48ohms.
To protect LED and limit the max current to 10mA is selected
which gives 120ohms
If there is no voltage drop we would then need 3.3/.010=330 ohms as safety standards.

## Schematic and circuit design.
 ![enter image description here](https://github.com/vishnurad/My-Projects/blob/Project_1_Flicker_fusion_threshold/2020-05-10%20%284%29.png)

![enter image description here](https://github.com/vishnurad/My-Projects/blob/Project_1_Flicker_fusion_threshold/2020-05-10%20%286%29.png)







## Software details

https://github.com/vishnurad/My-Projects/blob/Project_1_Flicker_fusion_threshold/main.cpp.pdf



**ledPin(8)** is the output
Using **Pinmode , buttonPin(12)** is set as the input
**ISR** is the interrupt service routine.

**Timeperiod** is half of the original time period as it record the time when **LED** is either turned **OFF** or **ON** which is .002seconds

Therefore, **frequency**=1/(.002***Timeperiod**)=500/**Timeperiod.**
But to reduce errors from large scale, we employ map() function to scale down **Timeperiod** to a lower range **xtime**
ie; **frequency**=500/**xtime**





## Output:

![enter image description here](https://github.com/vishnurad/My-Projects/blob/Project_1_Flicker_fusion_threshold/2020-05-09%20%282%29.png)



## Serial plotter output:
![enter image description here](https://github.com/vishnurad/My-Projects/blob/Project_1_Flicker_fusion_threshold/2020-05-10%20%2812%29.png)


Period of wave =(time taken to complete one cycle)= 4*2=8ms (as original **Timeperiod** is half of original time period )

Now 
**frequency**=1/Period of wave in seconds=1/(8*2*10pow(-3))=62.5 Hz
which is close to our frequency range.

## Working detail:



Available on youtube:
https://youtu.be/wdBYyEvzVNI

Available on Github:

[https://github.com/vishnurad/My-Projects/blob/Project_1_Flicker_fusion_threshold/README.md](https://github.com/vishnurad/My-Projects/blob/Project_1_Flicker_fusion_threshold/README.md)



## Conclusion:

Human eye flicker fusion threshold was tested sucessfully using the system designed.
Subject under test was me and my finding is that I am unable to detect any flicker above the 55Hz range.

This project has allowed me to explore:

**Teensy 3.2** microcontroller and its terminologies.

**Arduino IDE** and coding library

Setting up **Visual Studio Code** and **version control system**(Git) for my projects.

Using **markdown** language editors(**Typora** and **StackEdit**)





## References:

| Article title: | Flicker fusion threshold                               |
| -------------- | ------------------------------------------------------ |
| Website title: | En.wikipedia.org                                       |
| URL:           | https://en.wikipedia.org/wiki/Flicker_fusion_threshold |

| Article title: | Teensy USB Development Board |
| -------------- | ---------------------------- |
| Website title: | Pjrc.com                     |
| URL:           | https://www.pjrc.com/teensy/ |

| Article title: | Programming Electronics Academy                          |
| -------------- | -------------------------------------------------------- |
| Website title: | YouTube                                                  |
| URL:           | https://www.youtube.com/channel/UCDGAg1pqcy8IScMqHHTy9Gg |

