class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

	 int l = 0, r = nums.size() - 1;
     while (l<r)
     {
         if (nums[r] == val)
             r--;
		 else if (nums[l] != val)
			 l++;
		 else
             swap(nums[l++], nums[r--]);
     }
     return r >= 0 && nums[r] == val ? r : r + 1;
 }
};