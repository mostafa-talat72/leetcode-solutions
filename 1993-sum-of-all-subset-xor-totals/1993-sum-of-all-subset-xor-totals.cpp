class Solution {
public:
    int sumNum(vector<int>& nums, int i, int n, int sum) {
	if (i == n)
		return sum;
	return sumNum(nums, i + 1, n, sum ^ nums[i]) + sumNum(nums, i + 1, n, sum);
}
int subsetXORSum(vector<int>& nums) {
	int n = nums.size();
	return sumNum(nums, 0, n, 0);
}
};