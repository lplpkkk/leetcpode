
char* multiply(char* num1, char* num2) {
    if (*num1=='0' ||*num2=='0'){
        char* ans=malloc(2);
        ans[0]='0';
        ans[1]='\0';
        return ans;
    }
    int len1=strlen(num1);
    int len2=strlen(num2);
    int len=len1+len2;
    int* res=calloc(len+1,sizeof(int));

    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            int n1=num1[len1-1-i]-'0';
            int n2=num2[len2-1-j]-'0';
            int mul=n1*n2;
            int sum=mul+res[len-1-i-j];

            res[len-1-i-j]=sum%10;
            res[len-1-i-j-1]+=sum/10;
        }
    }

    char* ans=malloc(len+1);
    int idx=0;
    int i=0;
    while(i<len&&res[i]==0){
        i++;
    }

    while(i<len){
        ans[idx++]=res[i++]+'0';
    }
    
    ans[idx]='\0';
    free(res);
    return ans;


}

/*
#define MAX(a,b) (((a)>(b)?)(a):(b))

char* multiply(char* num1, char* num2) {
   int len1=strlen(num1);
   int len2=strlen(num2);
   int len=len1+len2+1;
   char* ans=malloc(len+1);
   ans[len]='\0';
    char* carry=malloc(len+1);
    memeset(carry,0,sizeof(carry));

    // "1234"
    // "  56"
    //     |

    for(int i=0;i<len1;i++){
        for(itn j=0;j<len2;j++){
            int mul=num1[len1-1-i]*num2[len2-1-j];
            
            //this digit
            carry[len-1-i-j]+=mul%10;
            //carry digigt
            carry[len-1-1-i-j]+=mul/10;
            int k=0;
            do while(carry[len-1-i-j-k]/10>0){
                carry[len-1-1-i-j-k]+=(carry[len-1-i-j-k]/10);
                k+=1;
            }

        }
    }

    for(int i=0;i<len;i++){
        carry[i]+='0';
    }

    return carry+len;
}
*/
