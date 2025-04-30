class Solution {
public:
    int jumpSolve(int i, vector<int>& dp, vector<int>& nums) {
	if (i >= nums.size() - 1)return 0;
	if (~dp[i])return dp[i];
	int ans = 1e6;
	for (int j = nums[i]; j >=1 ; j--) {
		ans = min(ans, 1 + jumpSolve(i + j, dp, nums));
	}
	return dp[i] = ans;
}

int jump(vector<int>& nums) {
	vector<int>dp(nums.size(), -1);
	return jumpSolve(0, dp, nums);
}
};