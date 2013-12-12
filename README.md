Robot Racer Library
==============

##Welcome!

This is the repository for my Robot maze navigation program.

This program combines my sensor libraries and motor pulse-width modulation libraries.

Together the robot will execute a left-wall following algorithm to navigate through the maze.

To make the sensors detect further differences:

- Decrease the value in LEFTDISTANCE/ RIGHTDISTANCE located in the sensor.h header file.

- Larger numbers relate to closer distances.
- Smaller numbers relate to further distances.

Here are some reference values to help you out:

- 0x230~~ 3.5 inches
- 0x200~~ 4.0 inches
- 0x175~~ 4.5 inches
- 0x150~~ 7.0 inches
- 0x125~~ 10  inches
- 0x100~~ 15  inches
- 0x075~~ 17  inches

-- Remember, depending on the sensor, different voltages correspond to different voltages.
-- Additionally, different voltages correspond to different lighting and wall/surface conditions.

To make the robot go faster/ slower:

- Change the values in LEFTSPEED/ RIGHTSPEED

- Larger numbers increase the P_W modulation
- Smaller numbers decrease the P_W modulation

### Remember, keep the robot close to the left wall by increasing the LEFTDISTANCE value and making RIGHTSPEED>LEFTSPEED.

See Lab8_Robot_Racer to see first commits and initial program

Refer to comments if you have questions.

###Have Fun!
