int lengthOfLastWord(char* s) {
    int len=strlen(s);
    int i=len-1;
    int word_len=0;

    while(i>=0 && s[i]==' '){
        i--;
    }

    while(i>=0 && s[i]!=' '){
        word_len++;
        i--;
    }

    return word_len;
}
