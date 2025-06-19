class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
	
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0, last = -1, div = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (last == -1 || last - nums[i] + div > k)
        {
            last = nums[i];
            div = 0;
            ans++;
        }
        else
        {
            div += last - nums[i];
            last = nums[i];
        }
    }
    return ans;

}
};