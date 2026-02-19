
long long calc(int k){
    return ((long long)k*(k+1))/2;
}

int countHomogenous(char* s) {
    int len=strlen(s);
    int cur=1;
    long long ans=0;
    int MOD =1e9+7;

    for(int i=0;i<len;i++){
        if(i>0&&s[i]==s[i-1]){
            cur+=1;
        }else{
            cur=1;
        }
        ans=(ans+(cur))%MOD;
    }
    

    return ans;
    
    
}
