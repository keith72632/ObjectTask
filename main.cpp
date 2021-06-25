#include <stdio.h>
#include <cstdint>
#include "led.h"
#include "stack.h"

extern "C" void initialise_monitor_handles(void);
void softDelay(int rounds);
//void initSchedulerStack(uint32_t top_of_stack);

int main()
{
    initialise_monitor_handles();
    printf("Hello World\n");

    initSchedulerStack(SCHED_STACK);
    register uint32_t *msp __asm("sp");
    printf("Stack initialized: %p\n", msp);

    initTasks();
    printf("Task Stacks Initalized\n");

    GpioPin D('D', 12, OUTPUT);

    while(1)
    {
        D.ledOn();

        softDelay(1000);

        D.ledOff();

        softDelay(1000);    
    };
    
    return 0;
}

void softDelay(int rounds)
{
    for(int i = 0;i <= (rounds * 1000); i++){};
}
/*
void initSchedulerStack(uint32_t top_of_stack)
{
    __asm volatile("MSR MSP, %0":: "r"(top_of_stack):);
    __asm volatile("BX LR");
}
*/
