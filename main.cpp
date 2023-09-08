#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    gpio_t gasDetector, overTempDetector, alarmOffButton, alarmLED;

    gpio_init_in_ex(&gasDetector, D2, PullDown);     //DigitalIn gasDetector(D2); gasDetector.mode(PullDown);
    gpio_init_in_ex(&overTempDetector, D3, PullDown);//DigitalIn overTempDetector(D3); overTempDetector.mode(PullDown);
    gpio_init_in(&alarmOffButton, BUTTON1);          //DigitalIn alarmOffButton(BUTTON1);
    
    gpio_init_out(&alarmLED,LED1);
    DigitalOut alarmLed(LED1);


    alarmLed = OFF;

    bool alarmState = OFF;

    while (true) {

        if ( gpio_read(&gasDetector) || gpio_read(&overTempDetector) ) {
            alarmState = ON;
        }

        alarmLed = alarmState;

        if ( gpio_read(&alarmOffButton) ) {
            alarmState = OFF;
        }
    }
}