class Solution {
public:
    void solve(  int n, string& ans,int &k) {
	if (ans.size() == n) {
		k--;
		return;
	}
	for (char c = 'a'; c <= 'c' && k; c++) {
		if (ans.empty() || ans.back() != c) {
			ans.push_back(c);
			solve(n, ans, k);
			if (k)
				ans.pop_back();
		}

	}
}

string getHappyString(int n, int k) {
	string ans;
	solve( n, ans, k);
	return ans;
}
};