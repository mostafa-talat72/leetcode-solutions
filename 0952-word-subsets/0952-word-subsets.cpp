class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
	vector<string>ans;
	vector<vector<int>>freq(words1.size(), vector<int>(26, 0));
	vector<int>freq2(26, 0);
	for (int i = 0; i < words1.size(); i++) {
		for (int j = 0; j < words1[i].size(); j++) {
			freq[i][words1[i][j] - 'a']++;
		}
	}

	for (int i = 0; i < words2.size(); i++) {
		vector<int>frexp(26, 0);
		for (int j = 0; j < words2[i].size(); j++) {
			frexp[words2[i][j] - 'a']++;
			freq2[words2[i][j] - 'a'] = max(freq2[words2[i][j] - 'a'], frexp[words2[i][j] - 'a']);
		}
	}

	for (int i = 0; i < freq.size(); i++) {
		bool ok = 1;
		for (int k = 0; k < 26; k++) {
			if (freq[i][k] < freq2[k]) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			ans.push_back(words1[i]);
		}
	}
	return ans;
}
};