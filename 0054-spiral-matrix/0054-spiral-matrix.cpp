class Solution {
public:
 vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ans;
	int n = matrix.size(), m = matrix[0].size();
	int c = 0;

	for (int i = 0; i < n && c < m; i++)
	{
		for (int j = c; j < m; j++)
		{
			ans.push_back(matrix[i][j]);
		}
		for (int row = i + 1; row < n; row++)
		{
			ans.push_back(matrix[row][m - 1]);
		}
		m--;
		n--;
		for (int col = m - 1; col >= c; col--)
		{
			ans.push_back(matrix[n][col]);
		}

		for (int row = n - 1; row > i ; row--)
		{
			ans.push_back(matrix[row][c]);
		}
		c++;
	}
	while (ans.size() > matrix.size() * matrix[0].size())
		ans.pop_back();
	return ans;
}
};