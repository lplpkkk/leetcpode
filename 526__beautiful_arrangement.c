int count=0;
void dfs(int n, int pos, int* used){
    if(pos>n){
        count++;
        return;
    }

    for(int i=1;i<=n;i++){
        if(!used[i] && (((i%pos)==0) || ((pos%i)==0))){
            used[i]=1;
            dfs(n,pos+1,used);
            used[i]=0;
        }
    }
}

int countArrangement(int n) {
    int used[16]={0};
    count=0;
    dfs(n,1,used);
    return count;
}
