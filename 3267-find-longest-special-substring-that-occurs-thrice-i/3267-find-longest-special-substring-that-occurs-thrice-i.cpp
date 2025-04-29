class Solution {
public:
    int maximumLength(string s) {

	vector<vector<int>>letter(26);
	int cnt = 1;
	for (int i = 1; i < s.size(); i++) {
		if(s[i]!=s[i-1]){
			letter[s[i-1]-'a'].push_back(cnt);
			cnt = 0;
		}
		cnt++;
	}
	letter[s.back() - 'a'].push_back(cnt);
	cnt = -1;
	for(int i=0;i<26;i++){
		sort(letter[i].rbegin(), letter[i].rend());
		while (letter[i].size() > 3)
			letter[i].pop_back();
		if (letter[i].size() == 3){
			cnt = max(cnt, letter[i][2]);
			letter[i].pop_back();
		}
		int sum=accumulate(letter[i].begin(), letter[i].end(), 0);
		if (letter[i].size() == 2 && sum >= 3) {
			if (letter[i][1] == letter[i][0])
			{
				cnt = max(cnt, letter[i][1] - 1);
			}
			else {
				cnt = max(cnt, letter[i][1]);
			}
		}
		for(int j=0;j<letter[i].size();j++){
			if (letter[i][j] >= 3)
				cnt = max(cnt, letter[i][j] - 2);
		}
	}
	return cnt;
}
};