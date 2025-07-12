int similarPairs(char** words, int wordsSize) {
    //int mask[wordsSize]={0};
    int* mask=malloc(sizeof(int)*wordsSize);
    int count=0;

    for(int i=0;i<wordsSize;i++){
        mask[i]=0;
        int len=strlen(words[i]);
        for(int j=0;j<len;j++){
            mask[i]|=1<<(words[i][j]-'a');
        }
        
    }

    for(int i=0;i<wordsSize;i++){
        for(int j=(i+1);j<wordsSize;j++){
            if (mask[i]==mask[j]){
                count++;
            }
        }
    }   

    free(mask);

    return count;
}
