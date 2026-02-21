class Solution {
private:
    int freq[128];
public:
    string minWindow(string s, string t) {
        int t_len=t.size();
        int s_len=s.size();
        int req_cnt=t_len;
        int l=0;
        int win[128]={0};
        string ans;
        int min_len=INT_MAX;
        int start_ops=0;
        

        //init map for char count in t
        memset(freq,0,sizeof(freq));
        for(int i=0;i<t_len;i++){
            freq[t[i]]+=1;
        }
        
        //for loop to check if req_cnt is satisfied
        for(int i=0;i<s_len;i++){
            if (freq[s[i]]>0){
                win[s[i]]+=1;
                if(win[s[i]]<=freq[s[i]]){
                    req_cnt-=1;
                }
            }

            while(req_cnt==0){
                if (i-l+1<min_len){
                    min_len=(i-l+1);
                    start_ops=l;
                }

                //adjust l
                char l_ch=s[l];
                if(freq[l_ch]>0){
                    if(win[l_ch]==freq[l_ch]){
                        req_cnt+=1;
                    }
                    win[l_ch]-=1;
                }
                l+=1;
            }
        }

        return (min_len==INT_MAX)?"":s.substr(start_ops,min_len);
    }
};
