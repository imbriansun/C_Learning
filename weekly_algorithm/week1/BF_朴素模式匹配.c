#include <stdio.h>
#include <string.h>
int bf_index(char *a, char *b){
	int i = 0, j = 0;
	while(i<strlen(a)){
		if(a[i]==b[j]){
			i++;
			j++;
		}
		else {
			/*i=i-j则i回到这次匹配前的指针位置 +1 则是
匹配失败让在母串上的指针移到下一个字符上*/

			i = i - j + 1;
			j = 0;
		}
		if(j==strlen(b)){
			return i-j;
		}
	}
	return -1;
}

char* bf_ptr(char *a, char *b){
	char *m, *n;
	
	while(*a){	// 若a字符串都读到尾部了还没有匹配上则b不是a的子串
		m = a;	// 让m、n充当临时的a、b
		n = b;
		while(*m++ == *n++){
			if(!*n){
				return a;	// 一旦匹配成功 结束返回
			}
		}
			
		a++;	// 未匹配成功，则对母串指针下移一个字符从此开始再匹配
	}

	return NULL;
}


int main()
{
	char a[100],b[100];

	puts("Please input a parent-string and sub-string in sequence");
	
	scanf("%s%s",a,b);

	printf("sub-string is located at %d of parent-string.<bf_index method>\n",bf_index(a,b));

	printf("sub-string is located at %ld of parent-string.<bf_ptr method>\n",bf_ptr(a,b)-a);

}
