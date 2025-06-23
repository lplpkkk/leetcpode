char* longestCommonPrefix(char** strs, int strsSize) {

    int len=strlen(strs[0]);
    int srch_len=len;
    int cur_len;

    if(len==0){
        return "";
    }

    for(int i=1;i<strsSize;i++){
        cur_len=strlen(strs[i]);
        if(cur_len<srch_len ){
            strs[0][cur_len]='\0';
            srch_len=cur_len;
        }
        
        for(int j=0;j<srch_len;j++){
            if(strs[i][j]!=strs[0][j]){
                strs[0][j]='\0';
                srch_len=j;
            }
        }   
        
    }

    return strs[0];
}
