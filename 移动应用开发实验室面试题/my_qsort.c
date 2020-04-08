#include <stdio.h>
#include <stdlib.h>

int comp(const void * p1, const void * p2)
{
	return (*(int *)p1 > *(int *)p2);
}
void swap1(void *p1, void * p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}
void myqsort(void *base, int count, int size, int(*cmp)(const void *, const void *))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j<count - i - 1; j++)
		{
			if (comp((char *)base + j*size, (char *)base + (j + 1)*size) > 0)
			{
				swap1((char *)base + j*size, (char *)base + (j + 1)*size, size);
			}
		}
	}
}
int main()
{
	int arr[] = {68,15,24,36,2,54};
	int i = 0;
	myqsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), comp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
