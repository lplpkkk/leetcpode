int calculate(char* s) {
    int len=strlen(s);
    int ans=0;
    int sign=1;
    int num=0; //this is a temp value for current op

    int* result_stack=malloc(sizeof(int)*len);
    int* sign_stack=malloc(sizeof(int)*len);
    int top=-1;

    for(int i=0;i<len;i++){
        char c=s[i];
        if(isdigit(c)){
            num=num*10+(c-'0');
        }else if(c=='+'){
            ans+=sign*num;
            sign=1;
            num=0;
        }else if(c=='-'){
            ans+=sign*num;
            sign=-1;
            num=0;
        }else if(c=='('){
            top++;
            result_stack[top]=ans;
            sign_stack[top]=sign;
            ans=0;
            num=0;
            sign=1;
        }else if(c==')'){
            ans+=sign*num;
            num=0;
            ans=ans*sign_stack[top]+result_stack[top];
            top--;
        }
    }

    if(num!=0){
        ans+=sign*num;
    }

    free(sign_stack);
    free(result_stack);

    return ans;
}
