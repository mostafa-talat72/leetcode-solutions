class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
	int l = 1, r = nums.size(), mid, ans = 1, n = nums.size();
	while (l <= r) {
		mid = (l + r) / 2;
		int left = 0, right = mid - 1;
		bool ok = 0;
		while (right < n) {
			ok = 1;
			if (right - left + 1 == mid) {
				for (int i = left; i <= right; i++) {
					for (int j = i + 1; j <= right; j++) {
						if ((nums[i] & nums[j])) {
							ok = 0;
							break;
						}
					}
					if (!ok)break;
				}
				left++;
				if (ok)break;
			}
			right++;
		}
		if (ok) {
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	return ans;
}
};