class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
	long long row1 = accumulate(grid[0].begin(), grid[0].end(), 0LL);
	long long row2 = 0;
	long long ans = LLONG_MAX;
	for(int j=0;j<grid[0].size();j++)
	{
		row1 -= grid[0][j];
		row2 += grid[1][j];
		ans = min(ans, max(row1, row2 - grid[1][j]));
	}
	return ans;
}
};