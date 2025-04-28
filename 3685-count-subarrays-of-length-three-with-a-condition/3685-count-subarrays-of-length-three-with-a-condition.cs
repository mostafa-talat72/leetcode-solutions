public class Solution {
    public int CountSubarrays(int[] nums)
 {
     int ans = 0;
     for(int i = 1; i < nums.Length - 1; i++)
     {
         if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) ans++;
     }
     return ans;
 }
}