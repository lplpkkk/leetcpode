/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool is_lower_letter(char c){
    if((c>='a')&&(c<='z')){
        return true;
    }
    return false;
}

bool is_upper_letter(char c){
    if((c>='A')&&(c<='Z')){
        return true;
    }
    return false;
}

bool is_letter(char c){
    if(is_lower_letter(c)||is_upper_letter(c)){
        return true;
    }
    return false;
}

int calc_letter(char* s){
    int len=strlen(s);
    int ans=0;
    for(int i=0;i<len;i++){
        if(is_letter(*(s+i))){
            ans++;
        }
    }
    return ans;
}

#define LOWER_TO_UPPER_OFF ('a'-'A')

char toggle_letter(char c){
    if(is_lower_letter(c)){
        return c-LOWER_TO_UPPER_OFF;
    }else if (is_upper_letter(c)){
        return c+LOWER_TO_UPPER_OFF;
    }
    return c;
}

char** letterCasePermutation(char* s, int* returnSize) {
    int all_letters=calc_letter(s);
    int comb_num=1<<all_letters;
    int len=strlen(s);
    int this_letter_idx=0;

    char** ans=malloc(comb_num*sizeof(char*));

    for(int i=0;i<comb_num;i++){

        char* this=malloc((len+1)*sizeof(char));//include end char
        this_letter_idx=0;

        for(int j=0;j<len;j++){
            /* only toggle when comb==1 */
            if((is_letter(*(s+j)))){
                if(i&(1<<this_letter_idx)){
                    *(this+j)=toggle_letter(*(s+j));
                }else{
                    *(this+j)=*(s+j);    
                }
                this_letter_idx++;
            }else{
                *(this+j)=*(s+j);
            }
        }

        *(this+len)='\0';
        *(ans+i)=this;
    }

    *returnSize = comb_num;

    return ans;
    
}
