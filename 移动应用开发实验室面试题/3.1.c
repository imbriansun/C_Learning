#include <stdio.h>
int main()
{
	int x,y,m,n;
	x=0;
	y=1;
	m=x,y;
	n=(x,y);
	printf("%d ",m);
	printf("%d\n",n);

}
