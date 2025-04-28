class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
	vector<int>axis;
	for (auto it : grid)
		for (auto i : it)
			axis.push_back(i);
	sort(axis.begin(), axis.end());
	int siz = axis.size();
	siz = siz / 2;
	int ans = 0;
	for (auto it : axis) {
		if (abs(it - axis[siz]) % x != 0)
			return -1;
		ans += abs((it - axis[siz])) / x;
	}
	return ans;
}
};