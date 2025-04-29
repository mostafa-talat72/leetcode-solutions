class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
	unordered_map<int, int> rows, cols;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if(matrix[i][j] == 0){
				rows[i] = 1;
				cols[j] = 1;
			}
		}
	}

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (rows[i] || cols[j]) {
				matrix[i][j] = 0;
			}
		}
	}
}
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();