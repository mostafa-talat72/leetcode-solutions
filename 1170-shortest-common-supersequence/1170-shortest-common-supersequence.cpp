class Solution {
public:
    
int dp[1001][1001];
string shortestCommonSupersequence(string s, string t) {
	memset(dp, -1, sizeof dp);
	int n = s.size(), m = t.size();
	for (int j = 0; j <= m; j++)
		dp[n][j] = m - j;
	for (int i = 0; i <= n; i++)
		dp[i][m] = n - i;
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--) {
			if (s[i] == t[j])
				dp[i][j] = dp[i + 1][j + 1] + 1;
			else {

				dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
			}
		}

	int i = 0, j = 0;
	string ans;
	while( i < n && j < m) {
		if (s[i] == t[j] && dp[i][j] == dp[i + 1][j + 1] + 1)ans.push_back(s[i++]), j++;
		else if (dp[i][j] == dp[i + 1][j] + 1)
			ans.push_back(s[i++]);
		else if (dp[i][j] == dp[i][j + 1] + 1)
			ans.push_back(t[j++]);
	}
	ans += s.substr(i) + t.substr(j);
	return ans;
}
};