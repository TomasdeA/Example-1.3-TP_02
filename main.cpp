/**
 * @brief Al ejemplo de ARM https://github.com/armBookCodeExamples/example_1-3
 *  
 * @arg none
 * @param gasDetector El pin al que se conecta el sensor de gas (ahora un switch a 3v3)
 * @param overTempDetector El pin al que se conecta el sensor de temperatura (ahora un switch a 3v3)
 * @param alarmLed El LED el cual se usa como alarma.
 * @param alarmOffButton El pin al que se conecta el botón para apagar la alarma (ahora un switch a 3v3)
 * 
 * @note Asegúrese de que esté el button/switch conectado a 3v3 y a los pines D2 y D3.
 * @note Se utiliza un pull down por ende se debe conectar a 3v3. 
 * Si se pone Pull up, conectar a GND
 * 
 * @retval none.
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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