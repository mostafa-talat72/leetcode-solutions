class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
	vector<int> res(grid.size() * grid.size() + 1);
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			res[grid[i][j]]++;
		}
	}
	int a = -1, b = -1;
	for (int i = 1; i < res.size(); i++) {
		if (res[i] == 2) {
			a = i;
		}
		if (res[i] == 0) {
			b = i;
		}
	}
	return { a, b };
}
};