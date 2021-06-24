#include <stdio.h>
#include "led.h"

extern "C" void initialise_monitor_handles(void);

int main()
{
    initialise_monitor_handles();
    printf("Hello World\n");

    GpioPin D('D', 12, OUTPUT);
    D.ledOn();

    while(1);
    
    return 0;
}
