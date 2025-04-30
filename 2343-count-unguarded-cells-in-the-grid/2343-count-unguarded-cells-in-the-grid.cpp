class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
	vector<vector<int>>vis(m, vector<int>(n, 0));
	for(int i=0;i<guards.size();i++){
		vis[guards[i][0]][guards[i][1]] = 1;
	}
	for (int i = 0; i < walls.size(); i++) {
		vis[walls[i][0]][walls[i][1]] = -1;
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if(vis[i][j] == 1){
				for (int row = i + 1; row < m; row++) {
					if (vis[row][j] == -1 || vis[row][j] == 1)
						break;
					vis[row][j] = 5;
				}
				for (int col = j + 1; col < n; col++) {
					if (vis[i][col] == -1 || vis[i][col] == 1)
						break;
					vis[i][col] = 5;
				}

				for (int row = i - 1; row >= 0; row--) {
					if (vis[row][j] == -1 || vis[row][j] == 1)
						break;
					vis[row][j] = 5;
				}

				for (int col = j - 1; col >= 0; col--) {
					if (vis[i][col] == -1 || vis[i][col] == 1)
						break;
					vis[i][col] = 5;
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if(vis[i][j] == 0)
			{
				ans++;
			}
		}
	}
	return ans;
}
};