class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
	vector<vector<int>> ans(matrix[0].size(), vector<int>(matrix.size()));
	for (int i = ans.size() - 1; i >= 0;i--){
		for (int j = 0; j < ans[0].size(); j++) {
			ans[i][ans[0].size() - j - 1] = matrix[j][i];
		}
	}
	matrix = ans;
}
};