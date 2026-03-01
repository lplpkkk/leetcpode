bool isPalindrome(char* s) {
    int len=strlen(s);
    int l=0;
    int r=len-1;

    while(l<r){
        while(l<r && !isalnum(s[l])) l++;
        while(l<r && !isalnum(s[r])) r--;

        char left=(s[l]>='A'&&s[l]<='Z')?(s[l]+32):s[l];
        char right=(s[r]>='A'&&s[r]<='Z')?(s[r]+32):s[r];

        if(left!=right){
            return false;
        }

        l++; r--;
    }

    return true;
    
}
