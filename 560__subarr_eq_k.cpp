//1,1,1
//1,2,3
//prefix problem
//prefix_a-prefix_b==k
//          |
//           check if this is in hash map

//k+cur

//[       ]    
//---------

//sum[i,j]=prefix_j-1-prefix_i
// prefix_i = prefix_j-1 -k

//mp
// 1,2
// 1,1
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;

        int cur_sum=0;
        int ans=0;

        for (int num:nums){
            cur_sum+=num;
            if(mp.count(cur_sum-k)){
                ans+=mp[cur_sum-k];
            }
            //prefix sum of this idx
            mp[cur_sum]+=1;
        }    

        return ans;
    }
};
