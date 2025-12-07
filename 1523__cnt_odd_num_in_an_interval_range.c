

int countOdds(int low, int high){
    int l=(low&1)?low:(low+1);
    int r=(high&1)?high:(high-1);
    return ((r-l)/2)+1;
    
}
