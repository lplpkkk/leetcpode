class Solution {
    static constexpr int mod = 1e9 + 7;
public:
    int max_depth=0;

    int qpow(int x, int y) {
        int res = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                res = 1ll * res * x % mod;
            }
            x = 1ll * x * x % mod;
        }
        return res;
    }

    void dfs(int node, int parent, int cur_depth, vector<vector<int>>& adj){
        max_depth=max(max_depth,cur_depth);
        
        for(int neighbor: adj[node]){
            if(neighbor!=parent){
                dfs(neighbor,node,cur_depth+1,adj);
            }
        }
        
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        //set the adjmap
        int n=edges.size()+1;
        vector<vector<int>> adj(n+1);
        
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        dfs(1,0,0,adj);

        return qpow(2,max_depth-1);
    }
};
