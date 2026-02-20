#include <stdio.h>

struct Node{
	int val;
	struct Node* next;
}

struct Node* plusone(struct Node* list){
	struct Node* sentinel=malloc(sizeof(struct Node));
	sentinel->val=0;
	sentinel->next=list;

	struct Node* not_nine=sentinel;
	struct Node* cur=list;

	while(cur!=NULL){
		if (cur->val!=9){
			not_nine=cur;
		}
		cur=cur->next;
	}
	
	not_nine->val+=1;
	cur=not_nine->next;

	while(cur!=NULL){
		cur->val=0;
		cur=cur->next;
	}
	
	if(senitel->val==0){
		free(senitel);
	}

	return (sentinel->val!=0)? (&sentinel):list;
}

int main(){
	return 0;
}
