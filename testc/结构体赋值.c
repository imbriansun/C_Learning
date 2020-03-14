#include <stdio.h>
struct s1{
	int a;
	char b;
};

int main()
{
	struct s1 i;
	i=(struct s1){
		4,
		'a'
	};
	printf("%d	%c\n",i.a,i.b);
}
	
