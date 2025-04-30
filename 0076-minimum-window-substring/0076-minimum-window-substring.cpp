class Solution {
public:
    string minWindow(string s, string t) {
	vector<vector<int>> frLw(s.size() + 1, vector<int>(26, 0));
	vector<vector<int>> frUp(s.size() + 1, vector<int>(26, 0));
	vector<int> cntLw(26, 0);
	vector<int> cntUp(26, 0);

	for (int i = 0; i < t.size(); i++) {
		if(t[i]>='a' && t[i]<='z')
			cntLw[t[i] - 'a']++;
		else
			cntUp[t[i] - 'A']++;
	}

	for (int i = 1; i <= s.size(); i++) {
		if (s[i - 1] >= 'a' && s[i - 1] <= 'z')
			frLw[i][s[i - 1] - 'a']++;
		else
			frUp[i][s[i - 1] - 'A']++;
		for(int j=0;j<26;j++){
			frLw[i][j]+=frLw[i-1][j];
			frUp[i][j]+=frUp[i-1][j];
		}
	}
	int l = 1, r = 1, ans = INT_MAX, lw = -1;
	while(l<=r && r<=s.size())
	{
		if(r-l + 1 >= t.size())
		{
			bool f = 0;
			for (int i = 0; i < 26; i++) {
				if(cntLw[i] > (frLw[r][i] - frLw[l - 1][i]) || cntUp[i] > (frUp[r][i] - frUp[l - 1][i]))
				{
					f = 1;
					break;
				}
			}

			if (!f) {
				if(r - l + 1 < ans)
				{
					ans = r - l + 1;
					lw = l - 1;
				}
				l++;
			}
			else
				r++;
			
		}
		else
			r++;
	}
	return lw == -1 ? "" : s.substr(lw, ans);
}
};