class Solution {
public:
    int maximumLengthSubstring(string s) {
        int cnt[26]={0};
        int left=0;
        int right=0;
        int len=0;

        while(right<s.size()){
            int r_idx=s[right]-'a';
            

            cnt[r_idx]++;

            while(cnt[r_idx]>2){
                int l_idx=s[left]-'a';
                cnt[l_idx]--;
                left++;
            }

            len=max(len,right-left+1);
            right++;
        }

        return len;
    }
};
