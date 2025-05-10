int lengthOfLongestSubstring(char* s) {

    int ascii_last[128];
    int j=0;

    for(int i=0;i<128;i++){
        ascii_last[i]=-1;
    }

    if(s==NULL){
        return 0;
    }

    int start=0;
    char*r=s;
    int max_len=0;

    while(*(r+j)!='\0'){
        if(ascii_last[*(r+j)]>=start){
            start=ascii_last[*(r+j)]+1;
        }

        ascii_last[*(r+j)]=j;
        int len = j-start+1;

        if(len>max_len){
            max_len=len;
        }

        j++;
    }

    return max_len;
    
}
