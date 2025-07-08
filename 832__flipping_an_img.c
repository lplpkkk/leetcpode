/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    int** ans=malloc(sizeof(int*)*imageSize);
    *returnSize=imageSize;
    *returnColumnSizes=malloc(sizeof(int)*imageSize); 

    for(int i=0;i<imageSize;i++){
        ans[i]=malloc(sizeof(int)*imageColSize[i]);
        (*returnColumnSizes)[i]=imageColSize[i];

        //reverse
        for(int j=0;j<imageSize;j++){
            ans[i][j]=image[i][imageSize-1-j];
            //invert
            ans[i][j]^=1;
        }
        
    }

    return ans;
}
