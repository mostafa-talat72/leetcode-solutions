class Solution {
    public int jump(int[] nums)  {
        int mx = 0, cnt = 0,  curr = 0;
        for(int i = 0; i < nums.length - 1; i++){
            mx = Math.max(mx, i + nums[i]);
            if(i == curr){
                cnt++;
                curr = mx;
            }
        }
        return cnt;
    }
}