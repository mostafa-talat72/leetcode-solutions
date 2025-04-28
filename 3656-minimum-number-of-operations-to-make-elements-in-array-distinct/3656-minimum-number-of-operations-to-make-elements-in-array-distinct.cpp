class Solution {
public:
   int minimumOperations(vector<int>& nums) {
	int fr[101] = { 0 };
	bool ok = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (++fr[nums[i]] > 1) {
			ok = 1;
		}
	}
	if (!ok)return 0;
	int ans = 0, i = 0;
	for (;i < nums.size() && ok;i += 3) {
		ans++;
		fr[nums[i]]--;
		if (i + 1 >= nums.size())break;
		fr[nums[i + 1]]--;
		if (i + 2 >= nums.size())break;
		fr[nums[i + 2]]--;
		ok = 0;
		for (int j = 1; j <= 100; j++) {
			if (fr[j] > 1) {
				ok = 1;
				break;
			}
		}
	}
	return ans;
}
};