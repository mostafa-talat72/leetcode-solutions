int dr[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dc[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
	vis[i][j] = true;
	int ans = grid[i][j];
	for (int k = 0; k < 4; k++) {
		int ni = i + dr[k];
		int nj = j + dc[k];
		if(ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size() || vis[ni][nj] || !grid[ni][nj]) continue;

		ans += dfs(ni, nj, grid, vis);
	}
	return ans;
}


int findMaxFish(vector<vector<int>>& grid) {
	vector<vector<bool>>vis(grid.size(), vector<bool>(grid[0].size(), false));
	int ans = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (!vis[i][j] && grid[i][j]) {
				ans = max(ans, dfs(i, j, grid, vis));
			}
		}
	}
	return ans;
}
};