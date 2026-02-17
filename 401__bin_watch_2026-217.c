/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** result;
int count;

int v[]={1,2,4,8,1,2,4,8,16,32};

void dfs(int idx, int k, int hr, int min){
    if(hr>11||min>59){
        return;
    }    

   if (k==0){
        result[count]=malloc(6);
        sprintf(result[count],"%d:%02d",hr,min);
        count++;
        return;
    }

    if(idx==10){
        return;
    }

 

    if(idx<4){
        dfs(idx+1,k-1, hr+v[idx],min);
    }else{
        dfs(idx+1,k-1, hr,min+v[idx]);
    }
    dfs(idx+1,k,hr,min);
    
    return;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    //init
    result = malloc(1000 * sizeof(char*));
    count=0;
    dfs(0,turnedOn,0,0);        

    *returnSize=count;
    return result;
}
