class Solution {
public:
    int countPalindromicSubsequence(string s) {
	vector<vector<int>>letter(26);
	for (int i = 0; i < s.size(); i++) {
		letter[s[i] - 'a'].push_back(i);
	}

	int ans = 0;
	for (int i = 0; i < 26; i++) {
		if(letter[i].size()>1) {
			
			for(int j=0;j<26;j++) {
				if(letter[j].empty()) continue;
				int l = upper_bound(letter[j].begin(), letter[j].end(), letter[i][0]) - letter[j].begin();
				if (l < letter[j].size() && letter[j][l] < letter[i].back())
					ans++;
			}
		}
	}
	return ans;
}
};