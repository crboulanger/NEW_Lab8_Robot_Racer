/*Robot Racer robot.c

//Robot Racer implementation program
//Author: Christopher Boulanger
//Created: 19 November 2013
 * Edited: 9 December 2013
//Description: This program implements motor initializations and the pulse width modulation required for varying speeds.
 * */


#include "robot.h"
#include <msp430.h>

void initializeMotor(){
                P1DIR |= BIT2;
                P1SEL |= BIT2;
                P2DIR |= BIT1|BIT4;
                P2SEL |= BIT1|BIT4;

                TA0CTL &= ~MC1|MC0;                        // stop timer A0
                TA1CTL &= ~MC1|MC0;

                TA0CTL |= TACLR;                        // clear timer A0
                TA1CTL |= TACLR;

                TA0CTL |= TASSEL1;                        // configure for SMCLK
                TA1CTL |= TASSEL1;

                TA1CCR0 = 60;
                TA0CCR0 = 60;

                TA0CCR1 = RIGHTSPEED;
                TA1CCR1 = RIGHTSPEED;
                TA1CCR2 = RIGHTSPEED;

                TA0CCTL1 |= OUTMOD_7;                // set to RESET/SET mode
                TA1CCTL1 |= OUTMOD_7;

                TA0CTL |= MC0;                                // set to count up
                TA1CTL |= MC0;
}


void moveRobot(unsigned char direction){
        switch (direction){

        case STOP:
                        P1DIR |= BIT2;        //I reset the bits each time because backwards requires a different bit set configuration
                    P1SEL |= BIT2;
                    P2DIR |= BIT1|BIT4;
                    P2SEL |= BIT1|BIT4;

                    TA1CCR1 = 0;        //no duty cycle>>no movement
                TA0CCR1 = 0;
                TA1CCR2 = 0;
                break;

        case FORWARD:
                        P1DIR |= BIT2;
                    P1SEL |= BIT2;
                    P2DIR |= BIT1|BIT4;
                    P2SEL |= BIT1|BIT4;

                TA0CCR1 = LEFTSPEED;        //the left wheel is faster in code because
                TA1CCR1 = RIGHTSPEED;        //for some reason my robot's right motor goes faster in real life.
                TA1CCR2 = 0;
                break;

        case BACKWARD:
                    P2DIR &= ~BIT4;
                    P2SEL &= ~BIT4;

                    TA1CCR1 = 0;
                TA0CCR1 = 0;
                TA1CCR2 = RIGHTSPEED;
                break;

        case BIGRIGHT:
                        P1DIR |= BIT2;
                    P1SEL |= BIT2;
                    P2DIR |= BIT1|BIT4;
                    P2SEL |= BIT1|BIT4;

                TA1CCR1 = RIGHTSPEED;
                TA0CCR1 = 0;
                TA1CCR2 = 0;
                _delay_cycles(400000);
                TA0CCR1 = LEFTSPEED;
                break;

        case SMALLRIGHT:
                        P1DIR |= BIT2;
                    P1SEL |= BIT2;
                    P2DIR |= BIT1|BIT4;
                    P2SEL |= BIT1|BIT4;

                TA1CCR1 = RIGHTSPEED*2.5;
                TA0CCR1 = 0;
                TA1CCR2 = 0;
                _delay_cycles(DELAYWOBBLE);
                TA0CCR1 = LEFTSPEED/15;
                break;

        case BIGLEFT:
                        P1DIR |= BIT2;
                    P1SEL |= BIT2;
                    P2DIR |= BIT1|BIT4;
                    P2SEL |= BIT1|BIT4;

                TA0CCR1 = LEFTSPEED*2.5;
                TA1CCR1 = 0;
                TA1CCR2 = 0;
                _delay_cycles(DELAYWOBBLE);
                TA1CCR1 = RIGHTSPEED/5;
                break;

        case SMALLLEFT:
                        P1DIR |= BIT2;
                    P1SEL |= BIT2;
                    P2DIR |= BIT1|BIT4;
                    P2SEL |= BIT1|BIT4;

                TA0CCR1 = LEFTSPEED*2.5;
                TA1CCR1 = 0;
                TA1CCR2 = 0;
                _delay_cycles(DELAYWOBBLE);
                TA1CCR1 = RIGHTSPEED/5;
                break;
        }
}


