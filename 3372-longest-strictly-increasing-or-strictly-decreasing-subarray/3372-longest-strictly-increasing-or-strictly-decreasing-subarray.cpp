class Solution {
public:
   int longestMonotonicSubarray(vector<int>& nums) {
	int cntUp = 1, cntDown = 1, ans = 1;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] > nums[i - 1])
		{
			cntUp++;
			cntDown = 1;
		}
		else if (nums[i] < nums[i - 1])
		{
			cntDown++;
			cntUp = 1;
		}
		else
			cntUp = cntDown = 1;
		ans = max({ ans, cntUp, cntDown });
	}
	return ans;
}
};