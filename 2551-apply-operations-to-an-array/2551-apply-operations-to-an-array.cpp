class Solution {
public:

vector<int> applyOperations(vector<int>& nums) {
	vector<int>ret;
	int zero = 0;
	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i] == nums[i + 1])
		{
			nums[i] *= 2;
			nums[i + 1] = 0;
		}
		if (nums[i] != 0)
			ret.push_back(nums[i]);
	}
	ret.push_back(nums.back());
	while (ret.size()!=nums.size())
		ret.push_back(0);
	return ret;
}
};