/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
    //x1 x2 x3 x4
    //  y  y  y
    int* ans=malloc(sizeof(int)*(encodedSize+1));
    *returnSize=(encodedSize+1);
    ans[0]=first;
    for(int i=1;i<=(encodedSize);i++){
        ans[i]=ans[i-1]^encoded[i-1];
    }

    return ans;
}
