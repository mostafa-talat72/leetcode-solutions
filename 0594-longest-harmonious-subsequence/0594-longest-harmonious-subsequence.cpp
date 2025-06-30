class Solution {
public:
    int findLHS(vector<int>& nums) {
	
	sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < nums.size();)
    {
		int nextIdx=upper_bound(nums.begin() + i , nums.end(), nums[i] + 1) - nums.begin();
        nextIdx--;
        if (nums[nextIdx] - nums[i] == 1)
		{
			ans = max(ans,nextIdx - i + 1);
        }
            i = upper_bound(nums.begin() + i, nums.end(), nums[i]) - nums.begin();
	}
    return ans;
}
};