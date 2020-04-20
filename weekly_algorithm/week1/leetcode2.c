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
