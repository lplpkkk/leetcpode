
int getSum(int a, int b) {
    unsigned int carry;

    while(b!=0){
        carry= (unsigned)(a&b)<<1;
        a^=b;
        b=carry;
    }
    
    return a;
}
