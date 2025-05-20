class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) { 
    vector<int> pref(nums.size() + 1, 0);
    for (int i = 0; i < queries.size(); i++)
    {
        pref[queries[i][0]] += 1;
        pref[queries[i][1] + 1] -= 1;
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