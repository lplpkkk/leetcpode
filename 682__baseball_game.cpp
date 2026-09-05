class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> s;

        for(string str:op){
            char c=str[0];
            
            int len=s.size();

            if(c=='+'){
                if(len>=2){
                    int val=s.top();
                    s.pop();
                    int val2=s.top();
                    s.push(val);
                    s.push(val+val2);
                    
                }else if (len==1){
                    s.push(s.top());
                }
            }else if(c=='D'){
                if(len>0){
                    s.push(s.top()*2);
                }    
            }else if (c=='C'){
                if(len>0){
                    s.pop();
                }
            }else{
                s.push(stoi(str));
            }
        }

        int ans=0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }

        return ans;
    }
};
