# void* 的二三事

翻译自：[void pointer in C / C++](https://www.geeksforgeeks.org/void-pointer-c-cpp/)



一个空指针指向的数据类型没有与任何数据类型有所联系，它可以存储任何数据类型的地址，也可以被转化成任何数据类型的指针。



```c
int a = 10; 
char b = 'x'; 
  
void *p = &a;  // void pointer holds address of int 'a' 
p = &b; // void pointer holds address of char 'b' 
```



### 空指针的特点：

1）malloc()和calloc()函数会返回void*的指针，并且这些函数指针对应的地址还被允许存储分配给任意的数据类型

```c
int main(void) 
{ 
    // Note that malloc() returns void * which can be  
    // typecasted to any type like int *, char *, .. 
    int *x = malloc(sizeof(int) * n); 
} 
```

以上代码仅在C中可被编译，C++中必须在malloc函数前加上申请空间所存储的数据类型的指针"(int *)"，进行指针基类型的强制转换，而这一点对于C来说不是必须的。



2)空指针在C语言中可被实现<u>泛型函数</u>（泛型函数就是你定义函数时候，是万能类型。在调用的时候，只要你把具体的类型传进去就好。好处呢，就是代码的复用，减少代码量。），例如用在stdlib.h头文件中的qsort函数的compare函数。（C Primer Plus 中文译本第六版 P552）



### 一些有趣的事实：

1）你定义好的空指针不能被间接引用（即 *指针名），如下的代码是不能被编译的

```c
#include<stdio.h> 
int main() 
{ 
    int a = 10; 
    void *ptr = &a; 
    printf("%d", *ptr); 
    return 0; 
} 
```

输出：

```c
Compiler Error: 'void*' is not a pointer-to-object type 
```

如下的代码可是有被编译的：

```c
#include<stdio.h> 
int main() 
{ 
    int a = 10; 
    void *ptr = &a; 
    printf("%d", *(int *)ptr); 		// 进行强制类型转换
    return 0; 
} 
```

输出

`10`



2）C标准不允许指针与空指针间进行算数运算。然而，在GNU C中，这被允许但是空指针的大小被规定为1。 在gcc编译器下运行如下代码：

```c
#include<stdio.h> 
int main() 
{ 
    int a[2] = {1, 2}; 
    void *ptr = &a; 
    ptr = ptr + sizeof(int); 
    printf("%d", *(int *)ptr); 
    return 0; 
} 
```

输出：

`2`

在其他编译器下可能不可被编译成功。



### 具体相关的空指针运算：

https://stackoverflow.com/questions/20967868/should-the-compiler-warn-on-pointer-arithmetic-with-a-void-pointer