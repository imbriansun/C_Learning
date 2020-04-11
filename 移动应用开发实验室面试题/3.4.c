#include <stdio.h>
#pragma pack (8)
struct B{
	int a;
	char b;
	double c;
};
struct A{
	char a;double b;
	int c;
};
struct C{
	char a;
	double b;
	struct A c;
	int d;
};


int main()
{
	printf("%lu,%lu\n",sizeof(struct A),sizeof(struct B));
	printf("%lu",sizeof(struct C));
}

