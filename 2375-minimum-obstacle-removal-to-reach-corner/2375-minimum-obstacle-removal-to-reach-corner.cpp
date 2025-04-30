int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0};
class Solution {
public:
int minimumObstacles(vector<vector<int>>& grid) {
	queue< pair<int, int>> q;;
	vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
	q.push( {0, 0 });
	vis[0][0] = 0;
	int ans = INT_MAX;
	while(q.size()){
		auto top=q.front();
		q.pop();
		int r = top.first;
		int c = top.second;
		if (r == grid.size() - 1 && c == grid[0].size() - 1)
			ans = min(ans, vis[r][c]);
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size())continue;
			if (vis[nr][nc] == -1 || vis[nr][nc] > vis[r][c] + grid[nr][nc]) {
				vis[nr][nc] = vis[r][c] + grid[nr][nc];
				q.push({ nr, nc });
			}
		}
	}

	return ans;
}
};