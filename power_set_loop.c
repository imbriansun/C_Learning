/* 
 * 给定一个int型数组set，内含set_size个整数，使用函数power_set_loop循环
 * 的方式来输出set的幂集
 *
 * 这里我们规定set_size = 4, 时间复杂度为O(n^3)+O(n)
 *
 */

#include <stdio.h>
#include <math.h>

void power_set_loop(int* set, int set_size){
	
	printf("∅\n");
	
	for(int i=0; i<set_size ;i++)
		printf("%d ",set[i]);
	putchar('\n');

	for(int i=0; i<set_size; i++)
	{
		for(int j=i+1; j<set_size; j++)
		{
			for(int k=j+1; k < set_size; k++)
			{	
				printf("%d %d ",set[i],set[j]);
				printf("%d\n",set[k]);
			}

			printf("%d %d\n",set[i],set[j]);
		}

		printf("%d\n",set[i]);
	}
}

int main()
{
	int i;

	int set[4]={0};

	for(i=0;i<4;i++)
		scanf("%d",&set[i]);
	printf("------------\n");	
	power_set_loop(set,4);
	printf("------------\n");
	return 0;
}
