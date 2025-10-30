/*

TLE...

int get_sum(int* target, int targetSize){
    int sum=0;
    for(int i=0;i<targetSize;i++){
        sum+=target[i];
    }
    return sum;
}

int minNumberOperations(int* target, int targetSize) {
    int sum=0;
    int this_cnt=0;
    int this_max_cnt=0;
    int this_max_idx=0;
    int ans=0;

    do{
        for(int i=1;i<targetSize;i++){
            if(target[i]>target[i-1]){
                for(int j=i+1;j<targetSize;j++){
                    if(target[j]>target[i]){
                        this_cnt++;                    
                    }
                }
                if(this_cnt>this_max_cnt){
                    this_max_cnt=this_cnt;
                    this_max_idx=i;
                }
            }
            for(int k=this_max_idx;k<(this_max_idx+this_max_cnt);k++){
                target[k]--;
                ans++;
            }
        }
        sum=get_sum(target,targetSize);
    }while(sum);

    return ans;
}
*/

#pragma GCC optimize("O3, unroll-loops")
int minNumberOperations(int* target, int n) {
    int ans=target[0];
    for(int i=1; i<n; i++){
        ans+=fmax(target[i]-target[i-1], 0);
    }
    return ans;
}
