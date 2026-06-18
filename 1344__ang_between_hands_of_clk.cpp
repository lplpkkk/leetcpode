class Solution {
public:
    double angleClock(int h, int m) {
       double ext=(double)m/60;
       double habs=(h%12+ext)*30;//360/12->30
       double mabs=ext*360;

        //printf("%f,%f\n", ext,mabs);
        double cand=abs(habs-mabs);
       return min(cand,360-cand);

       //case 1, abs(15-180)
       //case 2, abs(105-180)
       //case 3, abs(3.25*30=97.5-90)
    }
};
