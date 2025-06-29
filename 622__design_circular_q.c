
#if(1)
typedef struct dl{
    int val;
    struct dl* prev;
    struct dl* next;
}dl;


typedef struct {
    int max;
    int cur_usage;
    dl* head;
    dl* tail;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {

    MyCircularQueue* obj=malloc(sizeof(MyCircularQueue));
    obj->max=k;
    obj->cur_usage=0;
    obj->head=malloc(sizeof(dl));
    obj->tail=malloc(sizeof(dl));

    obj->head->next=obj->tail;
    obj->head->prev=NULL;
    obj->tail->prev=obj->head;
    obj->tail->next=NULL;

    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->cur_usage==obj->max) return false;
    
    dl* new_node=malloc(sizeof(dl));
    new_node->val=value;

    dl* prev=obj->tail->prev;
    prev->next=new_node;
    new_node->prev=prev;
    new_node->next=obj->tail;
    obj->tail->prev=new_node;
    
    obj->cur_usage++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->cur_usage==0) return false;

    dl* to_del=obj->head->next;
    obj->head->next=to_del->next;
    to_del->next->prev=obj->head;
    free(to_del);

    obj->cur_usage--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->cur_usage==0){
        return -1;
    }
    
    return obj->head->next->val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->cur_usage==0){
        return -1;
    }

    return obj->tail->prev->val;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->cur_usage==0);    
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->cur_usage==obj->max);        
}

void myCircularQueueFree(MyCircularQueue* obj) {
    dl* cur=obj->head;

    while(cur!=NULL){
        dl* next=cur->next;      
        free(cur);
        cur=next;
    }
    free(obj);
}
#endif


/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
