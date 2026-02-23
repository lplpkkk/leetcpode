class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //build adj table
        unordered_map<string, vector<pair<string,double>>>  adj;
        int len=equations.size();

        for(int i=0;i<len;i++){
            string u=equations[i][0];
            string v=equations[i][1];
            double value=values[i];

            adj[u].push_back({v,value});
            adj[v].push_back({u,1.0/value});
        }

        //handle queries
        vector<double> res;

        for(auto& q:queries){
            string start=q[0];
            string end=q[1];

            if ((adj.find(start)==adj.end())||(adj.find(end)==adj.end())){
                res.push_back(-1.0);
            }else if(start==end){
                res.push_back(1.0);
            }else{
                unordered_set<string> visited;
                res.push_back(dfs(start,end,adj,visited,1.0));
            }
        }

        return res;
    }
private:
    double dfs(string& cur, string& tar, unordered_map<string, vector<pair<string,double>>>& adj,
                unordered_set<string>& visited, double prod){

                visited.insert(cur);

                for(auto& neighbor: adj[cur]){
                    string next_node=neighbor.first;
                    double next_val=neighbor.second;

                    if(next_node==tar){
                        return prod*next_val;
                    }

                    if(visited.find(next_node)==visited.end()){
                        double res=dfs(next_node, tar, adj, visited, prod*next_val);
                        if(res!=-1){
                            return res;
                        }
                    }
                }
                return -1;
                
            }
};
