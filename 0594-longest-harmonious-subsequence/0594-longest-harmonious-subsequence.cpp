class Solution {
public:
    int findLHS(vector<int>& nums) {
	
	map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
		mp[nums[i]]++;
    }
    for (auto it : mp)
    {
        if (mp.find(it.first + 1) != mp.end())
		{
			ans = max(ans, it.second + mp[it.first + 1]);
        }
	}
    return ans;
}
};