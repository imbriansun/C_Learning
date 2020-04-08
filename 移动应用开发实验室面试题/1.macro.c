#include <stdio.h>
#define xname(N) x##N	// 类函数参宏中的宏部分括号内容粘合到##之后
#define print(N) printf("x" #N " is %d\n", x##N)	// 类函数参宏的宏部分括号内容替换#N以变成字符串和其他字符串黏合在一起

int main()
{
	int xname(1) = 5;
	int xname(2) = 44;
	int x3=254;

	print(1);
	print(2);
	print(3);
	
}
