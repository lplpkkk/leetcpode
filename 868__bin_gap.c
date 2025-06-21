int binaryGap(int n) {
    int max=0;
    for(int i=0;i<32;i++){
        if((n>>i)&1){
            for(int j=(i+1);j<32;j++){
                if((n>>j)&1){
                    
                    if((j-i)>max){
                        max=(j-i);
                    }
                    break;
                }
            }
        }
    }
    return max;
}
