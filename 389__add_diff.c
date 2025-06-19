char findTheDifference(char* s, char* t) {
    int s_len=strlen(s);
    int sum=0;
    for(int i=0;i<s_len;i++){
        sum+=s[i];
    }
    
    int t_len=strlen(t);
    int sum2=0;
    for(int i=0;i<t_len;i++){
        sum2+=t[i];
    }

    if(sum>sum2){
        return sum-sum2;
    }else{
        return sum2-sum;
    }

}
