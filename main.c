/*Robot Racer main.c

//Robot Racer Program
//Author: Christopher Boulanger
//Created: 6 December 2013
//Description: This program implements the open-space, collision-avoidance navigation algorithm to travel through the maze.
 * */


#include <msp430.h> 
#include "robot.h"
#include "sensor.h"


unsigned int leftSensorVoltage, rightSensorVoltage, middleSensorVoltage;
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;        // Stop watchdog timer

   initializeMotor();
   initializeADC10();

   P1DIR |= BIT0;
   P1DIR |= BIT6;

for (;;){
        leftSensorVoltage=getLeftSensorVoltage();
        rightSensorVoltage=getRightSensorVoltage();

        if(leftSensorVoltage > LEFTDISTANCE){
                P1OUT &= ~BIT0;
                moveRobot(SMALLLEFT);

        }
//        else{
//                P1OUT |= BIT0;
//                moveRobot(FORWARD);
//        }
        else if(rightSensorVoltage>RIGHTDISTANCE){
                P1OUT &= ~BIT6;
                moveRobot(SMALLRIGHT);

        }
        else{
                P1OUT |= BIT6;
               // moveRobot(FORWARD);
                TA0CCR1 = 20;
                TA1CCR1 = 23;
                TA1CCR2 = 0;
        }

       middleSensorVoltage=getMiddleSensorVoltage();

                  	  	if(middleSensorVoltage>MIDDLEDISTANCE){
                               // P1OUT &= ~BIT6;
                                //P1OUT &= ~BIT0;
                                moveRobot(SMALLLEFT);
                        }
//                        else{
//                                //P1OUT |= BIT6;
//                                //P1OUT |= BIT0;
//                                moveRobot(FORWARD);
//                        }

}

return 0;

}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void){
        __bic_SR_register_on_exit(CPUOFF);
}


/*int main(void) {
    WDTCTL = WDTPW | WDTHOLD;        // Stop watchdog timer

    for(;;){
            leftSensorVoltage=getLeftSensorVoltage();
            rightSensorVoltage=getRightSensorVoltage();

 //           if(leftSensorVoltage < SMALLLEFTDISTANCE){
 //                   moveRobot(BIGRIGHT)
 //           }
            /*else*/ /*if (leftSensorVoltage < LEFTDISTANCE){
                    moveRobot(SMALLRIGHT);
            }
            if (rightSensorVoltage < RIGHTDISTANCE){
                    moveRobot(SMALLLEFT);
            }
            else{
                    moveRobot(FORWARD);
            }
    }
        return 0;
}*/
