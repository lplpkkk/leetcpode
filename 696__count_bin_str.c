int countBinarySubstrings(char* s) {
    int prev=0;
    int cur=1;    
    int ans=0;
    int len=strlen(s);

    for(int i=1;i<len;i++){
        if (s[i]==s[i-1]){
            cur+=1;
        }else{
            prev=cur;
            cur=1;
        }

        if(prev>=cur){
            ans+=1;
        }
    }
    return ans;
}
