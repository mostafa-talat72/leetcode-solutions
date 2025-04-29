class Solution {
public:
    bool isAnagram(string s, string t) {
	int freqS[26] = { 0 }, freqT[26] = { 0 };
	for (auto it : s)
		freqS[it - 'a']++;
	for (auto it : t)
		freqT[it - 'a']++;
	for (int i = 0; i < 26; i++)
		if (freqS[i] != freqT[i])return false;
	return true;
}
};