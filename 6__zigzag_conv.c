char* convert(char* s, int numRows) {
    /*
        x
        x  x
        x x
        x

        --> this is the general pattern: numRows+(numRows-2)

        for numRows<=2
        x x x
        x x x
    */

    int len=strlen(s);
    int pattern=(numRows>2)?(numRows+numRows-2):numRows;
    char* ans=malloc(sizeof(char)*(len+1));
    int layer_idx=0,ans_idx=0;

    for(int i=0;i<numRows;i++){
        layer_idx=0;
        if((i==0)||(i==(numRows-1))){
            /* only one val */
            while((layer_idx*pattern+i)<len){
                ans[ans_idx++]=s[layer_idx*pattern+i];
                layer_idx++;
            }
        }else{
            while((layer_idx*pattern+i)<len){
                ans[ans_idx++]=s[layer_idx*pattern+i];
                if (layer_idx * pattern + (pattern - i) < len) {
                    ans[ans_idx++] = s[layer_idx * pattern + (pattern - i)];
                }
                layer_idx++;
            }
            
        }
    }
    ans[ans_idx]='\0';
    return ans;
}
