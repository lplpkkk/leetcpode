
#define BIT(x) (1u<<x)
int hammingDistance(int x, int y) {
    int data= x^y;
    int ans=0;

    for(int i=0;i<32;i++){
        ans+=((data>>i)&1);    
    }

    return ans;
}
