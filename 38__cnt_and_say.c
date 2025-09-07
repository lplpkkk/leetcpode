
char* describe(char* s){
    int len=strlen(s);
    char* buf=malloc(len*2+1);
    int idx=0;

    for(int i=0;i<len;){
        char c=s[i];
        int cnt=0;

        while(s[i]==c && i<len){
            cnt++;
            i++;
        }

        idx+=sprintf(buf+idx,"%d%c",cnt,c);
    }
    buf[idx]='\0';

    return buf;
}


char* countAndSay(int n) {
    if(n==1){
        char* base=malloc(2);
        strcpy(base,"1");
        return base;
    }

    char* prev=countAndSay(n-1);
    char* cur=describe(prev);

    free(prev);
    return cur;
}

