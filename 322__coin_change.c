int coinChange(int* coins, int coinsSize, int amount) {
    
    // how many fewest coins needed for amount
    int dp[amount+1];

    for(int i=0;i< (amount+1);i++){
        dp[i]=amount+1;
    }
    //dont need any coin for 0 amount
    dp[0]=0;
    int max_cur_coin;
    
    //bottom-up dp
    for(int i=0;i<=amount;i++){

        for(int j=0;j<coinsSize;j++){
        
            if( i>=coins[j]){
                #if(1)
                // get min
                if( dp[i]>(dp[i-coins[j]]+1) ){
                    dp[i] = dp[i-coins[j]]+1;
                }
                #endif

                #if(0)
                max_cur_coin=i/coins[j];
                while(max_cur_coin){
                    //arr check
                    if((i-max_cur_coin*coins[j])>=0){
                        // min check
                        if( dp[i]<(dp[(i-max_cur_coin*coins[j])]+max_cur_coin) ){
                            dp[i]=(dp[(i-max_cur_coin*coins[j])]+max_cur_coin);
                        }
                    }
                    
                }
                #endif
            }
                    
        }

    }

    return (dp[amount]<(amount+1))?dp[amount]:(-1);
}
