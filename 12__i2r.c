typedef struct map{
    char* sym;
    int val;
}map;

map i2r[]={
    {"M", 1000},
    {"CM", 900},
    {"D", 500},
    {"CD", 400},
    {"C", 100},
    {"XC", 90},
    {"L", 50},
    {"XL", 40},
    {"X", 10},
    {"IX", 9},
    {"V", 5},
    {"IV", 4},
    {"I", 1},
};

char ans[20];

char* intToRoman(int num) {
    //char* ans=malloc(20);
    ans[0]='\0';
    int idx=0;

    for(int i=0;i<13;i++){
        while( num >= i2r[i].val){
            strcpy(ans+idx,i2r[i].sym);
            idx+=strlen(i2r[i].sym);
            num-=i2r[i].val;
        }
    }    
    ans[idx]='\0';
    return ans;
}
