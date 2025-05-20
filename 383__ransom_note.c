#if(0)
bool canConstruct(char* ransomNote, char* magazine) {
    // magazine   --> src
    // ransomnote --> target
    int idx_src=0;
    int idx_tar=0;
    int len_src=strlen(magazine);
    int len_tar=strlen(ransomNote);
    int j=0;
    int diff=0;

    for(int i=0;i<(len_src-len_tar+1) ;i++){
        for(j=0;j<len_tar;j++){
            if(magazine[i+j]==ransomNote[j]){
                //continue

            }else{
                diff=1;
                break;
            }
        }

        if ((j==len_tar) &&(!diff)){
            return true;
        }
    } 


    return false;   
}
#endif

bool canConstruct(char* ransomNote, char* magazine) {
    int ascii[26];
    memset(ascii,0,sizeof(int)*26);

    int len_src=strlen(magazine);
    int len_tar=strlen(ransomNote);
    
    for(int i=0;i<len_src;i++){
        ascii[  (magazine[i]-'a') ]++;
    }
    
    for(int i=0;i<len_tar;i++){
        ascii[  (ransomNote[i]-'a') ]--;
        if(ascii[  (ransomNote[i]-'a') ] <0){
            return false;
        }
    }

    return true;
    

    
}
