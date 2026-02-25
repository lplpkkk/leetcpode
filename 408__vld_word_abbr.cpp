class Solution {
public:
    /**
     * @param word: 原字串
     * @param abbr: 縮寫字串
     * @return: 縮寫是否合法
     */
  
    bool validWordAbbreviation(string word, string abbr) {
        int i=0;
        int j=0;

        while(i<word.length() && j<abbr.length()){
            if(isdigit(abbr[j])){
                int num=0;

                if(abbr[j]=='0'){
                    return false;
                }

                while((j<abbr.length())&&isdigit(abbr[j])){
                    num=num*10+(abbr[j]-'0');
                    j++;
                }

                i+=num;
            }else{
                if(i>=word.length()){
                    return false;
                }
                if (word[i]!=abbr[j]){
                    return false;
                }
                i++;
                j++;
            }
        }

        return (i==word.length() && j==abbr.length());
    }
};
