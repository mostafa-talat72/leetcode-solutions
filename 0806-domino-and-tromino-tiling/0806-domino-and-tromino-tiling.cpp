class Solution {
public:
    int dpNumTilings(int i, int& n, vector<int>& dp, int mod = 1e9 + 7) {
	if (i > n) return 0;

	if (i == n) return 1;
	if (~dp[i])return dp[i];
	dp[i] = dpNumTilings(i + 1, n, dp) % mod;
	dp[i] %= mod;
	dp[i] += dpNumTilings(i + 2, n, dp) % mod;
	dp[i] %= mod;
	for (int j = 3; j + i <= n; j++)
	{
		dp[i] += 2* dpNumTilings(i + j, n, dp) % mod;
		dp[i] %= mod;
	}
	return dp[i];
}
int numTilings(int n) {
	vector<int> dp(n + 1, -1);

	return dpNumTilings(0,  n, dp);
}
};