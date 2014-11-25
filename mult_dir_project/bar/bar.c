#include <stdio.h>
#include "bar.h"


void bar(int i)
{
	printf("hell from %s() in file: %s, num:%d\n", __func__, __FILE__, i);
}

int hello_bar(void)
{
    printf("in func: %s()\n", __func__);
    return 0;
}
