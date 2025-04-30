class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
	int ans = 0, tst = 0, conv, sum = 0, n = matrix.size(), m = matrix[0].size(), mnconvert = INT_MAX;
	vector<int>converter;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += matrix[i][j];
		}
		if (sum == m || sum == 0)
			tst++;
		else
		{
			if (m - sum > sum)
			{	
				if(mnconvert>sum)
				{
					mnconvert = sum;
					conv = 1;
				}
			}else
			{
				if (mnconvert > m - sum)
				{
					mnconvert = m - sum;
					conv = 0;
				}
			}
			converter.push_back(i);
		}
	}
	ans = tst;
	for (int i = 0; i < converter.size(); i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[converter[i]][j] == conv)
				for (int k = 0; k < n; k++)
				{
					matrix[k][j] = !matrix[k][j];
				}
		}
		tst = 0;
		for (int j = 0; j < n; j++)
		{
			sum = 0;
			for (int k = 0; k < m; k++)
			{
				sum += matrix[j][k];
			}
			if (sum == m || sum == 0)
				tst++;
		}
		ans = max(ans, tst);
	}

	return ans;
}
};