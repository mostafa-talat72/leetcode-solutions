class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
	long long ans = 0;
	long long i = nums[0];
	long long d = 0;
	for (int k = 2;k < nums.size();k++)
	{
		d = max(d, i - nums[k - 1]);
		ans = max(ans, 1LL * nums[k] * d);
		i = max(i, 1LL * nums[k - 1]);

	}
	return ans;
}
};