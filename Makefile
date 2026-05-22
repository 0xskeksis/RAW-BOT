#-------------------------------------------------------------------------------#
#								RAW_BOT								    		#
#-------------------------------------------------------------------------------#

TARGET		:= boot
BIN			:= $(TARGET).bin
ELF			:= $(TARGET).elf

BUILD		:= .objs

ASM_SRC		:= src/startup.s

C_SRCS_DIR	:= src
C_SRCS		:= main.c \
			   gpio.c \
			   utils.c \
			   rcc.c \


SRCS		:= $(addprefix $(C_SRCS_DIR)/, $(C_SRCS))

ASM_OBJ		:= $(patsubst %.s,$(BUILD)/%.o,$(ASM_SRC))
C_OBJ		:= $(patsubst %.c,$(BUILD)/%.o,$(SRCS))

OBJS		:= $(ASM_OBJ) $(C_OBJ)

CC			:= arm-none-eabi-gcc
OBJCOPY		:= arm-none-eabi-objcopy

LD_SCRIPT	:= linker.ld

CFLAGS		:= -mcpu=cortex-m4 -mthumb -ffreestanding -g -Wall -Wextra -O0
ASFLAGS		:= $(CFLAGS)
LDFLAGS		:= -nostdlib -nostartfiles -nodefaultlibs -T $(LD_SCRIPT)
IFLAGS		:= -I ./include

OBJCOPY_FLAGS := -O binary

RM			:= rm -rf
MKDIR		:= mkdir -p

#-Rules------------------------------------------------------------------------#

all: $(BIN)

$(BUILD)/%.o: %.s
	$(MKDIR) $(@D)
	$(CC) $(ASFLAGS) $(IFLAGS) -c $< -o $@

$(BUILD)/%.o: %.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(ELF): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(BIN): $(ELF)
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

clean:
	$(RM) $(BUILD) $(ELF) $(BIN)

re: clean all

#-------------------------------------------------------------------------------#
