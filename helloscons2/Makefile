
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

output = hello

cs = *.c
objs := $(patsubst %.c,%.o,$(wildcard *.c))

all = ${cs} ${objs}

c:
	@echo ${cs}

o: 
	@echo ${objs}


lc:
	@echo ${cs}
	@echo ${objs}
	@echo ${all}
	@echo $@

$(objs): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

output: $(objs)
	$(CC) -o ${output} ${objs}

depend:
	@$(CC) $(CFLAGS) -MM *.c

clean:
	rm -f ${objs} ${output}

cleanOutPut:
	rm -f ${output}

cleanObjs:
	rm -f ${objs}

bigoutput littleoutput:
	@echo $@
	@echo $(subst output, ,$@)