class Solution {
public:
    int minPartitions(string n) {
        int len=n.length();
        int max_dig=0;

        while(len){
            if((n[len-1]-'0')>max_dig){
                max_dig=(n[len-1]-'0');
            }
            len-=1;
        }

        return max_dig;
    }
};
