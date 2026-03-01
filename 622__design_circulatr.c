


typedef struct {
    int head;
    int tail;
    int* data;
    int cnt;
    int lim;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* my_cir_q=malloc(sizeof( MyCircularQueue));

    my_cir_q->data=malloc(sizeof(int)*k);
    my_cir_q->head=0;
    my_cir_q->tail=0;
    my_cir_q->cnt=0;
    my_cir_q->lim=k;

    return my_cir_q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)){
        return false;
    }

    obj->cnt+=1;
    obj->data[obj->tail]=value;
    obj->tail=(obj->tail+1)%obj->lim;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return false;
    }

    obj->head=(obj->head+1)%obj->lim;
    obj->cnt-=1;

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }

    return obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }

    int idx=(obj->tail-1+obj->lim)%obj->lim;

    return obj->data[idx];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return(obj->cnt==0);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return(obj->lim==obj->cnt);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if(obj){
        free(obj->data);
        free(obj);
    }
}

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
