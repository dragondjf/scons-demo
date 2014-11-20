
PLAT= none

CC= gcc
CFLAGS= -O2 -Wall -DLUA_COMPAT_ALL $(SYSCFLAGS) $(MYCFLAGS)
LDFLAGS= $(SYSLDFLAGS) $(MYLDFLAGS)
LIBS= -lm $(SYSLIBS) $(MYLIBS)

AR= ar rcu
RANLIB= ranlib
RM= rm -f

SYSCFLAGS=
SYSLDFLAGS=
SYSLIBS=

MYCFLAGS=
MYLDFLAGS=
MYLIBS=
MYOBJS=

INCLUDE = -I"include"

output = hello

src := $(wildcard *.c) $(wildcard ./include/*.c)
dir := $(notdir $(src))
objs := $(patsubst %.c,%.o,$(src) )

depends := $(patsubst %.c,%.d,$(src))

all = ${objs}

source:
	@echo "${src}"

sourced:${depends}
	@echo "${depends}"

echo:
	@echo "${src}"
	@echo "${objs}"
	@echo "${all}"

test:
	@echo "${objs}"
	@echo "$(filter $(mains),$(objects)) "
	@echo "$(filter-out $(mains),$(objects)) "
	@echo "$(dir src/foo.c a/b/hacks)"
	@echo "$(notdir src/foo.c a/b/hacks)"
	@echo "$(suffix src/foo.c src-1.0/bar.o hacks)"
	@echo "$(basename src/foo.c src-1.0/bar.c hacks)"
	@echo "$(addsuffix .c,foo bar)"
	@echo "$(addprefix src/,foo bar)"

${depends}: %.d: %.c
	@set -e; rm -f $@; \
	$(CC) ${INCLUDE} -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(objs): %.o: %.c
	$(CC) ${INCLUDE} -c $(CFLAGS) $< -o $@ 

output: $(objs)
	$(CC) -o $(output) ${INCLUDE} ${objs}

depend:
	@$(CC) ${INCLUDE} ${CFLAGS} -MM ${src}

clean:
	rm -f ${objs} ${output} ${depends}

cleanOutPut:
	rm -f ${output}

cleanObjs:
	rm -f ${objs}

cleanDepends:
	rm -f ${depends}
