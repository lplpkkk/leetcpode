
int get_val(char* s, int k){
    int val=0;
    for(int i=0;i<k;i++){
        val=(val<<1) |(*(s+i)-'0');
    }    
    return val;
}

// 0 1 2 3

bool hasAllCodes(char* s, int k) {
   int mask=0;
   int len=strlen(s);
   bool exist[1<<20]={0};

   for(int i=0;i<=(len-k);i++){
        int val=get_val(s+i,k);
        exist[val]=1;  
   }
   
   for(int i=0;i<(1<<k);i++){
    if(exist[i]==0){
        return false;
    }
   }
   return true;
}
