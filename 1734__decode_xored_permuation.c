/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int* returnSize) {
    int* ans=malloc(sizeof(int)*(encodedSize+1));
    *returnSize=encodedSize+1;
    
    int xor_val=0;
    for(int i=1;i<=(encodedSize+1);i++){
        xor_val^=i;
    }

    int xor_val_except0=0;
    for(int i=1;i<encodedSize;i+=2){
        xor_val_except0^=encoded[i];
    }
    
    ans[0]=xor_val^xor_val_except0;

    for(int i=1;i<=encodedSize;i++){
        ans[i]=ans[i-1]^encoded[i-1];
    }

    return ans;
}
