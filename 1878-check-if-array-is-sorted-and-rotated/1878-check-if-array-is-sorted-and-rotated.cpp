class Solution {
public:
    bool check(vector<int>& nums) {
	set<int>st;
	for (int i = 0; i < nums.size(); i++) {
		st.insert(nums[i]);
	}

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1])continue;
		if (st.upper_bound(nums[i - 1]) != st.end() && *st.upper_bound(nums[i - 1]) != nums[i])
			return false;
	}

	return true;
}
};