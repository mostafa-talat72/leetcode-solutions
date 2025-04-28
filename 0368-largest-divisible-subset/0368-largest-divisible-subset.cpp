class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	vector<pair<int, int>> dp(n, { 1, -1 });
	int top = 0, maxx = -1;
	for (int j = 0;j < n;j++) {
		for (int i = 0;i < j;i++)
		{
			if (nums[j] % nums[i] == 0 && dp[j].first < dp[i].first + 1) {
				dp[j].first = dp[i].first + 1;
				dp[j].second = i;
				if (maxx < dp[j].first) {
					maxx = dp[j].first;
					top = j;
				}
			}
		}
	}
	vector<int> ans;
	while (top != -1) {
		ans.push_back(nums[top]);
		top = dp[top].second;
	}
	return ans;
}
};