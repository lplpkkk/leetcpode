bool queryString(char* s, int n) {
    int target_max_len=0;
    int tmp=n;
    while(tmp){
        target_max_len++;
        tmp>>=1;
    }

    int s_len=strlen(s);
    int val=0;
    //int seen[n+1];
    int cnt=0;
    //memset(seen,0,sizeof(int)*(n+1));
    int* seen = (int*)calloc(n + 1, sizeof(int));



    for(int i=0;i<s_len;i++){
        val=0;
        for(int j=0;j<target_max_len && ((i+j)<s_len);j++){
            val=(val<<1)+s[i+j]-'0';
            if((val>=1) && (val<=n) && !seen[val]){
                seen[val]=1;
                cnt++;
                if(cnt==n){
                    return true;
                }               
            }
        }
    }

    return false;
}
