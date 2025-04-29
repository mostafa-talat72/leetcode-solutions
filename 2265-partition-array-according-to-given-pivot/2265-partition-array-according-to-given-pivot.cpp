class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
	vector<int>less, equal, greater;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < pivot) {
			less.push_back(nums[i]);
		}
		else if (nums[i] == pivot) {
			equal.push_back(nums[i]);
		}
		else {
			greater.push_back(nums[i]);
		}
	}
	vector<int>res;
	for (int i = 0; i < less.size(); i++) {
		res.push_back(less[i]);
	}
	for (int i = 0; i < equal.size(); i++) {
		res.push_back(equal[i]);
	}
	for (int i = 0; i < greater.size(); i++) {
		res.push_back(greater[i]);
	}
	return res;
}
};