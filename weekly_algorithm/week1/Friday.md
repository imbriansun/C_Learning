### 1.多项式加法

实现两个一元多项式相加运算



输入：一行输入非零多项式项数n，下一行输入n对（系数，指数）表示，每一项（按照指数升序输入）



输出：按多项式形式输出，各项指数升序排列



思路：

​		进行两条链表链表的合并，比较两个链表的节点值域，指数较小的连入第三条链表，指数相同的将系数相加运算后连入第三条链表，最终两条链表未遍历完剩余的节点全部补齐在第三条链表。

对该过程进行模拟实现：



代码：

```c
struct node* add(struct node* head1, struct node* head2) {
	struct node* ptr1 = head1->next;
	struct node* ptr2 = head2->next;
	struct node* ptr3 = (struct node*)malloc(sizeof(struct node));
	struct node* head, *end;
	head = end =ptr3;
	ptr3->next = NULL;

	while(ptr1 || ptr2) {

		/* 弥新节点 */

		ptr3 = (struct node*)malloc(sizeof(struct node));

		/* 填值域 */
		if(ptr1 && ptr2){
			if(ptr1->index > ptr2->index) {
				ptr3->index = ptr1->index;
				ptr3->coefficient = ptr1->coefficient;
			} else if (ptr1->index < ptr2->index) {
				ptr3->index = ptr2->index;
                       	        ptr3->coefficient = ptr2->coefficient;
			} else {
				ptr3->index = ptr1->index;
                       		ptr3->coefficient = ptr1->coefficient + ptr2->coefficient;
			}
		} else if (!ptr1) {
			ptr3->coefficient = ptr2->coefficient;
			ptr3->index = ptr2->index;
		} else if (!ptr2) {
			ptr3->coefficient = ptr1->coefficient;
                        ptr3->index = ptr1->index;
		}

		/* 指针移动以连接新节点 */

		ptr3->next = end->next;
		end->next  = ptr3;
	        end        = ptr3;	
	}

	return head;
}
```







### 2.多项式减法

实现两个一元多项式的相减运算

当两个多项式相减为0时，要输出0

按上述格式输入输出



思路：

​		和CPU中加法器执行减法命令原理一样，将减数遍历一遍系数取反，在与被减数链表相加



代码：

```c
void opposite_val (struct node* head) {
	struct node* ptr = head->next;
	while(ptr) {
		ptr->coefficient = -(ptr->cofficient);
		ptr = ptr->next;
	}
}


struct node* subtract(struct node* head1, struct node* head2) {
	opposite_val (head2);

	return add(head1, head2);
	
}
```





### 3.多项式相乘

思路：两层循环，对结点再进行排序，再合并相同指数项



```c
struct node* multi(struct node* head1, struct node* head2) {
        struct node* ptr1 = head1->next;
        struct node* ptr2 = head2->next;
        struct node* ptr3 = (struct node*)malloc(sizeof(struct node));
        struct node* head, end;
        head = end = ptr3;

        while(ptr1){
                while(ptr2){
                        ptr3 = (struct node*)malloc(sizeof(struct node));
                        ptr3->coefficient = ptr1->coefficient * ptr2->coefficient;
                        ptr3->index = ptr1->index + ptr2->index;

                        ptr3->next = end->next;
                        end->next  = ptr3;
                        end        = ptr3;
                }
        }

     sort_linklist(head);
    
     merge(head);
	
    return head;

}
```

#### ==> 链表排序之冒泡排序：

```c
void BubbleSort(bubbleSort * head)
{
    for(p = head -> next; p != NULL; p = p -> next)
          for(q = p -> next; q != NULL; q = q -> next)
               if((p -> index) > (q -> index))
               {
                   int temp_coe = p->coefficient;
                   int temp_index = p->index;
                   p->coefficient = q->coefficient;
                   p->index = q->index;
                   q->coefficient = temp_coe;
                   q->index = temp_index;
               }
}

```



#### ==>链表重复项合并：

```c
void merge(struct node* head){
        struct node* ptr = head->next;
        struct node* ptemp;

        while(ptr->next){
                ptemp = ptr;    // 一旧
                ptr = ptemp->next;      // 一新
                if(ptemp->index == ptr->next){
                        ptemp->coefficient += ptr->coefficient;
                        ptr->next = ptemp;
                }
        }
}
```

