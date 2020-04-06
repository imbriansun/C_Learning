#include <stdio.h>

struct node {
	int a;
	int b;
	int c;
};


int main()
{
	struct node a = { 1, 10, 100 };
	struct node *p = &a;
	printf("%d\n", *(int*)p);
}
