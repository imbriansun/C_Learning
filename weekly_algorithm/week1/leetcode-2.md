## 1. leetcode-2 两数相加

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。





```c
struct ListNode {
     int val;
     struct ListNode *next;
};


int lenth(struct ListNode* list){
	int len=0;
	struct ListNode* ptr=list;
	while(ptr)
	{
		len++;
		ptr=ptr->next;
	}

	return len;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode *l3=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *r=l3;
	int len1, len2, i,fi=0;
	len1=lenth(l1);
	len2=lenth(l2);

	int len = len1>len2?len1:len2;

	for(i=0;i<len;i++)
	{
		r=(struct ListNode*)malloc(sizeof(struct ListNode));
		
		if(i > (len1<len2?len1:len2) && len1>len2)
		{
			r->val=l1->val;
		}
		else if((i > (len1<len2?len1:len2) && len1<len2))
		{
			r->val=l2->val;
		}else
		{
			r->val = (l1->val + l2->val +fi)%10;
			fi=(l1->val + l2->val)/10;	//处理进位问题
				
		}
		
		r=r->next; 
	}

	return l3;
}



```



### 分析：

基本的链表增减。

将两个已知链表的每个结点数做出统计，较小值为循环最大值，这段循环中将两个链表的每一位相加，注意进位的问题。最后从链表长度较小值到较大值循环时，将较长链表val值直接添加到l3链表上来。



## 2.leecode-19 删除链表的倒数第N个节点

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



```c
struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	struct ListNode *ptr1, *ptr2, *ptr3;
	ptr3=(struct ListNode*)malloc(sizeof(struct ListNode));
	ptr3->val=0;
	ptr3->next=head;
	ptr1=ptr2=ptr3;

	int cnt=0;

	while(ptr2)
	{
		ptr2=ptr2->next;
		cnt++;
		if(cnt>n+1)
			ptr1=ptr1->next;
	}

	ptr1->next=ptr1->next->next;

	return ptr3->next;
}
```





### 进阶要求分析：

如果要保证进行一趟遍历就可以找到倒数第n个结点，思路是创建两个结点指针，一个指针指着头结点，另外一个移动，假设头结点不存数据，移动的那个指针遍历移动n个后，指向头结点的指针开始移动，与在第n个结点的指针间保持相对静止，当较后的那个指针指向链表的末尾，两个指针停止移动，这时，较前的指针指向倒数第n个结点。