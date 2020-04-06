#include <stdio.h>
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
	printf("%d,%d\n",sizeof(struct A),sizeof(struct B));
	printf("%d",sizeof(struct C));
}

