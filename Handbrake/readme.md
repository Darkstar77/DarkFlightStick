# Sim Racing Handbrake
---
## Intro:

This project started life as an experiment to learn to work with linear hall effect sensors for a much larger project I've been working on, an open source, easy to build, ambidextrous general aviation flight stick.

By the time I was done learning how to work with the sensor, it was working so well, I just kept developing it. Why? Well if you are into sim racing, you probably know how expensive these things are. A high end load cell based unit with hydraulic damper will cost well over $1000. The cheap Amazon specials are around $100, and a lot of them are just an on/off switch. You can build this fully analog hall effect sensor driven hand brake, with bespoke clamping desk mount, for around $30; less if you already have some of the parts kicking around. The most expensive single part is the toggle clamp. It's not meant to compete with the high end handbrakes, but it should absolutely blow any of the cheap options out of the water at a third the price.

This repository contains all the 3D print files and arduino source code required to build and assemble one.

---
## BOM:
| Item                            | QTY   | Description                                                                                                                                                                                                                                                |
| ------------------------------- | ----- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| M3x50mm SHCS                    | 4     |                                                                                                                                                                                                                                                            |
| M3x35mm SHCS                    | 2     |                                                                                                                                                                                                                                                            |
| M3x8mm BHCS                     | 9     |                                                                                                                                                                                                                                                            |
| M3x10mm BHCS                    | 1     | Can also use M3x12 here with 2 washers.                                                                                                                                                                                                                    |
| M3x12mm SHCS                    | 5     |                                                                                                                                                                                                                                                            |
| M3x16mm SHCS                    | 2     |                                                                                                                                                                                                                                                            |
| M3x4mm Heat Set                 | 9     |                                                                                                                                                                                                                                                            |
| M3 Nut                          | 8     |                                                                                                                                                                                                                                                            |
| M3 T-Nut                        | 4     |                                                                                                                                                                                                                                                            |
| M4x6mm SHCS                     | 2     |                                                                                                                                                                                                                                                            |
| M4x8mm SHCS                     | 14    |                                                                                                                                                                                                                                                            |
| M4x16mm SHCS                    | 8     |                                                                                                                                                                                                                                                            |
| M4x20mm SHCS                    | 1     |                                                                                                                                                                                                                                                            |
| M4 Washer                       | 4     | For mounting the toggle clamp.                                                                                                                                                                                                                             |
| M4 Nut                          | 5     |                                                                                                                                                                                                                                                            |
| M4 T-Nut                        | 20    |                                                                                                                                                                                                                                                            |
| MR6701-2R                       | 3     | 18x15x4 sealed ball bearing for the pivots.                                                                                                                                                                                                                |
| MX Style Keyswitch              | 1     | For the reset button.                                                                                                                                                                                                                                      |
| Arduino Pro Micro               | 1     | Must be a pro micro with a 32u4, and I recommend USB C.                                                                                                                                                                                                    |
| 4mm x 80mm  Carbon Fibre Tube   | 1     | For the damper / spring assembly.                                                                                                                                                                                                                          |
| 20 ~ 22 AWG silicon Wire        |       | Assorted for assembly.                                                                                                                                                                                                                                     |
| Push/Pull Toggle Clamp          | 1     | 32MM travel model with 4 mounting holes is used in the design. It would be fairly trivial to adapt a different model to this for hole spacing. Example can be found here: https://www.amazon.ca/KangTeer-Capacity-Plunger-Vertical-Operation/dp/B06VTCXXL1 |
| Eleastic Bands (optional)       | 4 ~ 6 | There is an option to use elastic bands as a return mechanism, if you can't print TPU, or can't source some of the material for the damper spring components. It doesn't look as good, but it works perfectly fine.                                        |
| 2020 Extrusion 300mm            | 1     | For the handle. You could use 250mm here as well to save money, but the handle will by 50mm shorter.                                                                                                                                                       |
| 2020 Extrusion 250mm            | 1     | For the desk mount. You could use 300mm here, but it will be long. If you only want to buy 1 size, that's fine, buy 300mm. I highly recommend you cut off ~50mm from the part being used for the desk mount.                                               |
| SS49E Linear Hall Effect Sensor | 1     | In theory any linear hall effect sensor should work here, but you want to make sure it's the same package size.                                                                                                                                            |
| 5x5x5mm magnets                 | 1     | This is for the hall effect sensor encoder assembly. It press fits into a rotor. The part is designed for the cheap ones, which are nominally 4.7mm cubed. You need to be able to determine north.                                                         |

## Tools:
- Hex drivers and / or allen keys.
- Soldering Iron w/ Solder & Heat Set Insert tool.
- Wire cutters and strippers.
- Optional, but a magnetic flux detector is really handy to have.
- De-burring tool, and other tools for trimming the prints.
- Hot glue gun for strain relief on the sensor.
- Small shrink tube.

---
## Printing:

All parts have been laid out for printing, in their intended orientations. Some parts need supports, some need brims, and some print as is. In addition some parts have been marked with an "[a]" ala the Voron style. This denotes a part that should be printed in an accent colour, while the other parts should be printed in a darker colour. Frankly, you can print them all in whatever colours you want, but if you're going for a similar look to my own, pick a dark primary colour, and a bright accent colour.

Talking materials, I have used a mix of ABS and PLA. For the desk mount parts, where there will be some forces applied at all times, I elected to use ABS. For everything else I have used PLA+ or just straight up PLA. Honestly, the whole thing could probably be printed in PLA+, and be plenty strong. I happen to have ABS around, and leveraged it.

| Part                                        | Requirements                                                             | Heat sets? |
| ------------------------------------------- | ------------------------------------------------------------------------ | ---------- |
| [a]-ElectronicsBayLid.stl                   |                                                                          |            |
| [a]-GearedEncoderPivot.stl                  |                                                                          | 1          |
| [a]-Handle.stl                              |                                                                          |            |
| [a]-HandleBumper.stl                        |                                                                          |            |
| [a]-IdlePivot.stl                           |                                                                          | 1          |
| [a]-HallEffectModuleV3 - Cap.stl            | With grid supports touching the build plate                              |            |
| [a]-HallEffectModuleV3 - DriveGear.stl      |                                                                          |            |
| HallEffectModuleV3 - Base.stl               |                                                                          |            |
| HallEffectModuleV3 - MagRotor.stl           | With grid supports touching the build plate                              | 1          |
| BumperFrontCover-Damper-Centre.stl          |                                                                          |            |
| BumperFrontCover-Damper-Left.stl            |                                                                          |            |
| BumperFrontCover-Damper-Right.stl           |                                                                          |            |
| BumperFrontCover-ForElastics.stl            | Optional if you're not going to use elastics or the TPU spring / damper. |            |
| DamperAssembly - Arm.stl                    | Print with brim                                                          |            |
| DamperAssembly - Lower.stl                  | With grid supports touching the build plate                              |            |
| DamperAssembly - Upper.stl                  | With grid supports touching the build plate                              |            |
| DamperAssembly - Spring - [tpu].stl         | Depending on the TPU hardness, you can vary the tension and resistance.  |            |
| LeftSidePlate.stl                           |                                                                          | 6          |
| RightSidePlate.stl                          |                                                                          |            |
| ToggleClamp2020Mount - ClampHead.stl        |                                                                          |            |
| ToggleClamp2020Mount - ToggleClampMount.stl |                                                                          |            |
| ToggleClamp2020Mount - ElasticCap.stl       | Optional if you're not going to use elastics or the TPU spring / damper. |            |

---
## Assembly:

Not the most simple assembly process, though it is not too difficult. I've broken it into sub assemblies, but first thing, install your heat sets before you start; noted in the above part print guide.

#### Handle assembly:
1. With the 300mm long extrusion, mount the "Handle Bumper" using 2 M4x6mm SHCS and 2 M4 T-Nuts. This part is directional, be sure the chamfers on the wings point downwards. The bottom of the bumper should be flush with the bottom of the extrusion.
2. For the idle pivot, and geared encoder pivots, which both have had heat sets installed from the bottom, screw in a M3x12mm SHCS into the top each, through the part, and into the heat set. This is to provide strength across the print layers of these parts.
3. Using four M4x8mm SHCS and four M4 T-nuts, mount the idler and geared encoder pivots to the sides of the extrusion. With the bumper facing you, the encoder is on the right, and the idler is on the left. Use the wings on the bumper, and the pivots, to line up the pivots on both sides of the handle extrusion.
4. Lastly mount the actual handle to the extrusion with M3x8mm SHCS and M3 T-nuts. You will need 4 of each. Pre-install the SHCS and t-nuts loosely on the handle, then line up and slide the handle onto the extrusion. You may need to sand or trim a bit to get a sliding fit here. The print is designed with very tight tolerances, so minimise and play. This step is more easily done with drop in nuts, pre positioned in the extrusion. Be sure the grip portion of the handle is facing away from the bumper side.
5. The is the handle assembly done, set it aside.

#### Hall Effect Rotary Encoder assembly:
1. First things first, ensure the cap fits the body, and ensure the gear fits onto the rotor. There should be a little play with both, just a tiny bit.
2. Press a bearing into the encoder base. You can use the rotor part to help seat it. Be sure it is fully seated before moving on.
3. With the rotor, which has a single heat set insert installed from the side that engages the gear (top side on the build plate), you need to install the magnet. On the face of the rotor (the wide side) there are 2 markings. A dot, and an arrow. You need to install the magnet with north facing the arrow. This is actually important, and can be done with another magnet that has N & S clearly indicated, or with a magnetic flux polarity detector. Either way, N needs to be facing the arrow on the rotor face. This should be a snug press fit. If it's loose, well check your extrusion multiplier, but also use a small touch of CA to make sure it's not going anywhere. Just be positive about your polarity before gluing it. BTW, the hole from the heat set goes all the way through, so you can use a small tool to push the magnet back out if needed.
4. Insert the rotor in the base through the bearing.
5. Fasten the gear to the rotor with a M3x8mm BHCS. You can use a SHCS if you want, it really doesn't make a difference in this design, but I think the BHCS looks nicer.
6. For the cap slide your SS49E into the keyed slot, passing the leads through the cap to the outside of the cap.
7. Check the data sheet 8 times, and then solder red and black wires to your positive and negative legs, then a yellow or white, or whatever different wire to the sensor output leg. You want to use wires about 6 inches long, so you have some play to trim them to size later. Make sure you strip back a significant amount of wire to solder to the legs. Use shrink wrap to get the bulk of the legs and wire insulated.
8. Press the sensor into the cap from the inside as far as it will go, should be flush, and bend the legs and wires into the channel on the top of the cap. Be sure nothing is touching or shorting before you proceed here. If you did the shrink tube correctly, this should be no problem. With the sensor pressed all the way into the cap, and the legs bent and formed to the cap, use hot glue to secure the wires to the cap. Looking at the cap from the top, with the legs and wires pointing down, bend the legs and wires to the right of the cap as they leave the small channel section before you glue them. You want to cover the flat of the cap in layer of glue to properly secure the sensor and the wires. 
9. That's it for the Hall Sensor for now.

#### Toggle Clamp Table Mount:
1. Preload the four M4 nuts in the clamp mount, as well as the four M4x8mm SHCS with the M4 T-nuts.
2. Afix to a side of your 250mm 2020 extrusion (if you used two 300mm, that is fine, but I really recommend you chop off 50mm) with the T-Nuts you preloaded in the last step.
3. Insert the four M3 nuts into clamp head, and install the two M3x50mm and two M3x35mm screws to strengthen the head against the layer lines. Do not over tighten them. Add four M4x8mm SHCS along with four M4 T-nuts.
4. Mount the clamp head on the same side of the clamp mount, with the top flush with the extrusion. Secure with the T-nuts you preloaded in the last step.
5. Place the toggle clamp on the clamp mount, and secure with M4x16mm screws. Use the M4 washers on this step.
6. Place the elastic cap over the top of the extrusion on the opposite side from the clamp head, and secure with a M3x8mm BHCS or SHCS and a M3 T-nut.
7. The table mount is now assembled. You can tweak the placement of the clamp mount to adjust the range for the toggle clamp. The toggle clamp itself uses a bolt and jam nut to fine tune the fit. You want the toggle to require some force to clamp, but not a huge amount of force. Tweak this now to ensure the fit for your desk / table is good. (NOTE: at some point I intend to design TPU bumpers for the toggle clamp side, and the clamp head side, to protect your desk/ table.)

#### Side Plate Prep:
1. You have some minor things you should take care of before moving forward. On the left and right side plates, press in the bearing. Load two M3 nuts onto the left or right side plate; I suggest the right side. Load M4x16mm SHCS with T-nuts for both side plates for mounting to the 2020 extrusion shortly.
2. On the right plate you will have installed 6 M3 heat set inserts. If you haven't, get that done now. 4 for the electronics bay, and 2 for the encoder mount.
3. Prep your cherry mx style keyswitch by soldering ~100mm of wire to each contact leg. Heat shrink each joint. You want to be fairly quick with the soldering, as you can melt the plastic housing of the switch.
4. Insert the switch into the right side plate. Orient it so the wires are closest to the back edge where it will mount to the 2020 extrusion of the desk mount. At this point confirm the switch is working using a digital multi meter. Beyond this point it becomes harder to proceed, so double check this before you move on.

#### Arduino Assembly:
1. On the right side plate, place the arduino into the pocket just for it. You are going to be connecting the red, black, and output leads from your hall effect encoder to the arduino. 
2. Take the encoder and place it on the frame. The cap is going to be installed with the wires facing the back of the plate, aka the mounting for the 2020 extrusion. Use a couple of M3 screws to roughly align it now, and trim your wires so they are the right length to hit VCC, GND, and A1 along the one side of the arduino. 
3. Do the same for the keyswitch button which will attach to the opposite side of the arduino pro micro, at digital pin 2 and GND. 
4. Solder your wires through hole such that the wires are poking out the top of the arduino board.
5. At this point, put the arduino in it's place, neatly route your wires, and install the electronics bay cover with four M3x8mm BHCS. Be careful to not pinch any of the wires with the cover. There is plenty of room for some slack in the wires; nothing should be tight or even taught.
6. Pull the screws out of the encoder assembly, and leave the cap off to the side, while you remove the rest of the assembly.

#### Final assembly:
1. Take the right plate, and lay it down flat.
2. Insert the handle's geared encoder pivot into the bearing. It should sit flush to the outside of the plate.
3. Take the hall effect rotary encoder body with the rotor and gear installed, and line it up with the mounting position.
4. This next part is critical to the function of your encoder. Previously we went to some trouble to get the North polarity aligned precisely in the rotor, which has 2 marks on it; an arrow, and a dot. The geared pivot also has a small arrow marked on it that will be visible from the inside. You want to align the dot on the rotor with the arrow on the geared pivot. The gears are designed to make this perfect. The handle should be at the mid point of it's travel, 15 degrees up and down, and then align the rotor to the arrow on the pivot, and mesh the gear on the rotor with the geared pivot. Confirm it is engaging the geared pivot by rotating the handle a little back and forth. At this stage you can add a small amount of white lithium grease to the gear teeth on the pivot if you like; I don't think you need it, but it can't hurt.
5. Once that is all aligned, place the cap over top of the base, wires pointing away from the geared pivot and handle, and use two M3x16 BHCS or SHCS screws to secure the encoder assembly to the right plate. This effectively locks the handle in place now, though it can be rotated too far to free it accidentally at this stage. Don't do that. If the geared pivot rotates outside of it's range, and is no longer meshing with the gear on the encode, you need to take it apart and align everything again as in step 4.
6. With the right plate still flat on a table, the handle installed, take the left plate and place it over the idle pivot, aligned with the right plate. You either have a single piece front cover/ bumper, or a 3 piece one, depending on if you're going with elastic bands or the TPU spring / damper. For the single piece, this is super easy, but for the 3 piece version is a little harder. Pay attention for the next coupe of steps. NOTE: once you have installed the front part, the handle's rotation will now be constrained to it's correct range of motion, and you don't need to worry about it disconnecting from the hall effect encoder.
7. For the single piece front, put it in place, and run your M3x50mm screws through the left plate, the front piece, and screw them into the right plate. Don't hulk out, evenly snug if what you want. Genuinely easy to install this part.
8. For the 3 piece front, if you're using the TPU spring damper, you want to do the following:
	1. Lay the left and right sides down, with the M3 nut recess up. Load the M3 nuts, one in each side.
	2. The M3 nuts go towards the inside, run one of your M3x50mm screws through the whole stack, I suggest the bottom holes. This will align everything correctly, and make it very easy to install.
	3. Insert the stack partly between the left and right plates. Line up the top hole for the M3x50mm bolt, and run it all the way through and lightly thread it in.
	4. Pull out the M3x50mm you used for your alignment of the stack, and rotate the bottom into position, and re-use the same M3x50mm bolt to secure the bottom.
	5. Ensure you have made them snug, with even tension across both M3 screws.
9. At this point everything should be well aligned, and you can move the handle through it's range of motion to ensure everything is lined up and moving freely. It should move with minimal effort, and not run against the electronics cover. If it binds, or rubs, gently loosen the two M3x50mm bolts, do the plates can move a little.
10. Slide the 2020 extrusion of the desk mount into the mounting area of the left and right plates. Lightly snug the M4 SHCS's to mostly secure the handbrake to the mount. Confirm everything moves freely, without rubbing. Tighten the M4 SHCS's on the 2020 extrusion, and snug up the M3x50mm SHCS's if you loosened them in the last step.
11. Confirm everything is moving smoothly, and adjust the plates if needed.

#### Elastic Bands?:
1. If you're going with elastic bands, take 2 or more standard elastic bands and double them over themselves, pull it over the handle to a point opposite the elastic band cap on the mount. 
2. Loop the bands around the cap, into the notch modeled for them. 
3. You can add or remove bands to adjust the tension.
4. You're done fully at this point, and can move on to software.

#### TPU Spring / Damper:
1. Using a pair of M3x12mm SHCS or BHCS, thread them through either side of the front plate into the M3 nuts you preloaded earlier. Just so the threads are starting to stick out.
2. Take the damper lower, and align the holes on the side of it with the 2 screws. Tighten the screws down so that the screws go into the damper lower part. The M3 nuts take up all the force, while the screws act as the pivot for the lower damper part.
3. With the damper arm, use two M4x8mm SHCS and two T-nuts to secure the damper arm to the handle. The bottom of the arm should be touching the handle bumper plate when you tighten it on.
4. With the upper, which you need to have installed a M3 heat set insert into the from boss / hole, insert your 4mm carbon fibre tube into the bottom until it hits the top of the upper mount. Use a M3x10mm BHCS or SHCS to secure the carbon tube. You can also use a M3x12mm BHCS or SHCS with a couple of M3 washers to do the same job. Load the M4 nut into the side of the upper mount at this time.
5. Slide your TPU spring over the carbon rod, and seat in the recess of the upper mount. Make sure it compresses freely before moving on. NOTE: the TPU spring will only fit in one orientation, this is intentional.
6. Slide the carbon rod into the lower mount now, and line up the TPU spring into the recess of the lower mount.
7. Compress the TPU spring by press on the upper mount, and slid it into place at the end of the damper arm. Slide a M4x20mm SHCS through the upper mount and arm, and gently tighten. Do not make this tight, the M4 nut is just to retain the M4x20mm SHCS. You do not want to introduce binding into the pivot.
8. Confirm the handle moves through it's full range, and nothing binds. It should be fairly smooth.

Congrats, your handbrake is assembled and mostly ready to go.

---
## Software:

This part is pretty easy. Grab the joystick library from here and install it into your Arduino IDE: https://github.com/MHeironimus/ArduinoJoystickLibrary

Once that is set up, you just need to flash the arduino sketch provided to your arduino using Arduino IDE. Once it's flashed, unplug it and plug it back in again, and you should be good to go. 

Open the USB game devices dialog, or something like GTK Joystick test, to confirm it's exposed a single axis and button, and the axis works. The button does nothing. I found that I had to add a single button to the definition of the joystick to make it work with Windows for some reason. With just an analog axis I found that Windows refuses to recognise it as a game device, though Linux had no such issues.

I implemented a really basic auto calibration routine, so every time you plug your handbrake in, move it through it's full range of motion, and it will automatically calibrate perfectly. It also adds a tiny amount of dead zone to both ends of it's range, as well as sampling the reading from the sensor 10 times before updating the position. That means that in general it should behave smoothly, and you should never need to calibrate it. 

If you find it drifts a little for some reason, press that key switch on the side to reset the auto calibration data. I found on early versions I needed that functionality, however I have played for hours with the current iteration, and have not found a need to use it since I added the tiny dead zone and sample averaging the reading from the sensor.

---

Your handbrake is now complete. I've used it in BeamNG, Assetto Corsa, Dirt Rally games, Project Cars series, and it has been a really nice addition over just hitting a digital button on my steering wheel.
