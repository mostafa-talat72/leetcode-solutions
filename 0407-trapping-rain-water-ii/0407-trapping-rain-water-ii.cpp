int dr[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dc[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

class Solution {
public:
   int trapRainWater(vector<vector<int>>& heightMap) {
	vector<vector<int>>vis(heightMap.size(), vector<int>(heightMap[0].size(), 0));
	priority_queue<pair<int,pair<int,int>>>q;
	for(int i=0;i<heightMap.size();i++){
		for (int j = 0; j < heightMap[0].size(); j++) {
			if (i == 0 || i == heightMap.size() - 1 || j == 0 || j == heightMap[0].size() - 1) {
				q.push({ -heightMap[i][j],{i,j} });
				vis[i][j] = 1;
			}
		}
	}

	int ans = 0,level = 0;
	while (q.size()) {
		auto top = q.top();
		level = max(level, -top.first);
		q.pop();
		for (int k = 0; k < 4; k++) {
			int r = top.second.first + dr[k];
			int c = top.second.second + dc[k];

			if (r < 0 || r >= heightMap.size() || c < 0 || c >= heightMap[0].size() || vis[r][c])continue;

			vis[r][c] = 1;
			ans += max(0, level - heightMap[r][c]);
			q.push({-heightMap[r][c],{r,c} });
		}
	}

	return ans;
}
};