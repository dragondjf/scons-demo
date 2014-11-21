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
_LIBS := ../bar/libbar.a ../foo/libfoo.a

LIBS := $(addprefix $(obj),$(_LIBS))

LDFLAGS = $(addprefix $(obj),$(_LIBS))


# main.c in this directory, can be empty
MAIN_DIR := main/

# source file(s), including c file(s) cpp file(s)
# you can also use $(wildcard *.c), etc.
SRC_C   := $(wildcard *.c)
SRC_CPP := $(wildcard *.cpp)

# object file(s)
OBJ_C   := $(addprefix $(obj),$(patsubst %.c,%.o,$(SRC_C)))
OBJ_CPP := $(addprefix $(obj),$(patsubst %.cpp,%.o,$(SRC_CPP)))

# executable file
target = $(BIN_DIR)/a

###############################################################################

all: $(target) $(obj).depend

config:
	@echo "$(shell uname)"
	@echo "CURDIR is $(CURDIR)"
	@echo "OBJTREE is $(OBJTREE)"
	@echo "obj is :$(obj)"
	@echo "LIBS is: $(LIBS)"
	@echo "CFLAGS is: $(CFLAGS)"
	@echo "LDFLAGS is: $(LDFLAGS)"

$(target): $(LIBS) exe

exe: $(OBJ_CPP) $(OBJ_C)
	@echo "Generating executable file..." $(notdir $(target))
	$(CXX) $(CFLAGS) $^ -o $(target) $(LDFLAGS)

$(LIBS):
	@echo "***************************************"
	$(MAKE) -C $(dir $(subst $(obj),,$@))
	@echo "***************************************"

clean:
	@echo "cleaning..."
	@$(RM) $(target)
	@find $(OBJTREE) $(BIN_DIR) -type f \
		\( -name 'core' -o -name '*.bak' -o -name '*~' \
		-o -name '*.o'	-o -name '*.a' -o -name '*.exe'	-o -name '.depend' \) -print \
		| xargs rm -f
distclean:
	@echo "distcleaning..."
	@$(RM) $(target)
	@find $(OBJTREE) $(BIN_DIR) -type f \
		\( -name 'core' -o -name '*.bak' -o -name '*~' \
		-o -name '*.o'	-o -name '*.a' -o -name '*.exe'	-o -name '.depend' \) -print \
		| xargs rm -f
	@$(RM) $(obj) $(BUILD_DIR)
	@$(RM) $(BIN_DIR)

.PHONY: all clean distclean $(LIBS) exe


include $(ROOTDIR)/public.mk