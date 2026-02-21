class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_len=s.size();
        int word_len=words[0].size();
        int cur_word=0;
        int left=0;
        int total_words=words.size();
        vector<int> res;

        //record the word freq
        unordered_map<string,int> map;
        for(string word:words){
            map[word]+=1;
        }
        
        //loop each offset
        for(int i=0;i<word_len;i++){
            unordered_map<string,int> window;
            left=i;
            cur_word=0;

        //  loop each word
            for(int j=i;(j+word_len)<=s_len;j+=word_len){
                string substr=s.substr(j,word_len);

                if(map.count(substr)){
                    window[substr]+=1;
                    cur_word+=1;

        //      if word freq is greater than word freq, adjust window                        
                    while(window[substr]>map[substr]){
                        string leftstr=s.substr(left,word_len);
                        window[leftstr]-=1;
                        cur_word-=1;
                        
                        left+=word_len;
                    }
                
                    if(cur_word==total_words){
                        res.push_back(left);
                    }

                }else{
                    //clear the window, reset l
                    window.clear();
                    cur_word=0;
                    left=j+word_len;
                }
            }
        }

        return res;
    }
};
