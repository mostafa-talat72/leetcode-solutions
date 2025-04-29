class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
	sort(ranks.begin(), ranks.end());
	long long l = 1, r = 1e15, mid, ans = LLONG_MAX, tst;
	while (l <= r) {
		mid = (l + r) / 2;
		bool ok = 1;
		tst = 0;
		for (auto it : ranks) {
			long long l2 = 1, r2 = 1e7, mid2, tst2 = 0;
			ok = 0;
			while (l2 <= r2) {
				mid2 = (l2 + r2) / 2;
				if (it * mid2 * mid2 <= mid) {
					ok = 1;
					l2 = mid2 + 1;
					tst2 = mid2;
				}
				else {
					r2 = mid2 - 1;
				}
			}
			if (!ok)
				break;
			tst += tst2;
			if (tst >= cars)break;
		}
		if (ok && tst >= cars) {
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return ans;
}
};