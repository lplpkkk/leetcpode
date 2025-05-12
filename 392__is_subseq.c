bool isSubsequence(char* s, char* t) {
    int len=strlen(t);
    int cur_s_idx=0;


    if((s==NULL)&&(t==NULL)){
        return true;
    }else if((s==NULL)||(t==NULL)){
        return false;
    }

    
    
    for(int i=0;i<len;i++){
        if(t[i]==s[cur_s_idx]){
            cur_s_idx++;
        }    
    }

    if(cur_s_idx==strlen(s)){
        return true;
    }else{
        return false;
    }
}
