#include <stdint.h>

#ifndef STACK_H
#define STACK_H
    
#define TASK_STACK_SIZE       1024U //0x400 
#define SCHED_STACK_SIZE      1024U

#define SRAM_START            0x20000000U
#define SRAM_SIZE             ((128) * (1024))
#define SRAM_END              ((SRAM_START) + (SRAM_SIZE)) //0x20020000

#define TASK1_STACK           SRAM_END
#define TASK2_STACK           ((SRAM_END) - (TASK_STACK_SIZE))
#define TASK3_STACK           ((TASK2_STACK) - (TASK_STACK_SIZE))
#define TASK4_STACK           ((TASK3_STACK) - (TASK_STACK_SIZE))
#define SCHED_STACK           ((TASK4_STACK) - (SCHED_STACK_SIZE)) //0x2001f000

#define MAX_TASKS 4
#define DUMMY_XPSR 0x00100000

void initSchedulerStack(uint32_t top_of_stack);
void initTasks(void);

typedef struct
{
    uint32_t psp_value;
    uint32_t block_count;
    uint8_t current_state;
    void(*task_handler)(void);
}TCB_t;

class Task
{
    private:
        uint32_t psp_value;
        uint32_t block_count;
        uint8_t current_state;
    public:
        Task(uint32_t psp, uint32_t b_count, uint8_t curr_state);
        void taskHander(void);
};

#endif
