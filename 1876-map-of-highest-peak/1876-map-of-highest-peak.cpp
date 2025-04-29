int dr[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dc[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

class Solution {
public:
    
vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
	vector<vector<int>>ans(isWater.size(), vector<int>(isWater[0].size(), -1));
	queue<pair<int, int>>q;
	vector<vector<bool>>vis(isWater.size(), vector<bool>(isWater[0].size(), false));
	for(int i = 0; i < isWater.size(); i++) {
		for (int j = 0; j < isWater[0].size(); j++) {
			if (isWater[i][j]) {
				q.push({ i, j });
				ans[i][j] = 0;
				vis[i][j] = true;
			}
		}
	}

	while(q.size())
	{
		auto top = q.front();
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int r = top.first + dr[k];
			int c = top.second + dc[k];
			if (r < 0 || r >= isWater.size() || c < 0 || c >= isWater[0].size() || vis[r][c])
				continue;
			vis[r][c] = true;
			ans[r][c] = ans[top.first][top.second] + 1;
			q.push({ r, c });
		}

	}
	return ans;
}
};