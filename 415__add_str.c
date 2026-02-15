#define MAX(a,b) (((a)>(b))?(a):(b))

char* addStrings(char* num1, char* num2) {
    int len1=strlen(num1);
    int len2=strlen(num2);
    //extra carry bit and terminal bit
    int len=MAX(len1,len2)+1;
    int carry=0;
    char* ans=malloc(len+1);
    ans[len]='\0';

    while(len1>0||len2>0||carry>0){
        if(len1>0){
            carry+=(num1[--len1]-'0');
        }
        if(len2>0){
            carry+=(num2[--len2]-'0');
        }
        ans[--len]=carry%10 +'0';
        carry/=10;
    }
    
    return ans+len;
}
