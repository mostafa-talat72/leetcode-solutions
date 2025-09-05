class Solution {
public:
    void rotate(vector<int>& nums, int k) {
	
	k %= nums.size();
    reverse(nums.begin(), nums.begin() + nums.size() - k);
    reverse(nums.rbegin(),nums.rbegin() + k);
    reverse(nums.begin(), nums.end());
}
};