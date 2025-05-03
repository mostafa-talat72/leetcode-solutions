class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
	int zeros = 0, Proudct = 1;
	vector<int> ans(nums.size(), 0);
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) {
			zeros++;
		}
		else {
			Proudct *= nums[i];
		}
	}
	if(zeros>1) return ans;
	for (int i = 0; i < nums.size(); i++) {
		if(nums[i] == 0) {
			ans[i] = Proudct;
		}
		else if(zeros) {
			ans[i] = 0;
		}
		else {
			ans[i] = Proudct / nums[i];
		}
	}
	return ans;
}
};