# Wednesday

## 1.字符串匹配--朴素的 模式匹配 算法

```c
/* 数组下标法、指针运算法 */

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
```

![Jt6gBt.png](/home/briansun/桌面/Jt6gBt.png)

## 2.字符串匹配 -- KMP模式匹配算法

* Step:

  * Calculate the prefix table of the searching one(source string)

    * form a prefix table which is made by cutting the source string. the character of the items in prefix table are incresed character one by one.

    * Find the longest common prefix and suffix string (except the source whole string) for each item in the prefix table.

    Cut out the longest prefix string and longest suffix string of one of the items in prefix table for each one, and write down the length of prefix string or suffix string in prefix table.

    E.g.

    ​		one of the item-string in frefix table:` a b a b`

    ​		the common longest prefix and suffix string is a  `a b` 

    ​		therefore the lenth of it is   `2`   should be marked beside the item in prefix table.

    * turn the prefix table to the brief one. (example below)

    

    E.g.

    ​	source string for prefix table: ` a b a b c`

    -1

    0	a

    0	a b

    1	a b a

    2	a b a b

    ~~0	a b a b c~~

    

    if the index of source string start by 0, we will abandon the last one and add `-1`  at begining.

    

    turn it to be the brief one and the new form is the latest PREFIX TABLE.

    

    1	2	3	4	5

    a	b	a	b	c

    -1	0	0	1	2



> tip :
>
> 			* you should mark the serial number on the source string.(start by `0`)
> 			* kmp算法的原理是我们计算出的前缀表(prefix table)中的值代表对应为之前的共同的前缀和后缀表达式最大的公共字符串个数，因此我们移动到对应位置时可以保证，此时此刻的该位置之前的所有值都是匹配的，因此只需要对之后的元素进行比较