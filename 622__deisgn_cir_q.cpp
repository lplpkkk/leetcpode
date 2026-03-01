class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int lim;
    int cnt; 

public:
    MyCircularQueue(int k) {
        data.resize(k);
        head=0;
        tail=0;
        lim=k;
        cnt=0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        data[tail]=value;
        tail=(tail+1)%lim;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        head=(head+1)%lim;
        cnt--;

        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return data[head];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return data[(tail-1+lim)%lim];
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==lim;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
