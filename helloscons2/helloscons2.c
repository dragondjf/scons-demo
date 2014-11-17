#include <stdio.h>
#include <stdlib.h>

#include "file1.h"
#include "file2.h"

int main(int argc, char* argv[])
{
	printf("Hello, another SCons !\n");

	fun_bar();
	
	fun_foo();
	
	return 0;
}
