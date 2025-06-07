struct Compare
{
    bool operator()(pair<char, int> a, pair<char, int> b)
    {
        if (a.first < b.first)
            return true;
        else if (a.first > b.first)
            return false;
        else
            return a.second > b.second;
    }
};
class Solution {
public:
    string clearStars(string s)
{ 

	map<char, vector<int>> mp;
    priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
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