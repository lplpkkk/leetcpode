#define BIT(x) (1u<<x)
int parse_b(int x){
    if( (x&0x80)==0x00) return 1;
    if( (x&0xE0)==0xC0) return 2; //110x_xxxx
    if( (x&0xF0)==0xE0) return 3; //1110_xxxx
    if( (x&0xF8)==0xF0) return 4; //1111_0xxx
    return -1;

}

bool is_cont(int x){
   return (x & 0xC0) == 0x80;
}

bool validUtf8(int* data, int dataSize) {
    int cur=0;
    int incr;

    while(cur<dataSize){
        incr=parse_b(data[cur]);
        if(incr<0) return false;
        
        for(int i=1;i<incr;i++){
            if((cur+i)>=dataSize){
                return false;
            }
            if(!is_cont(data[cur+i])){
                return false;
            }
        }
        cur+=incr;
    }

    if(cur>dataSize){
        return false;
    }else{
        return true;
    }
}
