class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
	int n = nums.size(), ans = 0;
	vector<int>flip(n + 1, 0);
	for (int i = 0; i < n; i++) {
		if (i)flip[i] += flip[i - 1];
		if (!nums[i] && !(flip[i] & 1)) {
			if (i + k - 1 >= n)return -1;
			flip[i]++;
			if (i + k < n)flip[i + k]--;
			ans++;
		}
		else if (nums[i] && (flip[i] & 1)) {
			if (i + k - 1 >= n)return -1;
			flip[i]++;
			if (i + k < n)flip[i + k]--;
			ans++;
		}
	}
	return ans;
}
};