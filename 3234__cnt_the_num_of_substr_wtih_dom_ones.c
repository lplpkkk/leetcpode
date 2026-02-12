
/*
int numberOfSubstrings(char* s) {
    int len=strlen(s);
    int ans=0;

    if (s==NULL){
        return 0;
    }

    for (int i=0;i<len;i++){
        long long zero_cnt=0;
        long long one_cnt=0;

        for(int j=i;j<len;j++){
            if (s[j]=='0'){
                zero_cnt+=1;
            }else if (s[j]=='1'){
                one_cnt+=1;
            }

            ans+=(one_cnt>=(zero_cnt*zero_cnt));
        }
    }
    return ans;
}
*/

#define MAX(a,b) ((a)>(b)?(a):(b))


int numberOfSubstrings(char* s) {
    int len=strlen(s);
    int ans=0;

    int* zeros=(int*)malloc(sizeof(int)*(len+1));
    int z_cnt=0;
    for(int i=0;i<len;i++){
        if (s[i]=='0'){
            zeros[z_cnt++]=i;
        }
    }
    zeros[z_cnt]=len;

    int z_ptr=0;
    for(int i=0;i<len;i++){
        // find the head of the substring
        while(z_ptr<z_cnt&&zeros[z_ptr]<i){
            z_ptr++;
        }

        int next_zero_idx=zeros[z_ptr];
        ans+=(next_zero_idx-i);

        // find all the substring
        for(int k=1;k<=z_cnt-z_ptr;k++){
            int pos1=zeros[z_ptr+k-1];
            int pos2=zeros[z_ptr+k];
            if((k*k)>(len-1)) break;

            int min_j=i+k*k+k-1;
            int valid_start=MAX(pos1,min_j);
            int valid_end=pos2-1;

            if (valid_start<=valid_end){
                ans+=(valid_end-valid_start+1);
            }
        }
    }

    free(zeros);
    return ans;
}
