bool hasSameDigits(char* s) {
    int len=strlen(s);
    int *arr=malloc(len*sizeof(int));

    for (int i = 0; i < len; i++)
        arr[i] = s[i] - '0';

    while(len>2){
        for(int i=0;i<len-1;i++){
            arr[i]=(arr[i]+arr[i+1])%10;        
        }
        len--;
    }
    return(arr[0]==arr[1]);
}
