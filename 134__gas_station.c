int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int len=gasSize;
    int total=0;
    int tank=0;
    int gain=0;
    int start_point=0;

    for(int i=0;i<len;i++){
        gain = (gas[i]-cost[i]);  
        total+=gain;
        tank+=gain;

        if(tank<0){
            //i_th start fail
            start_point=i+1;
            tank=0;
        }
    }

    if(total>=0){
        return start_point;
    }else{
        //fail 
        return -1;
    }
}
