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
            mp.begin()->second.pop_back();
            if (mp.begin()->second.empty()) {
				mp.erase(mp.begin());
            }
            n -= 2;
        }
    }

	string ans = "";
    vector<int> idxs;
	for (auto& [c, v] : mp) {
		for (int i : v) {
            idxs.push_back(i);
		}
	}
    sort(idxs.begin(), idxs.end());
	for (int i = 0; i < idxs.size(); i++) 
        ans += s[idxs[i]];
    return ans;
}
};