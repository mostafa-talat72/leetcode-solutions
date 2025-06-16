class Solution {
public:
    int maximumDifference(vector<int>& nums) {
	
	
	int ans = -1, mxNum = nums.back(); 
	for (int i = nums.size() - 2; i >= 0; i--)
    {
        cout << nums[i] << " " << mxNum << " " << mxNum - nums[i] << endl;
        if (mxNum == nums[i])
            continue; 
		ans = max(ans, mxNum - nums[i]);
        mxNum = max(mxNum, nums[i]);
    }
    return ans;
}
};