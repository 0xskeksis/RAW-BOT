#-------------------------------------------------------------------------------#
#							POC-arm_bootloader								    #
#-------------------------------------------------------------------------------#

TARGET			:= boot
BIN				:= $(TARGET).bin
ELF				:= $(TARGET).elf

ASM_SRC			:= src/startup.s
C_SRC			:= src/main.c

ASM_OBJ			:= $(ASM_SRC:.s=.o)
C_OBJ			:= $(C_SRC:.c=.o)

CC				:= arm-none-eabi-gcc
OBJCOPY			:= arm-none-eabi-objcopy

LD_SCRIPT		:= linker.ld

CFLAGS			:= -mcpu=cortex-m4 -mthumb -ffreestanding -g -Wall -Wextra -O0
ASFLAGS			:= $(CFLAGS)
LDFLAGS			:= -nostdlib -nostartfiles -nodefaultlibs -T $(LD_SCRIPT)

OBJCOPY_FLAGS	:= -O binary

#-Rules------------------------------------------------------------------------#

all: $(BIN)

$(ASM_OBJ): $(ASM_SRC)
	$(CC) $(ASFLAGS) -c $< -o $@

$(C_OBJ): $(C_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(ELF): $(ASM_OBJ) $(C_OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(BIN): $(ELF)
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

clean:
	rm -f $(ASM_OBJ) $(C_OBJ) $(ELF) $(BIN)

re: clean all

#-------------------------------------------------------------------------------#
