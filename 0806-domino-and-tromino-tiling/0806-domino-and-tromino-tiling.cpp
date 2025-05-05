class Solution {
public:
   long long dp[1001];
int mod = 1e9 + 7;
int solve(int i,int n) { 
	if (i > n)
        return 0;
    if (i == n)
        return 1;
    long long & ret = dp[i];
    if (~ret)
        return ret;
    ret = 0;
    ret += solve(i + 1, n);
    ret += solve(i + 2, n);
    for (int j = 3; j <= n; j++)
    {
        if (i + j > n)
            break;
        int resp = solve(i + j, n);
        ret += resp * 2;
    }
    ret %= mod;
    return ret;
}
 int numTilings(int n) {

	memset(dp, -1, sizeof dp);
     return solve(0, n);
 }
};