class Solution {
    public int jump(int[] nums)  {
       int[] dp = new int[nums.length];
       Arrays.fill(dp, Integer.MAX_VALUE);
       dp[0] = 0;
       for(int i=0;i<nums.length;i++){
           for(int j = 0; j <= nums[i] && i + j < nums.length;j++){
               int next = i + j;
               dp[next]=Math.min(dp[next], dp[i] + 1);
           }
       }
       return dp[nums.length - 1];
    }
}