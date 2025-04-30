class Solution {
public:
   long long maximumSubarraySum(vector<int>& nums, int k) {
	int mp[100001] = { 0 };
	long long ans = 0, sum = 0;
	int l = 0, r = 0, cnt = 0;
	while (r < nums.size()) {
		if (!mp[nums[r]]) {
			cnt++;
		}
		mp[nums[r]]++;
		sum += nums[r];
		if (r - l + 1 == k) {
			if (cnt == k) {
				ans = max(ans, sum);
			}
			mp[nums[l]]--;
			if (!mp[nums[l]]) cnt--;
			sum -= nums[l];
			l++;
		}
		r++;
	}
	return ans;
}
};