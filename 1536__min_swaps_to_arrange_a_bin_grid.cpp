class Solution {

//tmp.     ->0,1,2
//trailing0->2,1,0    
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        int cnt=0;
        vector<int> trailing0(n);

        //setup trailing 0 as a vector for each row
        for(int i=0;i<n;i++){
            cnt=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]!=0){
                    break;
                }else{
                    cnt+=1;
                }
            }
            trailing0[i]=cnt;
        }

        //check if possible
        vector<int> tmp=trailing0;

        int steps=0;
        int found=-1;

        //move candidate to row i
        for(int i=0;i<n;i++){
            found=-1;
            for(int k=i;k<n;k++){
                if(trailing0[k]>=n-1-i){
                    found=k;
                    break;
                }
            }
            //move up 'i', move down others
            if(found==-1){
                return -1;
            }

            steps+=(found-i);

            int val=trailing0[found];
            for(int k=found;k>i;k--){
                trailing0[k]=trailing0[k-1];
            }
            trailing0[i]=val;
        }
        return steps;
    }
};
