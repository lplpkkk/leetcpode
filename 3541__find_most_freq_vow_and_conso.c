
int is_vow(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int maxFreqSum(char* s) {
    int len=strlen(s);
    int val[26];
    int val_max_vow=0;
    int val_max_conso=0;

    memset(val,0,sizeof(int)*26);

    for(int i=0;i<len;i++){
        val[s[i]-'a']++;
        if(is_vow(s[i])){
            if(val_max_vow<val[s[i]-'a']){
                val_max_vow=val[s[i]-'a'];
            }
        }else{
            if(val_max_conso<val[s[i]-'a']){
                val_max_conso=val[s[i]-'a'];
            }
        }
    }
    
    return (val_max_vow+val_max_conso);

}
