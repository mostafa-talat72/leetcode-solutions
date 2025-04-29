class Solution {
public:
int Ceil(int num, int div) { return (num + div - 1) / div; }

int minimumSize(vector<int>& nums, int maxOperations) {
	sort(nums.begin(), nums.end());
	int l = 1, r = nums.back() - 1, mid, ans = nums.back();
	while (l <= r) {
		mid = (l + r) / 2;
		int tempOperations = maxOperations, tst = 0, i;
		for (i = nums.size() - 1; i >= 0 && tempOperations; i--)
		{
			if (nums[i] <= mid)
				break;
			int cl = min(nums[i] / mid, tempOperations);
			bool ok = 0;
			if (nums[i] - (cl * mid) == 0)
			{
				tst = max(tst, mid);
				tempOperations -= cl - 1;
			}
			else
			{
				tst = max(tst, nums[i] - (cl * mid));
				tempOperations -= cl;
			}
		}
		if (i >= 0)
			tst = max(tst, nums[i]);
		if (mid >=tst)
		{
			r = mid - 1;
			ans = mid;
		}
		else
			l = mid + 1;
	}
	
	return ans;
}
};