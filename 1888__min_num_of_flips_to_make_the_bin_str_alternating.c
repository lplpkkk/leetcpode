
//#define MIN(x,y) ((x<y)?(x):(y))
int minFlips(char* s) {
    int n=strlen(s);
    char* double_s=(char*)malloc(2*n+1);
    
    strcpy(double_s,s);
    strcat(double_s,s);

    int diff1=0;
    int diff2=0;
    int min_ans=n;

    for(int i=0;i<2*n;i++){
        if(double_s[i]-'0'!= (i%2)) diff1+=1;
        if(double_s[i]-'0'== (i%2)) diff2+=1;

        if(i>=n){
            int left=i-n;
            if(double_s[left]-'0'!=(left%2)) diff1-=1;
            if(double_s[left]-'0'==(left%2)) diff2-=1;
        }

        if(i>=n-1){
            min_ans=MIN(min_ans,MIN(diff1,diff2));
        }
    }

    free(double_s);
    return min_ans;
}
