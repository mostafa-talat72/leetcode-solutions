class Solution {
public:
   int minimizedMaximum(int n, vector<int>& quantities) {
	long long sum = 0;
	for (int i = 0; i < quantities.size(); i++) {
		sum += quantities[i];
	}
	long long ans = sum;
	long long l = 1, r = sum, mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		int cnt = 0;
		for (int i = 0; i < quantities.size(); i++) {
			cnt += (quantities[i] + mid - 1) / mid;
		}
		if (cnt <= n)
		{
			r = mid;
			ans = min(ans, mid);
		}
		else
			l = mid + 1;
	}
	return ans;
}
};