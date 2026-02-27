/*
class Solution {
public:
    int minOperations(string s, int k) {
        int n=s.length();
        int c0=0;
        for(char c:s){
            if(c=='0') c0++;
        }
        if(c0==0) return 0;

        queue<int> q;
        q.push(c0);

        //record state count
        vector<int> dist(n+1,-1);
        dist[c0]=0;

        while(!q.empty()){
            int cur0=q.front();
            q.pop();
            
            if(cur0==0){
                return dist[0];
            }
        
            int min_i=max(0,k-cur0);//
            int max_i=min(k,n-cur0);

            for(int i=min_i;i<=max_i;i++){
                int next_c0=cur0 +i-(k-i);
                if(next_c0>=0&&next_c0<=n&&dist[next_c0]==-1){
                    q.push(next_c0);
                    dist[next_c0]=dist[cur0]+1;
                }
            }
        }
        return -1;

    }
};
*/

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int c0 = 0;
        for (char c : s) if (c == '0') c0++;
        if (c0 == 0) return 0;

        // 將尚未訪問的狀態按奇偶性分開存儲
        set<int> unvisited[2];
        for (int i = 0; i <= n; ++i) {
            unvisited[i % 2].insert(i);
        }

        queue<int> q;
        q.push(c0);
        unvisited[c0 % 2].erase(c0);
        
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();

                if (curr == 0) return steps;

                // 計算下一狀態的範圍
                int min_i = max(0, k - curr);
                int max_i = min(k, n - curr);
                int min_next = curr + min_i - (k - min_i);
                int max_next = curr + max_i - (k - max_i);

                // 決定要搜尋哪一個奇偶性的集合
                int parity = min_next % 2;
                auto& st = unvisited[parity];
                
                // 使用 lower_bound 快速找到範圍內第一個未訪問的狀態
                auto it = st.lower_bound(min_next);
                while (it != st.end() && *it <= max_next) {
                    q.push(*it);
                    it = st.erase(it); // 刪除已訪問狀態，避免重複搜尋
                }
            }
            steps++;
        }
        return -1;
    }
};
