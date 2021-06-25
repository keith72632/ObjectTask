#include <cstdint>
#include <stdio.h>
#include "stack.h"

TCB_t userTasks[MAX_TASKS];
void taskOneHandler();
void taskTwoHandler();
void taskThreeHandler();
void taskFourHandler();

void (*taskHandlers[])() = {
    taskOneHandler,
    taskTwoHandler,
    taskTwoHandler,
    taskFourHandler
};

uint32_t stacks[] = {
    TASK1_STACK,
    TASK2_STACK,
    TASK3_STACK,
    TASK4_STACK,
};


void initSchedulerStack(uint32_t top_of_stack)
{
    __asm volatile("MSR MSP,%0":: "r"(top_of_stack):);
    __asm volatile("BX LR");
}

void initTasks()
{
    for(int i = 0; i < MAX_TASKS; i++)
    {
        userTasks[i].psp_value = stacks[i];
        userTasks[i].current_state = 0;
        userTasks[i].task_handler = taskHandlers[i];
    }

    uint32_t *pPSP;
    for(int i = 0; i < MAX_TASKS; i++)
    {
        pPSP = (uint32_t*)userTasks[i].psp_value;
        
        pPSP--; //XPSR

        *pPSP = DUMMY_XPSR;
        
        pPSP--; //PC

        *pPSP = (uint32_t)userTasks[i].task_handler;

        pPSP--; //LR
        
        *pPSP = 0xFFFFFFFD;

       for(int j = 0; j < 13; j++)
       {
            pPSP--;
            *pPSP = 0;
       } 

       userTasks[i].psp_value = (uint32_t)pPSP;
    }
}

void taskOneHandler(){};
void taskTwoHandler(){};
void taskThreeHandler(){};
void taskFourHandler(){};

/* C++ */
Task::Task(uint32_t psp, uint32_t b_count, uint8_t curr_state)
{
    this->psp_value = psp;
    this->block_count = b_count;
    this->current_state = curr_state;
}

void Task::taskHander(void)
{
    while(1)
    {
        //put code here
    }
}
