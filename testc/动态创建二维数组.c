#include <stdio.h>
#include <stdlib.h>
int main()
{
	int r,c;
	scanf("%d %d",&r,&c);	// 输入行列

	int ** ptr;

	/* 申请二维数组空间 <由外至内> */

	ptr=(int**)malloc(r*sizeof(int*));	// ① 先创建行数个指针空间
	for(int i=0;i<r;i++){			// ② 再遍历“每一行” 对每一行来申请一个r个整数大小的空间赋给每一行的“行指针”
		ptr[i]=(int*)malloc(c*sizeof(int));
	}

	/* 填充二维数组数据 */
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			ptr[i][j] = j + 1 ;
		}
	}


	/* 打印二维数组 */

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%d ",ptr[i][j]);
		}
		printf("\n");
	}

	/* 使用完该数组 释放其动态申请的内存 */

	/* 释放顺序：由内及外 */

	for(int n=0;n<c;n++){
		free(ptr[n]);
	}

	free(ptr);

}
