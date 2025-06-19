class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
	
    sort(nums.begin(), nums.end());
    int n = nums.size(), ans = 1, last = nums[n-1], div = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (last - nums[i] + div > k)
        {
            div = 0;
            ans++;
        }
        else
        {
            div += last - nums[i];
        }
        last = nums[i];
    }
    return ans;

}
};