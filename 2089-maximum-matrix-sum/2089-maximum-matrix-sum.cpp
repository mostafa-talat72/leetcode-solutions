class Solution {
public:
   
long long maxMatrixSum(vector<vector<int>>& matrix) {
	long long ans = 0;
	int neg = 0, mn = 1e9, connectedZeros = 0, n = matrix.size(), m = matrix[0].size();
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans += abs(matrix[i][j]);
			mn = min(mn, abs(matrix[i][j]));
			if (matrix[i][j] < 0)
			{
				neg++;
			}else if(matrix[i][j] == 0)
			{
				connectedZeros++;
			}
		}
	}
	if(neg &1)
	{
		if (!connectedZeros)
			return ans - 2 * mn;
	}
	return ans;
}
};