
#if(0)
bool isIsomorphic(char* s, char* t) {

    if((s==NULL) && (t==NULL)){
        return true;
    }

    if(s==NULL){
        return false;
    }

    if(t==NULL){
        return false;
    }


    int min_len= (sizeof(s)<sizeof(t))?sizeof(s):sizeof(t);
    char* pHash=malloc(min_len);

    if(pHash==NULL){
        return -1;
    }

    int i=0;
    int offset=*s-*t;

    for (i=1;i<min_len;i++){
        if((*(s+i)-*(t+i))!=offset){
            return false;
        }
    }

    return true;

    
}
#endif

#if(0)
// I thought it only use "lower case of english char..."
bool isIsomorphic(char* s, char* t) {
    char l2r[256];
    char r2l[256];
    


    for(int i=0;s[i];i++){

        ascii_idx_s=(s[i]-'a');
        if(l2r[ascii_idx_s]!=-1){
            l2r[ascii_idx_s]=t[i];
        }
        ascii_idx_t=(t[i]-'a');
        if(r2l[ascii_idx_t]!=-1){
            r2l[ascii_idx_t]=s[i];
        }

        //l2r ..[f]..    
        //       b       //t[i]
        //r2l ......[b]
        //           f   //s[i]


        if(r2l[ l2r[ascii_idx_s]-'a']!= s[i] ){
            return false;
        }
    }

    return true;
}
#endif

bool isIsomorphic(char* s, char* t) {

    char l2r[256]={0};
    char r2l[256]={0};


    for(int i=0;s[i];i++){
        if ((l2r[(unsigned char)s[i]]==0) && (r2l[(unsigned char)t[i]]==0)){
            l2r[(unsigned char)s[i]]=t[i];
            r2l[(unsigned char)t[i]]=s[i];
        }else{
            if( (l2r[(unsigned char)s[i]]!=t[i])
               || (r2l[(unsigned char)t[i]]!=s[i])
            ) 
            {
                return false;
            }
        }
            
    }    

    return true;
}
