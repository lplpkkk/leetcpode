char* simplifyPath(char* path) {
    char* stack[3001];
    int len=strlen(path);
    int i=0;
    int stack_idx=0;

    //parse data to stack
    while(i<len){
        while(i<len && path[i]=='/'){
            i++;
        }
        if(i>=len){
            break;
        }

        int start=i;
        while(i<len && path[i]!='/'){
            i++;
        }
        int end=i;
        int this_len=end-start;
        char this_s[this_len+1];
        strncpy(this_s,path+start,this_len);
        this_s[this_len]='\0';

        if(strcmp(this_s,"..")==0){
            if(stack_idx>0){
                stack_idx--;
            }
        }else if(strcmp(this_s,".")==0){
            continue;
        }else{
            stack[stack_idx++]=strdup(this_s);
        }
    }
    
    if(stack_idx==0){
        return strdup("/");
    }

    char* ans=malloc(3001);
    int offset=0;
    for(int i=0;i<stack_idx;i++){
        ans[offset]='/';
        strcpy(ans+offset+1,stack[i]);
        offset+=(strlen(stack[i])+1);
        free(stack[i]);
    }
    ans[offset]='\0';

    return ans;
}
