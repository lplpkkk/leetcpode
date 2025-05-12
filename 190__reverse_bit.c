#define BIT(n)       (1U<<(n))


uint32_t reverseBits(uint32_t n) {

    uint32_t sum=0;
    
    for(unsigned int i=0;i<32;i++){
        sum+=( ( (n&BIT(i))>>i)<<(31-i));
    }
            
    
    return sum;
}
