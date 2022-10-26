#include <msp430.h>


/**
 * main.c
 */

void delay(int time){ //Is used as a delay (time is amount of time you want the delay to loop through)
    volatile long i = time;

    while(i != 0){
        i = i - 1;
    }
}

void allOn(){ //Turns all leds on pin6 bit 0-4 on
    P6OUT |= BIT0;
    P6OUT |= BIT1;
    P6OUT |= BIT2;
    P6OUT |= BIT3;
    P6OUT |= BIT4;
}
void allOff(){ //Turns all leds on pin6 bit 0-4 off
    P6OUT &= ~BIT0;
    P6OUT &= ~BIT1;
    P6OUT &= ~BIT2;
    P6OUT &= ~BIT3;
    P6OUT &= ~BIT4;
}

void redOn(){ //Turns pins 6.1 and 6.3 on
    P6OUT |= BIT1;
    P6OUT |= BIT3;
}
void blueOn(){ //Turns pins 6.0, 6.2 and 6.4 on
    P6OUT |= BIT0;
    P6OUT |= BIT2;
    P6OUT |= BIT4;
}

void trickle(int delaySpeed){ //Turns on and off pins in a "trickle" pattern
    delay(delaySpeed);
    P6OUT |= BIT0;
    delay(delaySpeed);
    P6OUT |= BIT1;
    delay(delaySpeed);
    P6OUT &= ~BIT0;
    delay(delaySpeed);
    P6OUT |= BIT2;
    delay(delaySpeed);
    P6OUT &= ~BIT1;
    delay(delaySpeed);
    P6OUT |= BIT3;
    delay(delaySpeed);
    P6OUT &= ~BIT2;
    delay(delaySpeed);
    P6OUT |= BIT4;
    delay(delaySpeed);
    P6OUT &= ~BIT3;
    delay(delaySpeed);
    P6OUT |= BIT5;
    delay(delaySpeed);
    P6OUT &= ~BIT4;
    delay(delaySpeed);
    P6OUT &= ~BIT5;


}
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // disable hihe-imedance mode

    P6DIR |= BIT0;
    P6DIR |= BIT1;
    P6DIR |= BIT2;
    P6DIR |= BIT3;
    P6DIR |= BIT4;

    int a,b,x,y,z;

    for(;;){
        for(x = 0; x <= 20; x++){ //Pattern 1
           allOn();
           delay(5000);
           allOff();
           delay(6000);
        }
        for(y = 0; y <= 10; y++){ //Pattern 2
            allOff();
            delay(5000);
            redOn();
            delay(7000);
        }
        for(z = 0; z <=10; z++){ //Pattern 3
            allOff();
            delay(5000);
            blueOn();
            delay(7000);
        }
        for(a = 0; a <= 8; a++){ //Pattern 4
            allOff();
            delay(20000);
            redOn();
            delay(10000);
            blueOn();
            delay(20000);
            allOff();
        }
        for(b = 0; b <= 3; b++){ //Pattern 4 and 5
            trickle(10000); //Pattern 4
            trickle(3000);  //Pattern 5
        }
    }
    return 0;
}
