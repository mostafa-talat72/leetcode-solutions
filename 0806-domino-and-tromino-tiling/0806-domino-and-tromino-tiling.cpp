class Solution {
public:
   int dp[1001];
int mod = 1e9 + 7;
int module(int num, int dpp) { return (num % mod + dpp % mod) % mod; }
int solve(int i, int n)
    { 
	if (i > n)
        return 0;
    if (i == n)
        return 1;
    if (~dp[i])
        return dp[i];
    dp[i] = 0;
    dp[i] = module(dp[i], solve(i + 1, n));
    dp[i] = module(dp[i], solve(i + 2, n));
    for (int j = 3; j <= n; j++)
    {
       dp[i] = module(dp[i], solve(i + j, n));
       dp[i] = module(dp[i], solve(i + j, n));
    }
    return dp[i];
}
 int numTilings(int n) {

	memset(dp, -1, sizeof dp);
     return solve(0, n);
 }
};