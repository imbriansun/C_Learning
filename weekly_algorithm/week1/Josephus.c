// 带头结点版

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
			//这样的一段代码是为了防止一种情况：当要删除的是No.1结点时，ptr停止在最后一个结点，然而最后一个节点规定不能被ptr指（要不然删除的就是为节点的下一个结点头结点），因此这里把ptr移动到头结点上
			if(ptr->next==head){
				ptr=ptr->next;
			}

			temp=ptr->next;
			ptr->next=temp->next;
			printf("No.%d was killed. XD\n",temp->num);
			free(temp);
			cnt=m;
		}
		if(ptr->next==head){	//这样一段代码是在ptr指向第一个结点到第i-2个结点[1,i-1)的过程中所为了防止ptr指向尾结点设置的
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

