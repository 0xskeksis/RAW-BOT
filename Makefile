#-------------------------------------------------------------------------------#
#																			    #
#							POC-arm_bootloader								    #
#																			    #
#-------------------------------------------------------------------------------#

#-Variables---------------------------------------------------------------------#

TARGET			:= boot
BIN				:= $(TARGET).bin
ELF				:= $(TARGET).elf

ASM_SRC			:= src/startup.s
C_SRC			:= src/main.c

LINKER			:= arm-none-eabi-gcc
LD_SCRIPT		:= linker.ld

ASM_OBJ			:= $(ASM_SRC:.s=.o)
C_OBJ			:= $(C_SRC:.c=.o)

CC				:= arm-none-eabi-gcc

OBJCOPY			:= arm-none-eabi-objcopy

OBJCOPY_FLAGS 	:= -O binary	
																			
CFLAGS 			:= -mcpu=cortex-m4 -mthumb -ffreestanding -nostdlib -g

CFLAGS 			+= -nostartfiles

#-Rules------------------------------------------------------------------------#

all:$(BIN)

$(ASM_OBJ): $(ASM_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(C_OBJ): $(C_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(ELF): $(ASM_OBJ) $(C_OBJ)
	$(LINKER) -T $(LD_SCRIPT) -o $@ $^

$(BIN): $(ELF)
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

clean:
	rm -f $(ASM_OBJ) $(ELF) $(BIN)

#------------------------------------------------------------------------------#
