class Solution {

private:
    //int ans=0;
    //int dir[4][2]={ {-1,0},{0,-1},{1,0},{0,1}};
    
public:
#if(0)
    void dfs(string s, int idx, int hor, int vert){
        if(idx>=s.length()){
            return;
        }    
        
        int this_hor=0;
        int this_vert=0;
        bool normal=true;

        if(s[idx]=='U'){
            this_vert+=1;
        }else if(s[idx]=='D'){
            this_vert-=1;
        }else if(s[idx]=='L'){
            this_hor-=1;
        }else if(s[idx]=='R'){
            this_hor+=1;
        }else{
            normal=false;
        }
    
        if(normal){
            ans=max(ans, abs(hor+this_hor)+abs(vert+this_vert));
            dfs(s,idx+1,hor+this_hor,vert+this_vert);
        }else{
            for(int i=0;i<4;i++){
                ans=max(ans,abs(hor+dir[i][0])+abs(vert+dir[i][1]));
                dfs(s,idx+1,hor+dir[i][0],vert+dir[i][1]);
            }
        }
        
    }
#endif

    int maxDistance(string moves) {
        int hor=0;
        int vert=0;
        int arb=0;

        for(char c: moves){
            if(c=='U'){
                vert+=1;
            }else if(c=='D'){
                vert-=1;
            }else if(c=='L'){
                hor-=1;
            }else if(c=='R'){
                hor+=1;
            }else{
                arb+=1;
            }
        }    

        return (abs(vert)+abs(hor)+arb);

    }
};
