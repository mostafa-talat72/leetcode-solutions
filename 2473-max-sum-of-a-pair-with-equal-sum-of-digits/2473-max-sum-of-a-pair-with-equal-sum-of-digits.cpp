class Solution {
public:
    
int maximumSum(vector<int>& nums) {
	unordered_map<int, pair<int,int>> mp;
	int ans = -1;

	for (auto x : nums) {
		int cnt = 0, xx = x;
		while (xx) {
			cnt += xx % 10;
			xx /= 10;
		}
		if (mp.find(cnt) == mp.end())
			mp[cnt] = { x,0 };
		else {
			if (mp[cnt].first < x) {
				mp[cnt].second = mp[cnt].first;
				mp[cnt].first = x;
			}
			else if (mp[cnt].second < x) {
				mp[cnt].second = x;
			}
			ans = max(ans, mp[cnt].first + mp[cnt].second);
		}
	}
	return ans;
}
};