int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize, int** friendships, int friendshipsSize, int* friendshipsColSize) {

    bool knows[languagesSize+1][n+1];
    memset(knows,0,sizeof(knows));
    for(int i=0;i<languagesSize;i++){
        for(int j=0;j<languagesColSize[i];j++){
            int lang_idx=languages[i][j];
            knows[i+1][lang_idx]=1;
        }
    }

    bool needhelp[languagesSize+1];
    memset(needhelp, 0,sizeof(needhelp));

    for(int i=0;i<friendshipsSize;i++){
        int u=friendships[i][0];
        int v=friendships[i][1];

        int ok=false;
        for(int j=1;j<=n;j++){
            if(knows[u][j]&&knows[v][j]){
                ok=true;
                break;
            }
        }
        
        if(!ok){
            needhelp[u]=needhelp[v]=1;
        }
    }

    int needhelpcnt=0;
    for(int i=1;i<=languagesSize;i++){
        if(needhelp[i]) needhelpcnt++;
    }

    if(needhelpcnt==0) return 0;

    /* find one lang that is most common, so we can minimize ppl that we need to teach */
    int lang_cnt[n+1];
    memset(lang_cnt,0,sizeof(lang_cnt));
    for(int i=1;i<=languagesSize;i++){
        if(needhelp[i]){
            for(int j=1;j<=n;j++){
                if(knows[i][j]){
                    lang_cnt[j]++;
                }
            }
        }
    }

    int max_cnt=0;
    for(int i=1;i<=n;i++){
        /* ith lang is most common*/
        if(max_cnt<lang_cnt[i]) max_cnt=lang_cnt[i];
    }

    return (needhelpcnt-max_cnt);
}
