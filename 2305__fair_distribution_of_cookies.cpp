/*
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int sum=accumulate(cookies.begin(),cookies.end(),0);
        int tar=sum/k;
        int len=cookies.size();
        int ans=INT_MAX;

        for(int i=0;i<(1<<len);i++){
            int sum=0;

            for(int j=0;j<len;j++){
                if(i&(1<<j)){
                    sum+=cookies[j];
                }
            }

            ans=min(ans,abs(sum-tar));

        }   

        return (tar+ans); 
    }
};
*/


class Solution {
public:
    vector<int> child;
    int len;
    int ans=INT_MAX;

    void dfs(vector<int> c,int idx){
        if(idx==c.size()){
            int unfair=*max_element(child.begin(),child.end());
            ans=min(ans,unfair);
            return;
        }

        for(int i=0;i<len;i++){
            child[i]+=c[idx];
            dfs(c,idx+1);
            child[i]-=c[idx];

            if(child[0]==0) break;
        }

    }

    int distributeCookies(vector<int>& cookies, int k) {
        len=k;
        
        sort(cookies.rbegin(),cookies.rend());
        child.assign(k,0);
        dfs(cookies,0);

        return ans;
    }
};
