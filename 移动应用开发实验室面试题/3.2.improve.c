#include <stdio.h>
int main()
{
	
	int x=3;
	int y=4;
	int a = x++;
	a+=x++;
	a+=x++;

	int b = ++y ;
	b+=++y;
	b+=++y;

	printf("%d, %d\n", a, b);

}
