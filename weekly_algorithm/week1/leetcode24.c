#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *next;
}Node;

Node* CreatList(int n){
	Node* head, *pnew;
	head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
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

void swap(Node* head){
    
}

int main(int argc, char*argv[])
{


}
