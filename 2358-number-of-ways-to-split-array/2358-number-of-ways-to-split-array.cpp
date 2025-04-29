class Solution {
public:
   int waysToSplitArray(vector<int>& nums) {
	long long sum = 0, startSum = nums[0];
	for(int i=1;i<nums.size();i++) {
		sum += nums[i];
	}

	int ans = 0;
	if (startSum >= sum)
		ans++;
	for (int i = 1; i < nums.size() - 1; i++) {
		
		startSum += nums[i];
		sum -= nums[i];
		if (startSum >= sum)
			ans++;
	}
	return ans;

}
};