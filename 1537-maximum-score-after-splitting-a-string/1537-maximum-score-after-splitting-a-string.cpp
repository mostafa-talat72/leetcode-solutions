class Solution {
public:
    int maxScore(string s) {
	int cnt = count(s.begin(), s.end(), '0'), out;

	cnt += (s.back() == '1') ? 1 : -1;
	out = cnt;

	for (int i = s.size() - 2; i >= 1; i--) {
		if (s[i] == '0') cnt--;
		else
		{
			cnt++;
			out = max(out, cnt);
		}
	}
	return out;
}
};