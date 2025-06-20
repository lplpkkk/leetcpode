 const char *hex = "0123456789abcdef";

char* toHex(int num) {
    if(num==0){
        char* ans=malloc(2);
        ans[0]='0';
        ans[1]='\0';
        return ans;
    }

    unsigned int u=(unsigned int)num;

    //32b=2^32=16^8
    char* ans=malloc(9);
    ans[8]='\0';
    int idx=8;

    while(u){
        int d=u&0xf;
        ans[--idx]=hex[d];
        u>>=4;
    }
    
    int len=8-idx;
    memmove(ans,ans+idx,len+1);

    return ans;
}
