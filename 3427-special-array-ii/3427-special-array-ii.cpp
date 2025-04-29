class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
	vector<int>check(nums.size(), -1);
	for (int i = 1; i < nums.size(); i++) {
		if (((nums[i] & 1) && !(nums[i - 1] & 1)) || (!(nums[i] & 1) && (nums[i - 1] & 1))){
			check[i] = check[i - 1];
		}else
		{
			check[i] = i - 1;
		}
	}
	vector<bool>ans(queries.size(), true);
	for (int i = 0; i < queries.size(); i++) {
		if (check[queries[i][1]] >= queries[i][0]) {
			ans[i] = false;
		}
	}
	return ans;

}
};