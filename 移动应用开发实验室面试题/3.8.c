#include <stdio.h>
int main()
{
	int a[4] [3]={1,2,3,4,5,6,7,8,9,10,11,12};
	// 假设 a的首地址为0x0000000000000000
	printf("%p,%p\n",a,a+1);
	printf("%p,%p\n",a[0],a[0]+1);
	printf("%p,%p\n",*a,*a+1);
	printf("%d\n",a[0] [0]);
	printf("%d,%d\n",*a[0],*(a[0]+1));
	printf("%d\n",**a);
	printf("%d\n",* (*(a+3)+1));
						        
}
