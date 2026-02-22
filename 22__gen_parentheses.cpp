class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;

        bt(n,0,0,s,res);
        return res;
    }

private:
    void bt(int n, int l_cnt, int r_cnt, string& s, vector<string>& res){
        if(s.length()==2*n){
            res.push_back(s);
            return;
        }
        
        if (l_cnt<n){
            s.push_back('(');
            bt(n, l_cnt+1, r_cnt, s, res);
            s.pop_back();
            
        }

        if( l_cnt>r_cnt){
            s.push_back(')');
            bt(n, l_cnt, r_cnt+1, s, res);
            s.pop_back();
        }
    }
};

/*
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> res;

        bt(s,n,res);
        return res;        
    }
private:
    void bt(string s, int n, vector<string> res){
        if (chk(s)==false){
            return;
        }

        if(s.length()==(n<<1)){
            res.push_back(s);
        }

        for(int i=0;i<2;i++){
            if(i==0){
                s.append("(");
            }else{
                s.append(")");
            }
            bt(s,n,res);
            s.erase_last();
        }
    }

    bool chk(string s, int lim){
        int len=s.length();
        int cnt_front=0;
        int cnt_end=0;

        for(int i=0;i<len;i++){
            if (s[i]=='('){
                cnt_front++;
            }else{
                cnt_end++;
            }
            if (cnt_end>cnt_front ||
                cnt_front>lim ||
                cnt_end>lim
            ){
                return false;
            })
        }
        return true;
    }
};
*/
