int findTheLongestSubstring(char* s) {
    int first[32];//every perm

    for(int i=0;i<32;i++){
        first[i]=-2;
    }
    first[0]=-1;

    int len=strlen(s);
    int max_len=0;
    int mask=0;

    for(int i=0;i<len;i++){
        switch(s[i])    {
            case 'a': mask^=(1<<0); break;
            case 'e': mask^=(1<<1); break;
            case 'i': mask^=(1<<2); break;
            case 'o': mask^=(1<<3); break;
            case 'u': mask^=(1<<4); break;
        }

        if(first[mask]>=-1){
            int len= i - first[mask];
            if(len>max_len){
                max_len=len;
            }
        }else{
            first[mask]=i;
        }
    }    
    
    return max_len;
}
