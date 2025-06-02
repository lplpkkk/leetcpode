/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct map{
    char dig;
    char idx;
}map;


char* map_data[8]={
"abc",
"def",
"ghi",
"jkl",
"mno",
"pqrs",
"tuv",
"wxyz",
} ;

char* get_mapping_data(char d){
    return map_data[d-'2'];
}

char** letterCombinations(char* digits, int* returnSize) {
    int len=strlen(digits);
    int max_num=1;

    if(len==0){
        *returnSize=0;
        return NULL;
    }

    for(int i=0;i<len;i++){
        max_num*=strlen(get_mapping_data(digits[i]));// total permuation num
    }

    char** ans=malloc(sizeof(char*)*max_num);
    for(int i=0;i<max_num;i++){
        ans[i]=malloc(len+1);
        ans[i][len]='\0';
    }

    for(int i=0;i<max_num;i++){//total
        int this_perm=i;

        for(int j=0;j<len;j++){//len of digit
            char* m_str=get_mapping_data(digits[j]);
            int cnt=strlen(m_str);
            ans[i][j]= m_str[this_perm%cnt];
            this_perm/=cnt;
        }
        
    }

    *returnSize=max_num;
    return ans;
}
