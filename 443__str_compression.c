/*
int compress(char* chars, int charsSize) {
    int l=0;
    int r=0;
    int this_cnt;
    int total_cnt=0;

    while(r<charsSize&&l<charsSize){
        this_cnt=0;
        while(chars[r]==chars[l]){
            this_cnt++;
            r++;
        }
        //prepare next compare
        l+=this_cnt;

        if(this_cnt<2){
            this_cnt=2;
        }
        total_cnt+=this_cnt;
        
    }
    return total_cnt;
}
*/

int compress(char* chars, int charsSize) {
    int read=0;
    int write=0;

    while(read<charsSize){
        char cur=chars[read];
        int cnt=0;

        while(read<charsSize&&chars[read]==cur){
            read++;
            cnt++;
        }

        chars[write++]=cur;
        
        if(cnt>1){
            int start=write;
            while(cnt>0){
                chars[write++]=(cnt%10)+'0';
                cnt/=10;
            }

            //reverse
            int end=write-1;
            while(start<end){
                char tmp=chars[start];
                chars[start++]=chars[end];
                chars[end--]=tmp;
            }
        }
    }

    return write;
}
