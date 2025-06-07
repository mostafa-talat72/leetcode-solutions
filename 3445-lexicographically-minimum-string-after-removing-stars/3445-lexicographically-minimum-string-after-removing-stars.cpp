struct Compare
{
    bool operator()(pair<char, int> a, pair<char, int> b)
    {
        if (a.first > b.first)
            return true;
        else if (a.first < b.first)
            return false;
        else
            return a.second < b.second;
    }
};
class Solution {
public:
    string clearStars(string s)
{ 

    priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
    int n = s.size();
    for (int i=0;i<s.size();i++) {
		if (s[i] != '*') {
            pq.push({s[i], i});
        }
        else
        {
            s[i] = ' ';
            s[pq.top().second] = ' ';
            pq.pop();
        }
    }
    s.erase(remove(s.begin(), s.end(), ' '), s.end());

	return s;
}
};