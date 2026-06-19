class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        long long maxv=0;
        long long tmp=0;

        for(auto& g:gain){
            tmp+=g;
            maxv=max(maxv,tmp);    
        }

        return (int)maxv;
    }
};
