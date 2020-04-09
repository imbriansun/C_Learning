#include <stdio.h>
#include <string.h>

#define STRCPY(a,b) strcpy(a##_p,#b)

int main()
{
	char var1_p[20];
	char var2_p[30];
	strcpy(var1_p,"aaa");
	strcpy(var2_p,"bbb");
	STRCPY(STRCPY(var1,var2),var2);
	puts(var1_p);
	puts(var2_p);

	return 0;
}
