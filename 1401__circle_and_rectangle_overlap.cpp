/*
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int circle_left=xCenter-radius;
        int circle_right=xCenter+radius;
        int circle_top=yCenter+radius;
        int circle_bottom=yCenter-radius;

        if(circle_left>x2 || circle_right<x1 || circle_bottom>y2 || circle_top<y1){
            return false;
        }

        //check four corner:
        pair<int,int> corner[4]={{x1,y1},{x1,y2},{x2,y2},{x2,y1}};
        for(int i=0;i<4;i++){
            int x_diff=corner[i].first-xCenter;
            int y_diff=corner[i].second-yCenter;

            int c2r_len=sqrt(x_diff*x_diff+y_diff*y_diff);
            if (c2r_len>radius) return false;
        }

        return true;
        
    }
}*/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        int closest_x = max(x1, min(xCenter, x2));
        int closest_y = max(y1, min(yCenter, y2));

        int dx = closest_x - xCenter;
        int dy = closest_y - yCenter;

        return dx * dx + dy * dy <= radius * radius;
    }
};
