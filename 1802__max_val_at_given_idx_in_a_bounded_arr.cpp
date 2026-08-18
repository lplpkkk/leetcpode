class Solution {
public:

    long long sidesum(long long x,long long cnt){
        if(x-1>=cnt){
            long long first=(x-1);
            long long last=(x-cnt);
            return (first+last)*cnt/2;
        }else{
            long long descending=(x-1)*x/2;
            long long left=(cnt-(x-1));
            return descending+left;
        }
    }

    int maxValue(int n, int i, int maxSum) {
        long long l=1,r=maxSum;    
        while(l<r){
            long long m=l+(r-l+1)/2;
            long long total=m+sidesum(m,i)+sidesum(m,n-i-1);

            if(total<=maxSum){
                l=m;
            }else{
                r=m-1;
            }
        }

        return l;
    }
};
