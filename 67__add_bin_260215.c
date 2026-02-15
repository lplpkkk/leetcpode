#define MAX(a,b) (((a)>(b))?(a):(b))
char* addBinary(char* a, char* b) {
    int len_a=strlen(a);
    int len_b=strlen(b);
    int len=MAX(len_a,len_b);
    len+=1;
    char* ans=malloc(sizeof(char)*(len+1+1));
    int carry=0;

    ans[len]='\0';

    while(len_a>0||len_b>0||carry>0){
        if(len_a>0){
            carry+=a[--len_a]-'0';
        }
        if(len_b>0){
            carry+=b[--len_b]-'0';
        }
        ans[--len]=carry%2+'0';
        carry/=2;
    }

    return ans+len;
    
}
