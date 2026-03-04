bool ispali(char*s, int l, int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

bool validPalindrome(char* s) {
    int len=strlen(s);
    int l=0;
    int r=len-1;

    while(l<r){
        if(s[l]!=s[r]){
            return (ispali(s,l+1,r) || ispali(s,l,r-1));
        }
        l++;
        r--;
    }

    return true;
}
