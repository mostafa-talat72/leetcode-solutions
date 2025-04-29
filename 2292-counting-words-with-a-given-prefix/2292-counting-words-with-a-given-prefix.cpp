class Solution {
public:
   int prefixCount(vector<string>& words, string pref) {
	int ans = 0;
	for (string word : words) {
		if (word.size() >= pref.size() && word.substr(0, pref.size()) == pref) ans++;
	}
	return ans;
}
};