class Solution {
public:

    string add(string& a, string& b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans;

        while(i >= 0 || j >= 0 || carry) {
            int val = carry;

            if(i >= 0)
                val += a[i--] - '0';

            if(j >= 0)
                val += b[j--] - '0';

            ans.push_back('0' + val % 10);
            carry = val / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool dfs(string num,int first_idx,int first_len,int second_len){
        int len=num.length();

        if(first_idx+first_len>=len) return false;
        if(first_idx+first_len+second_len>=len) return false;

        string sub=num.substr(first_idx,first_len);
        int second_idx=first_idx+first_len;
        string sub2=num.substr(second_idx,second_len);
        string sum = add(sub,sub2);
        
        int third_len=sum.length();
        int third_idx=second_idx+second_len;

        if(third_idx+third_len>len) return false;

        if(first_len > 1 && num[first_idx] == '0')
            return false;

        if(second_len > 1 && num[second_idx] == '0')
            return false;
           
        string to_chk=num.substr(third_idx,third_len);

        if(to_chk!=sum){
            return false;
        }

        if(third_idx+third_len==(len)){
            return true;
        }

        return dfs(num,second_idx,second_len,third_len);
        
    }

    bool isAdditiveNumber(string num) {
        int len=num.length();

        if(len<3) return false;

        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                if(dfs(num,0,i,j)){
                    return true;
                }
            }
        }    

        return false;  
    }
};
