class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) { 
    
    
    vector<int> pref(nums.size() + 1, 0);
    while (queries.size())
    {
        pref[queries.back()[0]] += 1;
        pref[queries.back()[1] + 1] -= 1;
        queries.pop_back();
    }
    nums[0] -= pref[0];
    if (nums[0] > 0)
        return false;
    for (int i = 1; i < nums.size(); i++)
    {
        pref[i] += pref[i - 1];
        nums[i] -= pref[i];
        if (nums[i] > 0)
            return false;
    }
    return true;
}
};