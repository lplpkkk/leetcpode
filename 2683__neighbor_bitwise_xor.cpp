class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int v=0;

        for(int n:derived){
            v^=n;
        }

        return (v==0);
    }
};
