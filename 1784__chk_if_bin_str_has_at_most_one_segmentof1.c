bool checkOnesSegment(char* s) {
    int len=strlen(s);

    for(int i=1;i<len;i++){
        if(s[i-1]=='0' && s[i]=='1'){
            return false;
        }
    }

    return true;
}
