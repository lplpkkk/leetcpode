class Solution {
public:
/*
    bool isBoomerang(vector<vector<int>>& points) {

        vector<int> diff(2);
        diff[0]=abs(points[0][0]-points[1][0]);
        diff[1]=abs(points[0][1]-points[1][1]);
        int _gcd=gcd(diff[0],diff[1]);
        diff[0]/=_gcd;
        diff[1]/=_gcd; 

        vector<int> diff2(2);
        diff2[0]=abs(points[2][0]-points[1][0]);
        diff2[1]=abs(points[2][1]-points[1][1]);

        bool same_line=((diff2[0]%diff[0])==0)&&((diff2[1]%diff[1])==0);
        return (!same_line);       
    }
    */
    bool isBoomerang(vector<vector<int>>& points) {
        int x1=points[0][0], y1=points[0][1];
        int x2=points[1][0], y2=points[1][1];
        int x3=points[2][0], y3=points[2][1];

        return ((x2-x1)*(y3-y1)==(x3-x1)*(y2-y1))?false:true;
    }
};
