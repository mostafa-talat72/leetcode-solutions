class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
	sort(nums.begin(), nums.end());
	int n = nums[0].size();
	for (int i = 0; i < 1 << n; i++) {
		bitset<16>st(i);
		string num = "";
		for (int i = 0; i < n; i++)
			num.push_back(st[i] + '0');
		if (!binary_search(nums.begin(),nums.end(),num))
			return num;
	}
	return "";
}
};