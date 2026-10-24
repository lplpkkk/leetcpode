class Solution {
public:

    void parse_date(string s, int* mon, int* day){
        string first="";
        int i=0;
        while(s[i]!='-'){
            first+=s[i];
            i++;
        }
        *mon=stoi(first);

        i++;
        string second="";
        while(i < s.size()){
            second+=s[i];
            i++;
        }
        *day=stoi(second);

        return;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a_arrive=0, a_leave=0, b_arrive=0, b_leave=0;
        int days[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int tmp_month, tmp_day;
        parse_date(arriveAlice,&tmp_month,&tmp_day);
        for(int i=0;i<tmp_month-1;i++){
            a_arrive+=days[i];
        }
        a_arrive+=tmp_day;

        parse_date(leaveAlice,&tmp_month,&tmp_day);
        for(int i=0;i<tmp_month-1;i++){
            a_leave+=days[i];
        }
        a_leave+=tmp_day;

        parse_date(arriveBob,&tmp_month,&tmp_day);
        for(int i=0;i<tmp_month-1;i++){
            b_arrive+=days[i];
        }
        b_arrive+=tmp_day;

        parse_date(leaveBob,&tmp_month,&tmp_day);
        for(int i=0;i<tmp_month-1;i++){
            b_leave+=days[i];
        }
        b_leave+=tmp_day;

        return max(0, min(a_leave,b_leave)-max(a_arrive,b_arrive)+1);
    }
};
