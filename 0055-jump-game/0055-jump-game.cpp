class Solution {
public:
bool jumpSolve(int i, vector<int>& dp, vector<int>& nums) {
	if (i >= nums.size() - 1)return 1;
	if (~dp[i])return dp[i];
	int ans = 0;
	for (int j = nums[i]; j >= 1; j--) {
		if (ans)
			break;
		ans = jumpSolve(i + j, dp, nums);
	}
	return dp[i] = ans;
}
bool canJump(vector<int>& nums) {
	vector<int>dp(nums.size(), -1);

	return jumpSolve(0, dp, nums);
}
};