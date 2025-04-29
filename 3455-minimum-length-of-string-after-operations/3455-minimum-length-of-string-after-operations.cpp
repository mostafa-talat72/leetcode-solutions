class Solution {
public:
 int minimumLength(string s) {
	int cnt[26] = { 0 };
	for (char c : s) {
		cnt[c - 'a']++;
	}
	int out = 0;
	for(int i=0;i<26;i++){
		if (cnt[i] >=3) {
			out += (cnt[i] & 1) ? 1 : 2;
		}
		else
			out += cnt[i];
	}
	return out;
}
};