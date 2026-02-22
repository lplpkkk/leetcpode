class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> currentline;
        int cur_width=0;

        for(string & word: words){
            //condition for checking enough space for this word
            if(cur_width+ currentline.size()+ word.length()>maxWidth){
               res.push_back( formatline(currentline, cur_width, maxWidth, false));
               cur_width=0;
               currentline.clear();
            }
            currentline.push_back(word);
            cur_width+=word.length();
        }

        //last one
        res.push_back(formatline(currentline,cur_width, maxWidth, true));

        return res;

    }

private:
    string formatline(vector<string>& line, int cur_width, int lim, bool islast){
        string res="";
        int num_words=line.size();
        int space=lim-cur_width;

        //case1: last
        if(islast||num_words==1){
            for(int i=0;i<num_words;i++){
                //res+=line[i];
                res.append(line[i]);
                if(i<num_words-1){
                    res+=" ";
                }
            }
            //res+=string(lim-res.length(),' ');
            res.append(string(lim-res.length(),' '));
        }else{//evenly
            int space_between=space/(num_words-1);
            int extra_space=space%(num_words-1);
            int gap_cnt=num_words-1;

            for(int i=0;i<num_words;i++){
                //res+=line[i];
                res.append(line[i]);
                if(i<num_words-1){
                    //res+=string(space_between+(i<extra_space?1:0),' ');
                    res.append(string(space_between+(i<extra_space?1:0),' '));
                }
            }
        }

        return res;        
    }
};

/*
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> grp;
        string tmp[maxWidth];
        int tmp_left=maxWidth;
        int tmp_start_idx=0;

        //use a while loop to group words into a vector
        for (string word: words){
            int this_len=word.length();
            if (this_len>tmp_left){
                //memcpy tmp to a buffer then push ?
            }else{
                
            }
        }
        //  if padding ' '

    }
};
*/
