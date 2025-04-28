class Solution {
public:
    long long dp[100005];
long long solve(int i, vector<vector<int>>& questions) {
	if (i >= questions.size())
		return 0;
	long long& ret = dp[i];
	if (~ret)return ret;
	ret = solve(i + questions[i][1] + 1, questions) + questions[i][0];
	ret = max(ret, solve(i + 1, questions));
	return ret;
}
long long mostPoints(vector<vector<int>>& questions) {
	memset(dp, -1, sizeof dp);
	return solve(0, questions);
}
};