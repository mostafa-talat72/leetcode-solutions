class Solution {
public:
    bool divideArray(vector<int>& nums) {
	int mp[501];
	for (auto it : nums)
		mp[it]++;
	for (int i = 1; i <= 500; i++)
		if (mp[i] & 1)
			return false;

	return true;
}
};