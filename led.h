#include <stdint.h>

#define INPUT   0x00
#define OUTPUT  0x01
class GpioPin
{
    private:
        uint32_t *pRccAhb1Enr   = (uint32_t *)0x40023830;
        uint32_t *pGpioModeA    = (uint32_t *)0x40020000;
        uint32_t *pGpioModeB    = (uint32_t *)0x40020400;
        uint32_t *pGpioModeC    = (uint32_t *)0x40020800;
        uint32_t *pGpioModeD    = (uint32_t *)0x40020C00;
        uint32_t *pGpioModeE    = (uint32_t *)0x40021000;
        uint32_t *pGpioModeF    = (uint32_t *)0x40021400;
        uint32_t *pGpioModeG    = (uint32_t *)0x40021800;
        uint32_t *pGpioModeH    = (uint32_t *)0x40021C00;
        uint32_t *pGpioModeI    = (uint32_t *)0x40022000;
        uint32_t *pGpioModeJ    = (uint32_t *)0x40022400;
        uint32_t *pGpioModeK    = (uint32_t *)0x40022800;

        uint32_t *pGpioDataD    = (uint32_t *)(0x40020C00 + 0x14);
        char pinLetter;
        int pinNumber;
    public: 
        GpioPin(char pinLet, int pinNum, int mode);
        void ledOn();
        void ledOff();
        ~GpioPin();
};


