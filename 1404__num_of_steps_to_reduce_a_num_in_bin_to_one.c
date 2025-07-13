int numSteps(char* s) {
    int len=strlen(s);
    int carry=0;
    int steps=0;

    for(int i=len-1;i>0;i--){
        if(((s[i]-'0'+carry) ==1)){
            carry=1;
            steps+=2;
        }else{
            steps+=1;
        }
    }

    if(carry){
        steps+=1;
    }

    return steps;
}
