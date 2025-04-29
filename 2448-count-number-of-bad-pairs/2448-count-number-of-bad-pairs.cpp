class Solution {
public:
   long long countBadPairs(vector<int>& nums) {
	unordered_map<int, int>mp;
	long long ans= (nums.size() * (nums.size() - 1)) / 2;
	for (int i = 0; i < nums.size(); i++)
		mp[nums[i] - i]++;
	for (auto it : mp) {
		long long cnt = it.second;
		ans -= (cnt * (cnt - 1)) / 2;
	}
	return ans;
}
};