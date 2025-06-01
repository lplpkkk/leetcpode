/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 #if(0)
 // 6/1, 9:38

typdef struct map{
    int key; //sum
    int val; //idx of arrary
    UT_hash_handle hh;
}map;

int max_len=0;

int sum_the_str(char* str){
    int len=strlen(str);
    int sum=0;

    if(len>max_len){
        max_len=len;
    }

    for(int i=0;i<len;i++){
        sum+= (str[i]-'a');
    }
    return sum;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    int i=0;
    char * cur_str=NULL;
    int cur_sum=0;
    map* m=NULL;

    for(i=0;i<strsSize;i++){
        cur_str=strs[i];
        cur_sum=sum_the_str(cur_str);

        //hash
        map* found=NULL;
        HASH_FIND_INT(m, &cur_sum, found);
        if(found){
            //get the key to find val, use val to append to the ans arr
        }else{
            //add to hash map
            //add answer to the ans array           
        }
    }
}
#endif


typedef struct map{
    char* k;
    int idx; // group idx
    UT_hash_handle hh;
}map;

//strs[0] --"aaa"
//strs[1] .."bbb"
//     .
//     (strsSize-1)

//ans[0] .."ab"  
//       .."ba"  --> return colum_size[0]
//   .
//   [x] ..      --> return colum_size[x]
//   .
//    (rutrn_size)


int cmp(const void* a, const void*b){
    return (*(char*)a - *(char*)b);
}

char* get_sorted_str(char*s){
    char* tmp=malloc(sizeof(char)*strlen(s)+1);
    strcpy(tmp,s);

    qsort(tmp, strlen(tmp), sizeof(char),cmp);
    return tmp;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {

    char*** ans = malloc(sizeof(char**)* strsSize);
    *returnColumnSizes=malloc(sizeof(int)*strsSize);
    *returnSize=0;
    int i=0;
    map* m=NULL;
    char* str_k=NULL;
    int idx=0;

    for(i=0;i<strsSize;i++){
        str_k=get_sorted_str(strs[i]);
        map* found=NULL;
        HASH_FIND_STR(m,str_k,found);

        if(found){
            idx=found->idx;        
        }else{
            idx=*(returnSize);
            (*returnSize)++;
            ans[idx]=malloc(sizeof(char*)*strsSize);
            (*returnColumnSizes)[idx]=0;

            map* e=malloc(sizeof(map));
            e->k=str_k;
            e->idx=idx;
            HASH_ADD_STR(m,k,e);
        }   

        //copy data to the ans:
        ans[idx][ (*returnColumnSizes)[idx] ]=strs[i];
        (*returnColumnSizes)[idx]++;
    }
    
    map *cur_m, *tmp_m;
    HASH_ITER(hh,m,cur_m,tmp_m){
        HASH_DEL(m, cur_m);
        free(cur_m->k);
        free(cur_m);
    }

    return ans;
}
