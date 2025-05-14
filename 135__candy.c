int candy(int* ratings, int ratingsSize) {
    int* c=malloc(sizeof(int)*ratingsSize);
    for (int i = 0; i < ratingsSize; i++) {
        c[i] = 1;
    }


    for(int i=1;i<ratingsSize;i++){
        if(ratings[i]>ratings[i-1]){
            c[i]=c[i-1]+1;
        }
    }

    for(int i=(ratingsSize-2);i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            if (c[i] < c[i + 1] + 1) {
                c[i] = c[i + 1] + 1;
            }
        }
    }

    

    int total=0;
    for(int i=0;i<ratingsSize;i++){
        total+=c[i];
    }   
    
    free(c);

    return total;
}
