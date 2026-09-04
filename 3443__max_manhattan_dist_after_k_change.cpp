class Solution {
public:
    int maxDistance(string s, int k) {
        vector<int> vert(2);
        vector<int> hor(2);

        int ans=0;

        for(char c:s){
            switch(c){
                case 'N':
                    vert[0]++;
                    break;
                case 'S':
                    vert[1]++;
                    break;
                case 'E':
                    hor[0]++;
                    break;
                case 'W':
                    hor[1]++;
                    break;
                default:
                    assert(false);    
            };

            int base=abs(vert[0]-vert[1])+abs(hor[0]-hor[1]);
            int bad=min(vert[0],vert[1])+min(hor[0],hor[1]);

            int use=min(k,bad);

            ans=max(ans,base+2*use);
        }

        return ans;
    }
};ˇ
