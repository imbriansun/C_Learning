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
