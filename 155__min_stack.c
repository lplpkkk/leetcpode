

#define MAX_STACK 20000
typedef struct {
    int stack[MAX_STACK];
    int stack_min[MAX_STACK];
    int cur_idx;
} MinStack;


MinStack* minStackCreate() {
    MinStack* s=malloc(sizeof(MinStack));
    s->cur_idx=-1;
    return s;
}

void minStackPush(MinStack* obj, int val) {
    obj->cur_idx++;
    int this_idx=obj->cur_idx;
     obj->stack[this_idx]=val;    

    if(obj->cur_idx==0){
        //first one
        obj->stack_min[this_idx]=val;    
    }else{
        int last_min=obj->stack_min[this_idx-1];
        obj->stack_min[this_idx]=(val<last_min)?val:last_min;
    }
    
    return;
}

void minStackPop(MinStack* obj) {
    if(obj->cur_idx>-1){
        obj->cur_idx--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->cur_idx];
}

int minStackGetMin(MinStack* obj) {
    return obj->stack_min[obj->cur_idx];    
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

/*
typedef struct {
    
} MinStack;


MinStack* minStackCreate() {
    
}

void minStackPush(MinStack* obj, int val) {
    
}

void minStackPop(MinStack* obj) {
    
}

int minStackTop(MinStack* obj) {
    
}

int minStackGetMin(MinStack* obj) {
    
}

void minStackFree(MinStack* obj) {
    
}
*/
