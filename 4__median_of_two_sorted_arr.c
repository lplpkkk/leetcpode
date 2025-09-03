double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(nums1Size>nums2Size){
        return  findMedianSortedArrays(nums2,nums2Size,nums1,nums1Size);
    }
    int l_min=0, l_max=nums1Size;
    int half=(nums1Size+nums2Size+1)/2;
    bool odd=(nums1Size+nums2Size)&1;

    while(l_min<=l_max){
        int l=(l_min+l_max)/2;
        /* r is the idx of the other arr*/
        int r=(half-l);
        
        if(l<nums1Size && (nums1[l]<nums2[r-1])){
            l_min=l+1;
        }else if(l>0 && (nums1[l-1]>nums2[r])){
            l_max=l-1;
        }else{
            int max_left;
            if(l==0){
                max_left=nums2[r-1];
            }else if(r==0){
                max_left=nums1[l-1];
            }else{
                max_left=(nums1[l-1]>nums2[r-1])?nums1[l-1]:nums2[r-1];
            }

            if(odd){
                return max_left;
            }

            int min_right;
            if(l==nums1Size){
                min_right=nums2[r];
            }else if(r==nums2Size){
                min_right=nums1[l];
            }else{
                min_right=(nums1[l]<nums2[r])?nums1[l]:nums2[r];
            }

            return (max_left+min_right)/2.0;
        }
    }

    // cannot reach here
    return 0;
}
