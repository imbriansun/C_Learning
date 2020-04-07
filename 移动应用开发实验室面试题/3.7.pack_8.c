#pragma pack(8)
#include <stdio.h>
struct perInfo1{
	int num;
	char name[10];
	double account;
};

struct perInfo2{
	char name[10];
	double account;
	int num;
};

int main()
{
       	struct perInfo1 Tony1 = {1,"Tony",3.14159};
	int structSize1 = sizeof(struct perInfo1);
	struct perInfo2 Tony2 = {"Tony",3.14159,1};
	int structSize2 = sizeof(struct perInfo2);
	printf("Size : { int, char[10], double } = %d\n",structSize1);
	printf("Size : { char[10], double, int } = %d\n",structSize2);
				    
	return 0;
}
