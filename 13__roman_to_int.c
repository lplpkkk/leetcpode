typedef struct tb{
    char sym;
    int val;
}tb;

tb table[7]={
  {
    'I',1,
  } ,
  {
    'V',5,
  } , 
  {
    'X',10,
  } ,
  {
    'L',50,
  } ,
  {
    'C',100,
  } ,
  {
    'D',500,
  } ,
  {
    'M',1000,
  } ,
};

int parse(char sym){
    for(int i=0;i<7;i++){
        if(sym==table[i].sym){
            return table[i].val;
        }
    }
    return -1;
}

int _excp(int prev, int cur){
    if((prev==1) && ((cur==5)||(cur==10))){
        return 1;
    }
    if((prev==10) && ((cur==50)||(cur==100))){
        return 1;
    }
    if((prev==100) && ((cur==500)||(cur==1000))){
        return 1;
    }
    return 0;
}

int romanToInt(char* s) {
    int sum=0;
    int *tmp=malloc(sizeof(int)*strlen(s));

    for(int i=0;i<strlen(s);i++){
        //sum+=parse(s[i]);
        tmp[i]=parse(s[i]);

        if(i>0){
            if(_excp(tmp[i-1],tmp[i])){
                sum=sum-2*tmp[i-1]+tmp[i];
            }else{
                sum+=tmp[i];    
            }
        }else{
            sum+=tmp[i];
        }

    }

    return sum;
}
