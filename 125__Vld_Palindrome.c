
#if(0)
int isUpperLetter(char c){
    return ((c>='A') && (c<='Z'));
}

int isLowerLetter(char c){
    return ((c>='a') && (c<='z'));
}

int isnumber(char c){
    return ((c>='0') && (c<='9'));
}
#define LETTER_OFFSET ('a'-'A')

char*  parse_and_rm(char* s){
    char* after_par = malloc(strlen(s)+1);
    int cur_idx=0;

    for (int i=0;i<strlen(s);i++){
        if (isLowerLetter(*(s+i)) || isnumber(*(s+i))){
            after_par[cur_idx]=*(s+i);
            cur_idx++;
        }else if (isUpperLetter(*(s+i))){
            after_par[cur_idx]=*(s+i)+LETTER_OFFSET;
            cur_idx++;
        }else{
            //do nothing
        }
    }

    after_par[cur_idx]='\0';

    return after_par;
}

void dbg(char* s){
    for(int i=0;i<strlen(s);i++){
        printf(" %c ",*(s+i));
    }
    printf("\n");
}


bool isPalindrome(char* s) {
    dbg(s);
    char* par = parse_and_rm(s);
    dbg(par);
    int ans=1;
    int len=strlen(par);

    for(int i=0;i<len/2;i++){
        printf("cmp front(%d)=%c, back(%d)=%c\n", i,*(par+i),len-i,*(par+len-i));
        if (*(par+i) != *(par+len-i-1)){
            ans=0;
            break;
        }
    }

    return ans;
}

#else
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int isUpperLetter(char c) {
    return (c >= 'A' && c <= 'Z');
}

int isLowerLetter(char c) {
    return (c >= 'a' && c <= 'z');
}

int isNumber(char c) {
    return (c >= '0' && c <= '9');
}

int isAlphaNumeric(char c) {
    return isUpperLetter(c) || isLowerLetter(c) || isNumber(c);
}

char toLower(char c) {
    if (isUpperLetter(c)) return c + ('a' - 'A');
    return c;
}

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isAlphaNumeric(s[left])) left++;
        while (left < right && !isAlphaNumeric(s[right])) right--;

        if (toLower(s[left]) != toLower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

#endif
