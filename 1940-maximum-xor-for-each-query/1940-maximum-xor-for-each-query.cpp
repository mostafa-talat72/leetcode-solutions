class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
	int power=pow(2,maximumBit);
	vector<int>ans(nums.size(), 0);
	int xorAns = 0;
	for (int i = 0; i < nums.size(); i++) {
		xorAns = xorAns ^ nums[i];
		if (xorAns != power - 1) {
			ans[nums.size() - 1 - i] = power - 1 - xorAns;
		}
	}
	return ans;
}
};