

int minFlips(int a, int b, int c){
    int ans=0;

    for(int i=0;i<32;i++){
        int bit_a=(a>>i)&1;
        int bit_b=(b>>i)&1;
        int bit_c=(c>>i)&1;

        if((bit_a|bit_b)==bit_c){
            continue;
        }
        
        if(bit_c){
            ans+=1;
        }else{
            ans+=(bit_a+bit_b);
        }
    }
    return ans;
}
