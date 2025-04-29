class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
	int sum = 0, mxPos = 0, mxNeg = 0, ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (sum < 0)
		{
			ans = max(abs(sum - mxPos), ans);
			mxNeg = min(mxNeg, sum);
		}
		else {
			ans = max(abs(sum - mxNeg), ans);
			mxPos = max(mxPos, sum);
		}
		
	}
	return ans;
}
};