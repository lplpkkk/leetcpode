int fast_abs(int x){
    int mask=x>>31;
    return (x+mask)^mask;
}

void ut(){
    printf(" data=%d, abs(data)=%d\n", INT_MAX, fast_abs(INT_MAX));
    printf(" data=%d, abs(data)=%d\n", -1, fast_abs(-1));
    printf(" data=%d, abs(data)=%d\n", 20, fast_abs(20));
    return;
}

bool isPalindrome(int x) {
    
    int dig[11]={0};
    int cur_dig=0;
    int this_dig=0;

    if(x<0){
        return false;
    }
    
    x=fast_abs(x);
    

    do{
        this_dig=x%10;         //0
        dig[cur_dig]=this_dig; //dig[0]=0, lsd
        x/=10;                 //1
        cur_dig++;             //0-->1
        //printf(" cur_dig = %d\n", cur_dig); 
    }while(x>0);

    
    //odd --> cur_dig is even
    if((cur_dig&1)==1){
        for(int i=0;i<=cur_dig/2;i++){ //i=0 
            //printf(" cur_dig = %d, %d\n", (cur_dig/2)+i, (cur_dig/2)-i); 
            if(dig[(cur_dig/2)+i]!=dig[(cur_dig/2)-i]){
                return false;
            }
        }
    }else{
        //even, (max+1)/2+i <--r 
        // x x x x
        //     |
        // x x
        //   |
        // | 
        // ((max+1)/2-1) -i  <-- l 
        int l=(cur_dig/2)-1;
        int r=(cur_dig/2);

        for(int i=0;i<=l;i++){
            if(dig[l-i]!=dig[r+i]){
                return false;
            }
        }
    }
    


    return true;
}
