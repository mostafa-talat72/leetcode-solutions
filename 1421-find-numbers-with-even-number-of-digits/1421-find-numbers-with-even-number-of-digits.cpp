class Solution {
public:
    int findNumbers(vector<int>& nums) { 
	
	int ans = 0;
    for (auto it : nums)
    {
        ans += !(to_string(it).size() & 1);
    }
    return ans;
}
};