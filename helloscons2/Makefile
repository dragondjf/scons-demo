
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


# 定义第三方库的路径
INCLUDE = -I"include"

# 定义程序输出可执行文件名称
output = hello


# 获取项目所有.h头文件的路径列表
headers := $(wildcard *.h) $(wildcard ./include/*.h)

# 获取项目所有.c源文件的路径列表
sources := $(wildcard *.c) $(wildcard ./include/*.c)

# 获取项目所有.c源文件的目录列表
dir := $(notdir $(sources))

# 所有.c文件生成的.o文件的o文件列表
objs := $(patsubst %.c, %.o, $(sources) )

# 所有.c文件生成的.d文件的d文件列表, 文件依赖列表
depends := $(patsubst %.c, %.d, $(sources))


headers:
	@echo "${headers}"

sources:
	@echo "${sources}"

objs:
	@echo "${objs}"

sourceds:
	@echo "${depends}"

echo:
	@echo "${headers}"
	@echo "${sources}"
	@echo "${objs}"
	@echo "${depends}"

test:
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
	@$(CC) ${INCLUDE} ${CFLAGS} -MM ${sources}

clean:
	rm -f ${objs} ${output} ${depends}

cleanOutPut:
	rm -f ${output}

cleanObjs:
	rm -f ${objs}

cleanDepends:
	rm -f ${depends}
