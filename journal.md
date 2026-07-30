# July 28: the struggles of a kicad noob - 1 hr 17 secs (lapse)
I read through the runway guide to help me out for this project.
Reading through the second step, I learned about the different components of a PCB (input, output, connector), and also how to do research (datasheets) and get useful files (symbols for schematics, and footprints for PCBs) for each part.

After reading through, I downloaded the symbols (.kicad_sch) for each component and imported it into a kicad schematic file.
Unfortunately, I couldn't find one for the AS5600, so I just imported a .sch and hoped it worked.

After importing everything, I wired the SDA and SCL parts together using labels. They look different than the ones shown in the guide, but it should be fine. However, I couldn't find any pinout diagrams for the buzzer (PS1240P02BT) so I just guessed where they might go.

This is the schematic I have so far:
![Image of schematic progress on 072826](journal-pictures\072826.png)

It looks very complicated and I have no idea what I'm looking at. 

# July 30: remaking the whole schematic - 41 mins 57 secs (lapse)
Looking through the datasheets for each component, I realized that I made the whole schematic incorrectly. 
My schematic looks a lot more complicated than the pinout diagrams for the datasheets.

So, I did some googling and found the correct schematics for the microcontroller (RP2040-**DIP**) and the rotation-input component (found an actual .kicad_sch instead of .sch).
However, I still don't know what the "1" and "2" mean for the buzzer, and since there are no pinout diagrams or explanations on the datasheet, I have no idea what to do with it. 
Additionally, there's an "A" piece and a "B" piece, and they're different, so I'm also confused about that.

Here is the new schematic:
![Image of schematic progress on 073026](journal-pictures\073026.png)

It's a lot more simpler and makes more sense to me.