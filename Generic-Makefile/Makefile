# Silent build
MAKEFLAGS += s

####################################################################################
####################################################################################
########################   EDITS IN THIS SECTION   #################################
PROJECT_NAME := 

SRC_DIRS := 

BUILD_DIR := 

CLOCK_SPEED := 
####################################################################################
####################################################################################

TARGET_LOADABLE := $(PROJECT_NAME).hex 
TARGET_BINARY := $(PROJECT_NAME).elf

CC = avr-gcc
CXX = avr-g++
OBJCOPY = avr-objcopy

CFLAGS = -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -Os -DF_CPU=$(CLOCK_SPEED)UL -Wall 
CXXFLAGS = -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -mmcu=atmega32 -Os -DF_CPU=$(CLOCK_SPEED)UL -Wall 
LDFLAGS = -mmcu=atmega32


# find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. Make will incorrectly expand these otherwise.
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')


# String substitution for every C/C++ file.
# As an example, hello.cpp turns into ./build/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an examle, ./build/hello.cpp.o turns into ./build/hello.cpp.d
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d)

# Add a prefix to INC_DIRS. so moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# The final build step.
$(BUILD_DIR)/$(TARGET_BINARY): $(OBJS)
	$(CXX) -Wl,-Map,$(BUILD_DIR)/$(PROJECT_NAME).map $(LDFLAGS) $(OBJS) -o $@ 

# objcopy .text and .data sections
$(BUILD_DIR)/$(TARGET_LOADABLE): $(BUILD_DIR)/$(TARGET_BINARY)
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

flash: $(BUILD_DIR)/$(TARGET_LOADABLE)
	avrdude -c usbasp -p m32 -B 0.5 -U flash:w:"$<":a

erase:
	avrdude -c usbasp -p m32 -e

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

debug:
	echo $(SRC_DIRS)
	echo $(INC_DIRS)	
	echo $(SRCS)
	echo $(OBJS)
	echo $(DEPS)
	echo $(INC_FLAGS)
	echo $(CC)
	echo $(CXX)

# Include the .d makefiles. The - at the front suppresses the errors of missing Makefiles.
# Initially, all the .d files will be missing, and we don't want those errors to show up.
-include $(DEPS)

