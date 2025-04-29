class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
	string ans = "";
	reverse(spaces.begin(), spaces.end());
	int i = 0;
	while(i<s.size())
	{
		if(spaces.size() && i== spaces.back())
		{
			ans += ' ';
			spaces.pop_back();
		}
		ans += s[i];
		i++;
	}
	return ans;
}
};