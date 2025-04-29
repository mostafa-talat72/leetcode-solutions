class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
	int fr1[26] = { 0 }, fr2[26] = { 0 };

	for (int i = 0; i < s1.size(); i++) {
		fr1[s1[i] - 'a']++;
		fr2[s2[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (fr1[i] != fr2[i]) return false;
	}

	int cnt = 0;

	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i]) cnt++;
	}
	return cnt <= 2;
}
};