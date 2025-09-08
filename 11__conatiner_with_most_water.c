
#if(0)
/* TLE answer */
int maxArea(int* height, int heightSize) {
    int max=0;
    /* select start point */
    for(int i=0;i<heightSize-1;i++){
        /* calc */
        
        for(int j=i+1;j<heightSize;j++){
            int min_h = height[i] < height[j] ? height[i] : height[j];
            if(height[j]<min_h) min_h=height[j];
            int this_area=min_h*(j-i);
            if(this_area>max) max=this_area;
        }
    }
    return max;
}
#else
int maxArea(int* height, int heightSize) {
    int l=0, r=heightSize-1;
    int max=0;

    while(l<r){
        int min_h=(height[l]<height[r])?height[l]:height[r];
        int area=min_h*(r-l);
        if(area>max) max=area;

        if(height[l]<height[r]){
            l++;
        }else{
            r--;
        }
    }
    return max;
}

#endif
