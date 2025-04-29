class Solution {
public:
 int countPrefixSuffixPairs(vector<string>& words) {

	int ans = 0;
	for (int i = 0; i < words.size(); i++) {
		for (int j = i + 1; j < words.size(); j++) {
			if (words[i].size() > words[j].size() ||
				words[i][0] != words[j][0] ||
				words[i].back() != words[j].back()
				|| words[i].back() != words[j][words[i].size() - 1]
				|| words[i][0] != words[j][words[j].size() - words[i].size()]) continue;
			string pref=words[j].substr(0,words[i].size());
			string suf = words[j].substr(words[j].size() - words[i].size(), words[i].size());
			cout << pref << " " << suf << "\n";
			if (pref == words[i] && pref == suf) {
				ans++;
			}
		}
	}
	return ans;
}
};