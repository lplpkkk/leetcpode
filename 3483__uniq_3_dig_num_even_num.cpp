class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> seen;
        int n=digits.size();

        for(int i=0;i<n;i++){
            if(digits[i]==0) continue;

            for(int j=0;j<n;j++){
                if(j==i) continue;

                for(int k=0;k<n;k++){
                    if(k==j||k==i) continue;

                    if((digits[k]&1)==1) continue;

                    int num=100*digits[i]+10*digits[j]+digits[k];
                    seen.insert(num);
                }
            }

        }
        return seen.size();
    }
};
