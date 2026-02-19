int findSubstringInWraproundString(char* s) {
    int cnt[26]={0};
    int len=strlen(s);
    int cur=1;
    int ans=0;

    for(int i=0;i<len;i++){
        if(i>0&&((s[i]==s[i-1]+1)||(s[i]=='a'&&s[i-1]=='z'))){
            cur+=1;
        }else{
            cur=1;
        }
        int idx=s[i]-'a';
        if(cur>cnt[idx]){
            cnt[idx]=cur;
        }
    }
    
    for(int i=0;i<26;i++){
        ans+=cnt[i];
    }

    return ans;
}
