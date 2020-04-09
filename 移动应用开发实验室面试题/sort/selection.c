#include <stdio.h>


/* 在n个数中寻找出最大值的位置 */

int findMaxPos(int arr[], int n){
	int i,pos=0,max=arr[0];
	for(i=0;i<n;i++)
		if(arr[i]>max)
			max=arr[i], pos=i;
	return pos;
}

/* 选择排序是将在序列中找到的最大值和该序列的最后一个元素位置作交换 */

void selectionsort(int arr[], int n){
	while(n > 1){
		int pos=findMaxPos(arr, n);	
		/* n个数循环n-1次，每次都要使n-1，每次都将当前序列最大值找出来，那么整个序列由最后到最前，
		 * 数字大小就是整个序列的最大值，次大值，第三大值... 
		 * */
		int temp = arr[pos];
		arr[pos] = arr[n-1];
		arr[n-1] = temp;
		n--;
	}
}

int main()
{
	int arr[]={41,85,4,5,0,4,78,558,-35,-41,-2,58};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionsort(arr, n);

	for(int i=0; i<n; i++)
		printf("%d\n",arr[i]);
}
