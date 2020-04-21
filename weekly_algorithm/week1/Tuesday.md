# Tuesday

## 1.循环链表实现约瑟夫环(带头结点版)

约瑟夫问题是个有名的问题：N个人围成一圈，从第一个开始报数，第M个将被杀掉，最后剩下一个，其余人都将被杀掉。输入N、M，输出被杀掉的顺序，剩余的最后一个人是获胜者。

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *next;
}Node;

void killorder(int m, Node* head){
	Node* ptr,*temp;
	int cnt=m;
	ptr=head;
	while(head->next->next!=head)
	{		

		if(cnt==1){
			
			if(ptr->next==head){
				ptr=ptr->next;
			}

			temp=ptr->next;
			ptr->next=temp->next;
			printf("No.%d was killed. XD\n",temp->num);
			free(temp);
			cnt=m;
		}
		if(ptr->next==head){
			ptr=ptr->next;
		}
		
		
		ptr=ptr->next;	
		cnt--;
	}

	printf("No.%d is the winner. :D\n",ptr->num);

}

Node* CreatList(int n){
	Node* head, *pnew;
	head=(Node*)malloc(sizeof(Node));
	head->next=head;
	int cnt=n;

	while(n--)
	{	
		pnew=(Node*)malloc(sizeof(Node));
		pnew->num=cnt--;
		pnew->next=head->next;
		head->next=pnew;
	}


	return head;
}

int main()
{
	int n, m;
	Node* list;
	scanf("%d%d",&n,&m);
	
	list=CreatList(n);

	killorder(m, list);


}

```

![JGcGTS.jpg](https://s1.ax1x.com/2020/04/21/JGcGTS.jpg)

关键代码解析：

```c
void killorder(int m, Node* head){
	Node* ptr,*temp;
	int cnt=m;
	ptr=head;
	while(head->next->next!=head)
	{		

		if(cnt==1){
			
            /*这样的一段代码是为了防止一种情况：当要删除的是No.1结点时，ptr停止在最后一个结点，然而最后一个节点规定不能被ptr指（要不然删除的就是为节点的下一个结点头结点），因此这里把ptr移动到头结点上
            
			if(ptr->next==head){
				ptr=ptr->next;
			}
			
			*/
			temp=ptr->next;
			ptr->next=temp->next;
			printf("No.%d was killed. XD\n",temp->num);
			free(temp);
			cnt=m;
		}
        
        /*这样一段代码是在ptr指向第一个结点到第i-2个结点[1,i-1)的过程中所为了防止ptr指向尾结点设置的
        
		if(ptr->next==head){
			ptr=ptr->next;
		}
		
		*/
		
		
		ptr=ptr->next;	
		cnt--;
	}

	printf("No.%d is the winner. :D\n",ptr->num);

}
```

![JGhdl4.png](https://s1.ax1x.com/2020/04/21/JGhdl4.png)

## 2.[leetcode-24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

**你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。

 

**示例:**

```
给定 1->2->3->4, 你应该返回 2->1->4->3.
```

```c
struct ListNode {
 	int val;
    struct ListNode *next;
}
struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode *newList, *auxLeft, *auxRight, *auxParent;
    
    newList = head;
    auxLeft = head;
    auxRight = auxLeft->next;
    if(auxRight != NULL)
    {
        auxLeft->next = auxRight->next;
        auxRight->next = auxLeft;
        newList = auxRight;
        auxParent = auxLeft;

        auxLeft = auxLeft->next;
        if(auxLeft == NULL)
            return newList;
        else
            auxRight = auxLeft->next;
    }

    while(auxRight != NULL)
    {
        auxLeft->next = auxRight->next;
        auxRight->next = auxLeft;
        auxParent->next = auxRight;
        auxParent = auxLeft;

        auxLeft = auxLeft->next;
        if(auxLeft == NULL)
            return newList;
        else
            auxRight = auxLeft->next;
    }

    return newList;
}

```

![JG7jjU.jpg](https://s1.ax1x.com/2020/04/21/JG7jjU.jpg)

参考：https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/bao-li-de-mei-xue-by-ylf-4/


$$
××××××flag：明日再敲一遍×××××
$$
