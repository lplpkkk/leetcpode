/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #if(0) //bruce force TLE
int* prisonAfterNDays(int* cells, int cellsSize, int n, int* returnSize) {
    
    int* ans=malloc(sizeof(int)*cellsSize);
    *returnSize=cellsSize;
    int* this=malloc(sizeof(int)*cellsSize);

    memcpy(ans,cells,sizeof(int)*cellsSize);
    memcpy(this,cells,sizeof(int)*cellsSize);
    
    for(int i=0;i<n;i++){
        memcpy(this,ans,sizeof(int)*cellsSize);
        for(int j=0;j<cellsSize;j++){
            //boundary case
            if((j==0) ||(j==(cellsSize-1))){
                this[j]=0;
            }else{
                if((ans[j-1]^ans[j+1])==0){
                    this[j]=1;
                }else{
                    this[j]=0;
                }
            }
        }
        memcpy(ans,this,sizeof(int)*cellsSize);
    }

    return ans;
}
#endif
#define BIT(x) (1u<<x)
int encode(int* cells){
    int ans=0;

    for(int i=0;i<8;i++){
        ans+=((cells[i])<<i);
    }

    return ans;
}

void decode(int* cells, int val){
    for(int i=0;i<8;i++){
        cells[i]=(val&BIT(i))>>i;
    }
}

int next_state(int* cells){
    int ans=0;

    for(int i=1;i<7;i++){
        if((cells[i-1]^cells[i+1])==0){
            ans+=(1<<i);
        }
    }    
    return ans;
}

int* prisonAfterNDays(int* cells, int cellsSize, int n, int* returnSize) {
    int seen[256]={0};
    int state=encode(cells);

    for(int i=0;i<n;i++){
        // find cycle here
        if(seen[state]){
            int cycle=i-seen[state]+1;
            int remain=(n-i)%cycle;
            decode(cells,state);
            return prisonAfterNDays(cells, cellsSize, remain, returnSize);
        }        

        seen[state]=i+1;//record this day

        int tmp[8];
        decode(tmp,state);
        state=next_state(tmp);
    }

    decode(cells,state);
    *returnSize=8;
    int* ans=malloc(sizeof(int)*cellsSize);
    memcpy(ans,cells,sizeof(int)*cellsSize);
    return ans;
}
