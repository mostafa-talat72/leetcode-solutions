class Solution {
public:
  int dp[201][10001];
bool isValid(int i, vector<int>& nums, int sum) {
	if (i == nums.size()) {
		return sum == 0;
	}
	if (sum < 0) return false;
	if (~dp[i][sum]) 
		return dp[i][sum];
	return dp[i][sum] = isValid(i + 1, nums, sum - nums[i]) || isValid(i + 1, nums, sum);
}
bool canPartition(vector<int>& nums) {
	int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum & 1) return false;
	sort(nums.begin(), nums.end());
	memset(dp, -1, sizeof dp);
	return isValid(0, nums, sum / 2);
}

};