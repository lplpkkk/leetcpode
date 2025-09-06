int myAtoi(char* s) {
    long long tmp=0;
    int sign=1;
    char* real=s;

    while(*real==' '){
        real++;
    }

    if(*real=='-'){
        sign=-1;
        real++;
    }else if(*real=='+'){
        real++;
    }

    while(*real!='\0' && (isdigit(*real))){       
        tmp=tmp*10+(*real-'0');
        if(sign==1){
            if(tmp>INT_MAX) return INT_MAX;
        }else if(sign==-1){
            if(-tmp<INT_MIN) return INT_MIN;
        }
        real++;
    }

    return (int)(sign*tmp);
}
