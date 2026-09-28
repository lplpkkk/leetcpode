#define MAX(a,b) ((a>b)?a:b)
int maxDepth(char* s) {
    int len=strlen(s);
    int dep=0;
    int ans=0;

    for(int i=0;i<len;i++){
        if(s[i]=='(') dep++;
        if(s[i]==')') dep--;

        ans=MAX(ans,dep);    
    }
    return ans;
}
