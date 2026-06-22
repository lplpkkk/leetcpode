class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int balon[5]={0};

        for(auto& c:text){
            if(c=='a'){
                balon[0]++;
            }else if(c=='b'){
                balon[1]++;
            }else if(c=='l'){
                balon[2]++;
            }else if(c=='o'){
                balon[3]++;
            }else if(c=='n'){
                balon[4]++;
            }
        }

        int minv=INT_MAX;
        for(int i=0;i<5;i++){
            if(i==2||i==3){
                minv=min(minv,balon[i]/2);
            }else{
                minv=min(minv,balon[i]);
            }
        }

        return minv;
    }
};
