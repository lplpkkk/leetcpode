class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int len=seq.length();
        vector<int> ans(len);

        int bal=0;
        for(int i=0;i<len;i++){
            char c=seq[i];

            if (c=='('){
                bal++;
                ans[i]=bal%2;
                
            }else{
                ans[i]=bal%2;
                bal--;
            }
        }

        return ans;
    }
};
