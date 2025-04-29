class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) { 
	
	int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
    long long ans = 0;
    vector<int> mxNums;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == mx)
        {
            mxNums.push_back(i);
        }
    }
    if (mxNums.size() < k)
    {
        return 0;
    }
    int l = 0, r = k - 1;

    while (r < mxNums.size())
    {
        int left = l == 0 ? mxNums[l] : mxNums[l] - mxNums[l - 1] - 1;
        int right = n - mxNums[r] - 1; 
        ans += 1 + left + right + 1LL * left * right;
        l++;
        r++;
    }
    return ans;
}
};