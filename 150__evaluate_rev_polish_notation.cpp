class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>s;

        for(const string& t: tokens ){
            if (t=="+"||t=="-"||t=="*"||t=="/"){
                long long v2=s.top(); s.pop();
                long long v1=s.top(); s.pop();

                if(t=="+") s.push(v1+v2);
                else if(t=="-") s.push(v1-v2);
                else if(t=="*") s.push(v1*v2);
                else if(t=="/") s.push(v1/v2);

            }else{
                s.push(stoi(t));
            }
        }
        return (int)s.top();
    }
};


/*
class Solution {
private:
    char special_op[]={'+','-','*','/'};
public:
    int evalRPN(vector<string>& tokens) {
        stack<char> s;
        int len=tokens.size();
        for(int i=0;i<size;i++){
            char this=isdigit(tokens[i])? strtoval(tokens[i]):tokens[i];
            if (is_special(this)){
                //stack.pop=v2
                //stack.pop=v1
                //stack.push(v1 op v2)
            }else{
                //stack.push(this)
            }
        }
        return stack.front();
    }
};
*/
