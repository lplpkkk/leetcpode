


typedef struct {
    int* data;
    int front;
    int last;
    int lim;
    int cnt;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* dq=malloc(sizeof(MyCircularDeque));

    dq->data=malloc(sizeof(int)*k);
    dq->front=0;
    dq->last=0;
    dq->lim=k;
    dq->cnt=0;

    return dq;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if(obj->cnt==0){
        return true;
    }else{
        return false;
    }
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if(obj->cnt==obj->lim){
        return true;
    }else{
        return false;
    }
}


bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj)){
        return false;
    }

    obj->data[obj->front]=value;
    obj->front=(obj->front-1+obj->lim)%obj->lim;
    obj->cnt+=1;

    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj)){
        return false;
    }

    obj->last=(obj->last+1)%obj->lim;
    obj->data[obj->last]=value;
    obj->cnt+=1;

    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj)){
        return false;
    }

    obj->front=(obj->front+1)%obj->lim;
    obj->cnt-=1;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj)){
        return false;
    }

    obj->last=(obj->last-1+obj->lim)%obj->lim;
    obj->cnt-=1;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj)){
        return -1;
    }
    return obj->data[(obj->front+1)%obj->lim];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj)){
        return -1;
    }
    return obj->data[obj->last];
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
