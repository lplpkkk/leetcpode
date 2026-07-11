/*
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //dsu, 創建vector, size=n, 都先自己連自己
        //for edges把dsu連一連
        //for 所有dsu確認是否complete component
    }
};
*/


class Solution {
public:
    vector<int> parent;
    vector<int> sz;

    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a, int b){
        int ra=find(a);
        int rb=find(b);

        if(ra==rb) return;

        if(sz[ra]<sz[rb]){
            swap(ra,rb);
        }

        parent[rb]=ra;
        sz[ra]+=sz[rb];
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sz.assign(n,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto&e:edges){
            unite(e[0],e[1]);
        }

        vector<int> nodecnt(n,0);
        vector<int> edgecnt(n,0);
        
        for(int i=0;i<n;i++){
            int root=find(i);
            nodecnt[root]++;
        }

        for(auto& e:edges){
            int root=find(e[0]);
            edgecnt[root]++;
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(find(i)!=i) continue;
            
            long long nodes=nodecnt[i];
            long long expectededge=nodes*(nodes-1)/2;

            if(edgecnt[i]==expectededge){
                ans++;
            }
        }

        return ans;
    }

};
