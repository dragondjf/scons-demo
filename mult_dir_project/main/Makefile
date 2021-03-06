#
# (C) Copyleft 2011
# Late Lee from http://www.latelee.org
# 
# A simple Makefile for multi-directory
# Most idea comes from U-boot project
#

ROOTDIR	:= $(CURDIR)

include $(ROOTDIR)/config.mk

###############################################################################
# libs

ExecutableName = main

target_bar = bar
target_foo = foo
target_helloworld = helloworld
targets := $(target_bar) $(target_foo) $(target_helloworld)

_LIBS := \
../$(target_bar)/lib$(target_bar).a \
../$(target_foo)/lib$(target_foo).a \
../$(target_helloworld)/lib$(target_helloworld).a

LIBS := $(addprefix $(obj),$(_LIBS))

LDFLAGS = $(addprefix $(obj),$(_LIBS))

ifeq ($(shell uname), Linux)
SharedLibPath_LDFLAGS = $(addprefix -L,$(SHARED_DIR))
Sharedlibs := $(addprefix -l, $(targets))
else
SharedLibPath_LDFLAGS = $(addprefix -L,$(LIBs_DIR))
Sharedlibs := $(addprefix -l, $(targets))
endif

SharedLibaryPath = $(abspath $(BIN_DIR))

# main.c in this directory, can be empty
CFLAGS += -I../helloworld/

# source file(s), including c file(s) cpp file(s)
# you can also use $(wildcard *.c), etc.
SRC_C   := $(wildcard *.c)
SRC_CPP := $(wildcard *.cpp)

# object file(s)
OBJ_C   := $(addprefix $(obj),$(patsubst %.c,%.o,$(SRC_C)))
OBJ_CPP := $(addprefix $(obj),$(patsubst %.cpp,%.o,$(SRC_CPP)))

# executable file
target = $(STATIC_DIR)/$(ExecutableName)
shared_target = $(SHARED_DIR)/$(ExecutableName)

###############################################################################
#create static and shared Executable program
all: static $(obj).depend share

#create static Executable program
static: $(target)

#create shared Executable program
share: $(shared_target)

config:
	@echo "$(shell uname)"
	@echo "abspath usage: $(abspath $(CURDIR))"
	@echo "CURDIR is $(CURDIR)"
	@echo "OBJTREE is $(OBJTREE)"
	@echo "obj is :$(obj)"
	@echo "LIBS is: $(LIBS)"
	@echo "CFLAGS is: $(CFLAGS)"
	@echo "LDFLAGS is: $(LDFLAGS)"
	@echo "SharedLibPath_LDFLAGS is : $(SharedLibPath_LDFLAGS)"

$(target): $(LIBS) exe

$(shared_target): $(LIBS) sharedexe

exe: $(OBJ_CPP) $(OBJ_C)
	@echo "Generating static executable file..." $(notdir $(target))
	$(CXX) $(CFLAGS) $^ -o $(target) $(LDFLAGS)

sharedexe: $(OBJ_CPP) $(OBJ_C)
	@echo "Generating shared executable file..." $(notdir $(shared_target))
	$(CXX) $^ -o $(shared_target) $(SharedLibPath_LDFLAGS) $(Sharedlibs) -Wl,-rpath,.

$(LIBS):
	@echo "***************************************"
	$(MAKE) -C $(dir $(subst $(obj),,$@))
	@echo "***************************************"

clean:
	@echo "cleaning..."
	@$(RM) $(target) $(shared_target)
	@find $(OBJTREE) $(BIN_DIR) $(LIBs_DIR) -type f \
		\( -name 'core' -o -name '*.bak' -o -name '*~' \
		-o -name '*.o'	-o -name '*.a' -o -name '*.exe'	-o -name '.depend' -o -name '*.so' -o -name '*.dll' \) -print \
		| xargs rm -f
distclean:
	@echo "distcleaning..."
	@$(RM) $(target) $(shared_target)
	@find $(OBJTREE) $(BIN_DIR) $(LIBs_DIR) -type f \
		\( -name 'core' -o -name '*.bak' -o -name '*~' \
		-o -name '*.o'	-o -name '*.a' -o -name '*.exe'	-o -name '.depend' -o -name '*.so' -o -name '*.dll'\) -print \
		| xargs rm -f
	@$(RM) $(obj) $(BUILD_DIR)
	@$(RM) $(BIN_DIR)

.PHONY: all clean distclean $(LIBS) exe


include $(ROOTDIR)/public.mk