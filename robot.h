/*Robot Racer robot.h

//Robot header file
//Author: Christopher Boulanger
//Created: 15 November 2013
 * Edited: 9 December 2013
//Edits: Made program more user-friendly by adding RIGHTSPEED and LEFTSPEED
 * I did this because the hardware for my particular robot veered to the LEFT.
 * By making the Right motor speed less than the Left motor speed this problem can be fixed.
 * The robot will now go straight.
 * */


#ifndef ROBOT_H_
#define ROBOT_H_

#define RIGHTSPEED 15		//Right MOTOR speed
#define LEFTSPEED 15 	//Left MOTOR speed
#define DELAYWOBBLE 10000	//ability to change delay between motor pulses

#define STOP                1
#define FORWARD             2
#define BACKWARD        	3
#define BIGRIGHT      		4
#define SMALLRIGHT          5
#define BIGLEFT             7
#define SMALLLEFT           8

void initializeMotor();

void moveRobot(unsigned char direction);

#endif /* ROBOT_H_ */
