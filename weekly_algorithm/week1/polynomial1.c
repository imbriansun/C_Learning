#include <stdio.h>
#include <stdlib.h>

struct node{
	int coefficient;
	int index;
	struct node *next;
};

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
			end	   = ptr3;
		}
	}

	bubblesort_linklist(head);
	
	return head;
}

void bubblesort_linklist(struct node* head){
	struct node* ptr = head->next;
	

}

void merge(struct node* head){
	struct node* ptr = head->next;
	struct node* ptemp;

	while(ptr->next){
		ptemp = ptr;	// 一旧
		ptr = ptemp->next;	// 一新
		if(ptemp->index == ptr->next){
			ptemp->coefficient += ptr->coefficient;
			ptr->next = ptemp;
		}
	}
}
