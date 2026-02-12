char* removeKdigits(char* num, int k) {
    int len=strlen(num);

    char* stack=malloc(len+1);
    int top=0;
    for(int i=0;i<len;i++){
        char c=num[i];

        while(top>0&&k>0&&stack[top-1]>c){
            top--;
            k--;
        }
        
        stack[top++]=c;
    }

    top-=k;
    stack[top]='\0';

    int start=0;
    while(start<top&&stack[start]=='0'){
        start++;
    }

    if(start==top){
        stack[0]='0';
        stack[1]='\0';
        return stack;
    }

    if(start>0){
        memmove(stack,stack+start,top-start+1);
    }
    
    return stack;
}
/*
void push(char* stack, int* idx, char val){
    stack[*idx++]=val;
    return;
}

void pop(char* stack, int* idx){
    if (*idx>1){
        stack[*idx--];
    }
    return;
}

char* removeKdigits(char* num, int k) {
    int len=strlen(num);
    char* stack=malloc(sizeof(char)*(len-k));
    int last_idx=0;
    stack[last_idx]='9'+1;//biggest

    for(int i=0;i<len;i++){
        //keep the min (n-k) 
        if (num[i]<stack[last_idx]){
            pop(stack,&last_idx);
            push(stack,&last_idx,num[i]);
        }else{
            if (last_idx<(len-k)){
                push(stack,&last_idx,num[i]);    
            }
        }
    }

    return stack;
}
*/
