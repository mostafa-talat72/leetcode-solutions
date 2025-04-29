class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
	int l = 1, r = 1e7, mid = 0, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		long long cnt = 0;
		if(mid)
		{
			for (auto it : candies) {
				cnt += it / mid;
				if (cnt >= k)
					break;
			}
		}
		if (cnt >= k)
		{
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	return ans;
}
};