class Solution {
    
public:
    vector<string> _stickers;
    string _target;
    int fullmask;
    vector<int> memo;

    int dfs(int mask){
        if(mask==fullmask) return 0;
    
        if(memo[mask]!=-1) return memo[mask];

        int ans=INT_MAX;
        
        for(auto& sticker:_stickers){
            vector<int> cnt(26,0);
            for(int i=0;i<sticker.length();i++) cnt[sticker[i]-'a']++;

            int newmask=mask;

            for(int i=0;i<_target.size();i++){
                if((newmask&(1<<i))==0){
                    int c=_target[i]-'a';
                    if(cnt[c]>0){
                        cnt[c]--;
                        newmask|=(1<<i);
                    }
                }
            }

            if(mask==newmask) continue;

            int next=dfs(newmask);

            if(next!=INT_MAX) ans=min(ans,1+next);
        }

        return memo[mask]=ans;
    }


    int minStickers(vector<string>& stickers, string target) {
        _stickers=stickers;
        _target=target;

        int n=_target.size();
        fullmask=(1<<n)-1;
        memo.assign(1<<n,-1);

        int ans=dfs(0);

        return ans==INT_MAX?-1:ans;
    }
};
