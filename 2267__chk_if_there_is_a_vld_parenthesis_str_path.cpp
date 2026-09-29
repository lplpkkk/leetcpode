class Solution {
public:
    int m_lim;
    int n_lim;
    vector<vector<vector<int>>> memo;

    bool dfs(int m,int n,int bal,vector<vector<char>>& grid){
        if(m>=m_lim || n>=n_lim) return false;

        bal+=(grid[m][n]=='(');
        bal-=(grid[m][n]==')');

        if(m==(m_lim-1)&&n==(n_lim-1)){
            if(bal==0) return true;
        }

        if(bal<0) return false;

        if(memo[m][n][bal]!=-1) return memo[m][n][bal];

        bool right=dfs(m,n+1,bal,grid);
        bool down=dfs(m+1,n,bal,grid);
        
        return memo[m][n][bal]=(right|down);      
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m_lim=grid.size();
        n_lim=grid[0].size();
        int max_bal = m_lim + n_lim;

        memo.assign(
            m_lim,
            vector<vector<int>>
                (
                    n_lim,
                    vector<int>(max_bal+1,-1)
                )
            );

        return dfs(0,0,0,grid);
    }
};
