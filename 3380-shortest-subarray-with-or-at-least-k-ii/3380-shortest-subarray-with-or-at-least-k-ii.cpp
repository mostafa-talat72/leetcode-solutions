class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
	int l = 0, r = 0, ans = INT_MAX;
	int mp[32] = { 0 };
	bitset<32> sum(0);
	while (l <= r && r < nums.size()) {
		if ((sum.to_ullong() | nums[r]) >= k) {
			ans = min(ans, r - l + 1);
			for (int i = 0; i < 32; i++)
			{
				if ((nums[l] & (1LL << i)))
					mp[i]--;
				if(!mp[i])
					sum[i] = 0;
			}
			l++;
		}
		else{

			for (int i = 0; i < 32; i++)
			{
				if ((nums[r] & (1LL << i)))
					mp[i]++;
				if(mp[i])
					sum[i] = 1;
			}
			r++;
		}
		
	}
	return ans == INT_MAX ? -1 : ans;
}
};