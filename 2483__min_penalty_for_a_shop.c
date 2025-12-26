int bestClosingTime(char* customers) {
    int n=strlen(customers);
    int p=0;
    int min_p=0;
    int ans=0;

    for(int i=0;i<n;i++){
        if(customers[i]=='Y'){
            p--;
        }else{
            p++;
        }

        if(p<min_p){
            min_p=p;
            ans=i+1;
        }
    }

    return ans;
}
