#include<stdio.h>
int main()
{
	int x=3;
	int y=4;
	int a = x++ + x++ + x++;
	int b = ++y + ++y + ++y;
	printf("%d, %d\n", a, b);
}
