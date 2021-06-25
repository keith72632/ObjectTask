CPP=/home/keith/Tools/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-g++
CC=/home/keith/Tools/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
CPPFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -fno-exceptions -fno-rtti -Wall -O0
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T linker.ld -Wl,-Map=final.map
LDFLAGS_SH= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T linker.ld -Wl,-Map=final.map
CSOURCE = $(wildcard *.c)
CPPSOURCE = $(wildcard *.cpp)
COBJS = $(CSOURCE:.c=.o)
CPPOBJS = $(CPPSOURCE:.cpp=.o)
HEADER = $(wildcard *.h)

all:$(CPPOBJS) $(COBJS) final.elf

semi:main.o startup.o led.o stack.o final_sh.elf

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf: $(CPPOBJS) $(COBJS) 
	$(CC) $(LDFLAGS) -o $@ $^ 
	
final_sh.elf: main.o startup.o led.o stack.o
	$(CC) $(LDFLAGS_SH) -o $@ $^

clean:
	rm -rf *.o *.elf

load:
	 openocd -f /usr/share/openocd/scripts/board/stm32f4discovery.cfg -f /usr/share/openocd/scripts/interface/stlink-v2-1.cfg -c "stm32f4x.cpu configure -rtos ChibiOS"
	
debug:
	/home/keith/Tools/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gdb
