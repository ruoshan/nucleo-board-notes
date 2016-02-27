PREFIX := arm-none-eabi
CCFLAGS := -Wall -Iinc -mcpu=cortex-m4 -mlittle-endian -mthumb -g
ASFLAGS := -mcpu=cortex-m4 -mlittle-endian -mthumb -g
LDFLAGS := ${ASFLAGS} -Tld/STM32F401RE_FLASH.ld --specs=nosys.specs

build: hex

hex: all
	${PREFIX}-objcopy -Oihex main.elf main.hex

all: main.o system.o startup.o
	${PREFIX}-gcc ${LDFLAGS} main.o system.o startup.o -o main.elf

main.o: main.c
	${PREFIX}-gcc ${CCFLAGS} -DSTM32F401xE -c $< -o $@

system.o: sys/system_stm32f4xx.c
	${PREFIX}-gcc ${CCFLAGS} -DSTM32F401xE -c $< -o $@

startup.o: asm/startup_stm32f401xe.s
	${PREFIX}-as ${ASFLAGS} -c $< -o $@

.PHONY: clean

clean:
	rm -vf *.o main.elf main.hex
