/*
 * 问题来源：2020-03-14 哔哩哔哩up主李永乐老师
 *
 * 有t层楼，n个鸡蛋，鸡蛋是相同的，临界楼层是指从某个楼层之上抛下来，都会碎，
 * 但从这个楼层之下抛下来，都不会碎。没有碎的鸡蛋可以重复使用。试假设一定能找到
 * 这个临界楼层需要抛投的最少次数。（找最坏的情况）
 *
 */
#include <stdio.h>

int Egg(int i, int j)
{
	int ans;





int main(void)
{
	int i,j,n,t;
	int arr[1001][1001];

	scanf("%d%d",&n,&t);
	
	for(i = 1; i <= t ; i++ ){	// i个鸡蛋 第一次在j层楼抛
		for(j = 1; j <= n; j++){
			arr[i][j]=Egg(i, j);
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

}


