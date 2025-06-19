public class Solution {
     public int PartitionArray(int[] nums, int k)
 {
     Array.Sort(nums);
     int n = nums.Length, last = nums[n - 1], sub = 0, ans = 1;
     for (int i = n - 2; i >= 0; i--)
     {
         if (last - nums[i] + sub > k)
         {
             sub = 0;
             ans++;
         }else
         {
             sub += last - nums[i];
         }
         last = nums[i];
     }
     return ans;
 }
}