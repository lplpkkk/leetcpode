#if(1)
bool isvow(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int numofvow(char *s){
    int len=strlen(s);
    int cnt=0;

    for(int i=0;i<len;i++){
        if(isvow(s[i])) cnt++;
    }

    return cnt;
}

bool doesAliceWin(char* s) {
    int target=numofvow(s);
    if(target){
        return true;
    }else{
        return false;
    }
}
#endif
