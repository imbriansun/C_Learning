/*qsort()原型：
 *
 * void qsort (void *base, size_t nmemb, size_t size, int (*compare)(const void*, const void*))
 *
 * 第一个参数是空指针（指向待排序数组的首元素）因此可以指向任何类型的数组
 * 第二个参数是待排序项的数量
 * 第三个参数是数组中每个元素的大小，由于第一个参数是void指针，qsort函数不知道数组中每个元素的大小，可用sizeof(type_name)表示大小
 * 第四个参数是一个指向函数compare(需另外定义)的指针，该函数接受两个参数:分别指向比较两项的指针。
 * compare()函数的原型如下：
 *
 * int (*compare)(const void*, const void*)
 *
 * */

/* 2.qsorter.c 用qsort函数排序一组数字 */

#include <stdio.h>
#include <stdlib.h>

#define NUM 50

void fillarray(double ar[], int n);
void showarray(const double ar[], int n);
int mycomp(const void*, const void*);

int main()
{
	double vals[NUM];
	fillarray(vals, NUM);
	puts("排序前：");
	showarray(vals, NUM);
	qsort(vals, NUM, sizeof(double), mycomp);
	puts("\n排序后：");
	showarray(vals, NUM);

}

/* 按从小到大的顺序 */
int mycomp(const void *p1, const void *p2){
	const double *a1 = (double*)p1;
	const double *a2 = (double*)p2;

	if(*a1 > *a2)		/* 这里可以理解成使*a1-*a2，若大于0返回1，小于0，返回-1，两数相等时返回0 */

		return 1;
	else if (*a1 == *a2)
		return 0;
	else
		return -1;
}


void fillarray(double ar[], int n){
	int index;

	for(index = 0; index < n; index++)
		ar[index] = (double)rand() / ((double)rand() + 0.1);

}


void showarray(const double ar[], int n){
	int i;

	for(i=0;i<n;i++){
		printf("%9.4f ",ar[i]);

		if(i%6==5)
			putchar('\n');
	}

	if(i%6!=0)
		putchar('\n');

}
