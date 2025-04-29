class Solution {
public:
   int tupleSameProduct(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int ans = 0, n = nums.size();
	unordered_map<int, int>mp;
	for (int i = 0; i < n; i++) {
		mp[nums[i]] = i;
	}

	for (int i = 0; i < n ; i++) {
		for (int j = n - 1; j > i; j--) {
			int product = nums[i] * nums[j];
			int ii = i + 1;
			while (ii < j) {
				int sub = 0;
				if (product % nums[ii] == 0) {
					sub = product / nums[ii];
					if (mp.find(sub) != mp.end() && sub != nums[ii] && sub != nums[i] && sub != nums[j]) {
						ans += 4;
					}
				}
				ii++;
			}
		}
	}
	
	
	return ans;
}
};