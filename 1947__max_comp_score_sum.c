int cur_sum=0;
int max_score=0;
int m,n;
int visited[8]={0};
int tb[8][8]={0};

int calc(int mask1, int mask2){
    int xor=mask1^mask2;
    int diff=__builtin_popcount(xor);
    return n-diff;
}

void dfs(int student_idx, int cur){
    if(student_idx==m){
        if(cur>max_score){
            max_score=cur;
        }
        return;
    }

    for(int j=0;j<m;j++){
        if(!visited[j]){
            visited[j]=1;
            dfs(student_idx+1,cur+tb[student_idx][j]);
            visited[j]=0;
        }
    }
    return;
}

int maxCompatibilitySum(int** students, int studentsSize, int* studentsColSize, int** mentors, int mentorsSize, int* mentorsColSize) {
    int mask1[8]={0};
    int mask2[8]={0};
    m=studentsSize;
    n=studentsColSize[0];
    max_score=0;
    memset(visited,0,8);

    for(int i=0;i<studentsSize;i++){
        for(int j=0;j<studentsColSize[0];j++){
            mask1[i]|=students[i][j]<<j;
            mask2[i]|=mentors[i][j]<<j;
        }
    }

    for(int i=0;i<studentsSize;i++){
        for(int j=0;j<studentsSize;j++){
            tb[i][j]=calc(mask1[i],mask2[j]);
        }
    }
    
    dfs(0,0);
    return max_score;
}
