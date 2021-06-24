#include "led.h"
GpioPin::GpioPin(char pinLet, int pinNum, int mode)
{
    pinLetter = pinLet;
    int pin;
    switch(pinLet)
    {
        case 'A':
            pin = 0;
            break;
        case 'B':
            pin = 1;
            break;
        case 'C':
            pin = 2;
            break;
        case 'D':
            pin = 3;
            break;
        default:
            break;
    }
    pinNumber = pinNum;
    *pRccAhb1Enr &= ~(0xffffffff);    
    *pRccAhb1Enr |= (1 << pin);

    *pGpioModeD |=  (mode << (2 * pinNum));
};

void GpioPin::ledOn()
{
    *pGpioDataD |= (1 << pinNumber);
}

void GpioPin::ledOff()
{
    *pGpioDataD |= ~(1 << pinNumber);
}

GpioPin::~GpioPin(){};
