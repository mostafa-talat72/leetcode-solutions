
int dr[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dc[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
class Solution {
public:
  int dfs(vector<vector<int>>& grid, int i, int j,vector<vector<bool>>&vis,int groupId ,map<pair<int,int>, int>&gridId) {
	vis[i][j] = 1;
	gridId[{i, j}] = groupId;
	int ans = 1;
	for (int k = 0; k < 4; k++) {
		int r = i + dr[k];
		int c = j + dc[k];
		if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && !vis[r][c] && grid[r][c]) {
			ans += dfs(grid, r, c, vis, groupId, gridId);
		}
	}
	return ans;
}

int largestIsland(vector<vector<int>>& grid) {
	vector<pair<int, int>>zeros;
	vector<vector<bool>>vis(grid.size(), vector<bool>(grid[0].size(), 0));
	int ans = 0;
	map<int, int>groupSiz;
	map<pair<int,int>, int>gridId;
	int id = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 0) {
				zeros.push_back({ i,j });
			}
			if(grid[i][j] && !vis[i][j]) {
				ans = dfs(grid, i, j, vis, id, gridId);
				groupSiz[id++] = ans;
			}

		}
	}
	if (zeros.size() == 0) {
		return grid.size() * grid[0].size();
	}
	ans = 0;
	for (int i = 0; i < zeros.size(); i++) {
		int r = zeros[i].first;
		int c = zeros[i].second;
		set<int>group;
		for (int k = 0; k < 4; k++) {
			int rr = r + dr[k];
			int cc = c + dc[k];
			if (rr >= 0 && rr < grid.size() && cc >= 0 && cc < grid[0].size() && grid[rr][cc]) {
				group.insert(gridId[{rr, cc}]);
			}
		}
		int sum = 1;
		for (auto x : group) {
			sum += groupSiz[x];
		}
		ans = max(ans, sum);
	}
	return ans;
}
};