class Solution {
public:
    void sortColors(vector<int>& nums) { 
   int cnt[3] = {0};
    for (auto it : nums)
        cnt[it]++;
    
   fill(nums.begin(), nums.begin() + cnt[0], 0);
    fill(nums.begin() + cnt[0], nums.begin() + cnt[0] + cnt[1], 1);
    fill(nums.begin() + cnt[0] + cnt[1],nums.end(), 2);
}
};