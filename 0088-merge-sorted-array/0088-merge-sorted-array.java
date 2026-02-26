class Solution {
   public void merge(int[] nums1, int m, int[] nums2, int n) {
        for(int cnt=n+m - 1,i=m-1,j=n-1;cnt>=0;cnt--){
            if(i<0){
                nums1[cnt]=nums2[j--];
            }else if(j<0){
                nums1[cnt]=nums1[i--];
            }else if(nums1[i]>nums2[j]){
                nums1[cnt]=nums1[i--];
            }else 
                nums1[cnt]=nums2[j--];
        }
    }
}