class Solution {
public:
   int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
	map<int, pair<int, int>>mp;
	map<int, int>col, row;
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[0].size(); j++) {
			mp[mat[i][j]] = { i, j };
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		row[mp[arr[i]].first]++;
		col[mp[arr[i]].second]++;
		if (col[mp[arr[i]].second] == mat.size()||row[mp[arr[i]].first]==mat[0].size())
			return i;
	}
	return -1;
}
};