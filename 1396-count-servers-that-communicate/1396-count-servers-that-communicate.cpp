class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

	vector<vector<int>>row(grid.size()), col(grid[0].size());

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 1) {
				row[i].push_back(j);
				col[j].push_back(i);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < grid.size(); i++) {
		if(row[i].size() > 1){
			for (int j = 0; j < row[i].size(); j++) {
				grid[i][row[i][j]] = -1;
			}
		}
	}

	for (int j = 0; j < grid[0].size(); j++) {
		if (col[j].size() > 1) {
			for (int i = 0; i < col[j].size(); i++) {
				grid[col[j][i]][j] = -1;
			}
		}
	}

	for(int i = 0; i < grid.size(); i++){
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == -1) {
				ans++;
			}
		}
	}
	return ans;
}
};