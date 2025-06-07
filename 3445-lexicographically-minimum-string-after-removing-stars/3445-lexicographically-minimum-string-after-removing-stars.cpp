class Solution {
public:
    string clearStars(string s) { 

	map<char, vector<int>> mp;
    int n = s.size();
    for (int i=0;i<s.size();i++) {
		if (s[i] != '*') {
			mp[s[i]].push_back(i);
        }
        else
        {
            s[i] = ' ';
            s[mp.begin()->second.back()] = ' ';
            mp.begin()->second.pop_back();
            if (mp.begin()->second.empty()) {
				mp.erase(mp.begin());
            }
        }
    }
    s.erase(remove(s.begin(), s.end(), ' '), s.end());

	return s;
}
};