#
# (C) Copyleft 2011
# Late Lee from http://www.latelee.org
# 
# A simple Makefile for lib(libxxx.a)
# You just need to change library name and source file(s)
#

ROOTDIR = $(dir ${CURDIR})main

include $(ROOTDIR)/config.mk

# here you can set your own flags
CFLAGS += -D_A_

# static library name
LIB = $(obj)libfoo.a

# source file(s), including c file(s) cpp file(s)
# you can also use $(wildcard *.c), etc.
SRC_C   := $(wildcard *.c) 
SRC_CPP := $(wildcard *.cpp)

# object file(s)
OBJ_C   := $(addprefix $(obj),$(patsubst %.c,%.o,$(SRC_C)))
OBJ_CPP := $(addprefix $(obj),$(patsubst %.cpp,%.o,$(SRC_CPP)))

all: $(obj).depend $(LIB)

config:
	@echo "CURDIR is $(CURDIR)"
	@echo "ROOTDIR is $(ROOTDIR)"
	@echo "OBJTREE is $(OBJTREE)"
	@echo "obj is: $(obj)"
	@echo "$(ROOTDIR)/config.mk"
	@echo "$(ROOTDIR)/public.mk"

$(LIB): $(OBJ_C) $(OBJ_CPP)
	@echo "Generating static library: " $(notdir $@)
	$(AR) $(ARFLAGS) $@ $^

clean:
	@echo "Cleaning..."
	$(RM) $(OBJ_C) $(OBJ_CPP) $(LIB) *.bak *~ *.d *.o $(obj).depend

.PHONY: all config  $(LIB) clean

include $(ROOTDIR)/public.mk
