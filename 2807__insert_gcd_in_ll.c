/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int gcd(int a,int b){
	while(b!=0){
		int temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
	
	struct ListNode* cur=head;

	while(cur!=NULL && cur->next!=NULL){
		int val=gcd(cur->val,cur->next->val);
		
		struct ListNode* newgcd=malloc(sizeof(struct ListNode));
		newgcd->val=val;
		newgcd->next=cur->next;

		cur->next=newgcd;
		cur=newgcd->next;
	}

	return head;
}
