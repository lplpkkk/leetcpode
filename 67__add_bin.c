char* addBinary(char* a, char* b) {
    int len_a=strlen(a);
    int len_b=strlen(b);
    int larger_len=(len_a>len_b)?len_a:len_b;

    char* ans = malloc(sizeof(char) * (larger_len + 2));
    ans[larger_len+1]='\0';
    int carry=0;
    int this_dig=0;

    while(larger_len){
        int this_dig=0;
        if(len_a>0){
            this_dig=this_dig+a[len_a-1]-'0';
            len_a--;
        }   
        if(len_b>0){
            this_dig=this_dig+b[len_b-1]-'0';
            len_b--;
        } 
        ans[larger_len]= ((this_dig+carry)&0x1)+'0';
        //printf("%d=%c\n",larger_len-1,ans[larger_len-1]);
        carry= ((this_dig+carry)/2);

        larger_len--;
    }

    
    
    if(carry){
        ans[0]='1';
        return ans;
    }else{
        char* new_ans=strdup(ans+1);
        free(ans);
        return (new_ans);
    }
    
}
