class Solution {
public:
    void solve(string gen, unordered_map<string, bool>&ans, unordered_map<char, int>&freq) {
	for (auto& it :freq) {
		if (it.second) {
			gen += it.first;
			ans[gen];
			it.second--;
			solve(gen, ans, freq);
			gen.pop_back();
			solve(gen, ans, freq);
			it.second++;
		}
	}
}
int numTilePossibilities(string tiles) {
	unordered_map<char, int>freq;
	unordered_map<string, bool>ans;
	for (auto it : tiles)
		freq[it]++;

	solve("", ans, freq);
	return ans.size();
}

};