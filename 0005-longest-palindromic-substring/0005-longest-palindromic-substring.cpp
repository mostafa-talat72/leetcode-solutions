class Solution {
public:
    string longestPalindrome(string s) {
	string ans = "", tst = "";
	deque<char> tst1, tst2;
	ans += s[0];
	for (int i = 0; i < s.size(); i++) {
		tst.clear();
		tst1.clear();
		tst2.clear();
		for (int j = i; j < s.size(); j++) {
			tst += s[j];
			tst1.push_back(s[j]);
			tst2.push_front(s[j]);
			if (tst2 == tst1) {
				if (ans.size() < tst.size()) ans = tst;
			}
		}
	}

	return ans;
}
};