class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int l = lower - nums[i];
        int r = upper - nums[i];
        int left = lower_bound(nums.begin() + i + 1, nums.end(), l) - nums.begin();
        int right = upper_bound(nums.begin() + i + 1, nums.end(), r) - nums.begin();
        ans += right - left;
    }
    return ans;
}
};