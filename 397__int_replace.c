#define MIN(x,y) ((a<b)?a:b)

int dfs(long long n, int cur_step){

    if(n==1){
        return cur_step;
    }

    if(n&1){
        int a=dfs(n+1, cur_step+1);
        int b=dfs(n-1, cur_step+1);
        return MIN(a,b);
    }else{
        return dfs(n/2, cur_step+1);    
    }
}

int integerReplacement(int n) {

    return dfs(n,0);    
}
