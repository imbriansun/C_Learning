#include <stdio.h>

/* 这是进行一趟冒泡排序的函数，让该序列中最大的数沉底 
 * n个元素的序列进行一趟比较需要比较n-1次 
 * 因此i=0开始 条件i<n-1 */

void bubble(int arr[], int n){
	int i,temp;
	for(i=0;i<n-1;i++){
		if(arr[i]>arr[i+1]){
			temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
		}
	}

}


/* 进行冒泡排序，有n个数，进行n-1趟bubble 
 * 本函数的i是让前i个元素进行一趟bubble
 */

/* n个数循环n-1次bubble，每次都要使n-1，每次都将当前序列最大值找出来，那么整个序列由最后到最前，
* 数字大小就是整个序列的最大值，次大值，第三大值... 
* */
 
void bubblesort(int arr[], int n){
	int i;
	for(i=n;i>=1;i--){	// 进行n-1趟bubble
		bubble(arr,i);
	}

}

int main()
{
	int arr[]={4,7,8,10,51,7,60,2,-8};
	int i;
	int n=sizeof(arr)/sizeof(arr[0]);
	bubblesort(arr,n);
	for(i=0;i<n;i++)
		printf("%d\n",arr[i]);

}
