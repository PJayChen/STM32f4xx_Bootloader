PROJECT = Bootloader

EXECUTABLE = $(PROJECT).elf
BIN_IMAGE = $(PROJECT).bin
HEX_IMAGE = $(PROJECT).hex
MAP_FILE = $(PROJECT).map

#FreeRTOS kernel source
FREERTOS ?= ./Libraries/freeRTOS

# set the path to STM32F4xx firmware package
STDP ?= ./

#source code and include path
SOURCE ?= ./src
INCLUDE ?= ./inc

# Toolchain configurations
CROSS_COMPILE ?= arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
SIZE = $(CROSS_COMPILE)size

# Cortex-M4 implements the ARMv7E-M architecture
CPU = cortex-m4
CFLAGS = -mcpu=$(CPU) -march=armv7e-m -mtune=cortex-m4
CFLAGS += -mlittle-endian -mthumb
# FPU
CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=softfp

#LDFLAGS =
#define get_library_path
#    $(shell dirname $(shell $(CC) $(CFLAGS) -print-file-name=$(1)))
#endef
#LDFLAGS += -L $(call get_library_path,libc.a)
#LDFLAGS += -L $(call get_library_path,libgcc.a)

# Basic configurations
CFLAGS += -g -std=c99
CFLAGS += -Wall

# Optimizations
CFLAGS += -O1 -ffast-math
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -Wl,--gc-sections
CFLAGS += -fno-common
CFLAGS += --param max-inline-insns-single=1000

# FPU
CFLAGS += -DARM_MATH_CM4 -D__FPU_PRESENT

# specify STM32F407
CFLAGS += -D STM32F40_41xxx

# to run from FLASH
CFLAGS += -DVECT_TAB_FLASH

#---------------- Linker Options ----------------
#  -Wl,...:     tell GCC to pass this to linker
#    -Map:      create map file
#    --cref:    add cross reference to  map file
LDFLAGS = -lm
LDFLAGS += -Wl,-Map=$(PROJECT).map,--cref
LDFLAGS += -Wl,--gc-sections
LDFLAGS += -T ./linkscript/stm32_flash.ld
LDFLAGS += -mcpu=cortex-m4 -march=armv7e-m -mtune=cortex-m4 -mlittle-endian -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp

# project starts here
CFLAGS += -I $(INCLUDE)
OBJS = \
    $(SOURCE)/main.o \
    $(SOURCE)/system_stm32f4xx.o

#hardware configure
#CFLAGS += -I $(INCLUDE)
OBJS += $(SOURCE)/hw_it.o \
	$(SOURCE)/hw_conf.o

#String, USART...
OBJS += $(SOURCE)/myio.o \
	$(SOURCE)/String.o 

# STARTUP FILE
OBJS += $(SOURCE)/startup_stm32f4xx.o
#OBJS += $(SOURCE)/startup_stm32f429_439xx.o

# CMSIS
CFLAGS += -I$(STDP)/Libraries/CMSIS/Device/ST/STM32F4xx/Include
CFLAGS += -I$(STDP)/Libraries/CMSIS/Include
#LIBS += $(STDP)/Libraries/CMSIS/Lib/GCC/libarm_cortexM4lf_math.a

# STM32F4xx_StdPeriph_Driver
CFLAGS += -DUSE_STDPERIPH_DRIVER
CFLAGS += -I$(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/inc
CFLAGS += -D"assert_param(expr)=((void)0)"
OBJS += \
    $(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/src/misc.o \
    $(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.o \
    $(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.o \
    $(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.o \
    $(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.o \
    $(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.o \
    $(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_ltdc.o \
    $(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.o \
    $(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.o \
    $(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.o \
    $(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.o \
    $(STDP)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.o

# FreeRTOS kernel
CFLAGS += -I$(FREERTOS)/include
CFLAGS += -I$(FREERTOS)

OBJS += \
    $(FREERTOS)/list.o \
    $(FREERTOS)/tasks.o \
    $(FREERTOS)/queue.o \
    $(FREERTOS)/timers.o \
    $(FREERTOS)/port.o \
    $(FREERTOS)/MemMang/heap_1.o

all: $(BIN_IMAGE)

$(BIN_IMAGE): $(EXECUTABLE)
	$(OBJCOPY) -O binary $^ $@
	$(OBJCOPY) -O ihex $^ $(HEX_IMAGE)
	$(OBJDUMP) -h -S -D $(EXECUTABLE) > $(PROJECT).lst
	$(SIZE) $(EXECUTABLE)
	
#$(EXECUTABLE): $(OBJS)
#	$(LD) -o $@ $(OBJS) \
#		--start-group $(LIBS) --end-group \
#		$(LDFLAGS)

# Link: create ELF output file from object files
.SECONDARY: $(EXECUTABLE).elf
.PRECIOUS:  $(OBJS)
$(EXECUTABLE): $(OBJS)
	@echo
	@echo Linking: $@
	$(CC) $^ $(LDFLAGS) --output $@ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXECUTABLE)
	rm -rf $(BIN_IMAGE)
	rm -rf $(HEX_IMAGE)
	rm -f $(OBJS)
	rm -f $(PROJECT).lst
	rm -f $(MAP_FILE)

flash:
	openocd -f interface/stlink-v2.cfg \
		-f target/stm32f4x_stlink.cfg \
		-c "init" \
		-c "reset init" \
		-c "halt" \
		-c "flash write_image erase $(PROJECT).elf" \
		-c "verify_image $(PROJECT).elf" \
		-c "reset run" -c shutdown || \
	st-flash write $(BIN_IMAGE) 0x8000000

st_flash:
	st-flash write $(BIN_IMAGE) 0x8000000
.PHONY: clean
