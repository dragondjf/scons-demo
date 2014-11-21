#
# (C) Copyleft 2011
# Late Lee from http://www.latelee.org
# 
# A simple file to specify compier and macros and flags
# and ways to compile .c & .cpp
#

# cross compile...
CROSS_COMPILE = 

CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
AR = $(CROSS_COMPILE)ar

ARFLAGS = cr
RM = -rm -rf
MAKE = mingw32-make

CFLAGS = #-Wall
DEBUG = y

ifeq ($(DEBUG), y)
CFLAGS += -g
DEBREL = Debug
else
CFLAGS += -O2 -s
DEBREL = Release
endif

DEFS = 

CFLAGS += $(DEFS)

LDFLAGS = $(LIBS)


# export to other Makefile
export CC
export CFLAGS
export INCDIRS
export AR
export ARFLAGS
export RM

###############################################################################

INCDIRS = ../include/

CFLAGS += -I$(INCDIRS)

#build file directory
BUILD_DIR := ../../build

# binary file directory
BIN_DIR := ../../bin

OBJTREE	:= $(if $(BUILD_DIR),$(BUILD_DIR),$(CURDIR))
export OBJTREE

obj := $(OBJTREE)/$(notdir $(CURDIR))/

ifneq ($(BUILD_DIR),)
$(shell mkdir -p $(obj))
endif

ifneq ($(BIN_DIR),)
$(shell mkdir -p $(BIN_DIR))
endif

suffix = $(notdir $(CURDIR))
export suffix
