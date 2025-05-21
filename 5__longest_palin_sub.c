#if(0)
#define Z1_OFF 0
#define Z2_OFF 10
#define Z3_OFF 10+26

typedef struct tmp_table{
    char* palin_start;
    char len;
    char is_palin;
}tb_t;

tb_t tb[62];

void init_tb(tb_t (*tb)){
    for(int i=0;i<62;i++){
        tb[i].palin_start=NULL;
        tb[i].len=0;
        tb[i].is_palin=0;
    }
    return;
}

char find_idx(char val){
    if((val-'a')>=0){
        return ((val-'a')+Z3_OFF);
    }else if ((val-'A')>=0){
        return ((val-'A')+Z2_OFF);
    }else{
        return ((val-'0')+Z1_OFF);
    }
}

void classify(tb_t *tb, char* cur){
    char idx=find_idx(*cur);
    int val=-1;

    // init case
    if(tb[idx].palin_start==NULL){
        tb[idx].palin_start=cur;
        tb[idx].is_palin=1;
        tb[idx].len=1;
    }else{
        val= *(tb[idx].palin_start);
        tb[idx].len++;

        if(val!=*cur){    
            tb[idx].is_palin=0;    
        }else{
            tb[idx].is_palin=1;
        }
    }
    
    return;
}

char* longestPalindrome(char* s) {
    init_tb(tb);
    int max=-1;
    int max_idx=0;

    for(int i=0;s[i];i++){
        classify(tb,(s+i));
    }

    for(int i=0;s[i];i++){
        if((tb[i].palin_start)!=NULL){
            if(tb[i].is_palin){
                if(tb[i].len>max){
                    max=tb[i].len;
                    max_idx=i;
                }
            }
        }
    }

    char* ans=malloc(sizeof(char)*tb[max_idx].len+1);
    memcpy(ans, tb[max_idx].palin_start, sizeof(char)*tb[max_idx].len);
    *(ans+tb[max_idx].len+1)='\0';
    
    
    return ans;
}
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Z1_OFF 0
#define Z2_OFF 10
#define Z3_OFF 10+26

typedef struct tmp_table {
    int last_seen_idx;
} tb_t;

tb_t tb[62];

void init_tb(tb_t* tb) {
    for(int i = 0; i < 62; i++) {
        tb[i].last_seen_idx = -1;
    }
}

char find_idx(char val){
    if(val >= 'a' && val <= 'z'){
        return ((val - 'a') + Z3_OFF);
    } else if (val >= 'A' && val <= 'Z'){
        return ((val - 'A') + Z2_OFF);
    } else { // digits
        return ((val - '0') + Z1_OFF);
    }
}

int expandAroundCenter(char* s, int left, int right) {
    int n = strlen(s);
    while(left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;  // 回文長度
}

char* longestPalindrome(char* s) {
    int start = 0, max_len = 0;
    int len = strlen(s);
    
    init_tb(tb);

    for (int i = 0; i < len; i++) {
        // 記錄最近出現的字元
        tb[find_idx(s[i])].last_seen_idx = i;

        // Odd length
        int len1 = expandAroundCenter(s, i, i);
        // Even length
        int len2 = expandAroundCenter(s, i, i + 1);

        int cur_len = (len1 > len2) ? len1 : len2;
        if (cur_len > max_len) {
            max_len = cur_len;
            start = i - (cur_len - 1) / 2;
        }
    }

    char* result = (char*)malloc(max_len + 1);
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';

    return result;
}
