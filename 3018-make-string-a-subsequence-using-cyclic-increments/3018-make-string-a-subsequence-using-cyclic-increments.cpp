class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
	int freq[26] = { 0 }, j = 0;
	for (int i = 0; i < str1.size() && j < str2.size(); i++) {
		freq[str1[i] - 'a']++;
		if (freq[str2[j] - 'a'] <= 0) {
			if (str2[j] == 'a' && freq[25] > 0) {
				j++;
				freq[25]--;
			}
			else if (str2[j] != 'a' && freq[str2[j] - 'a' - 1] > 0) {
				freq[str2[j] - 'a' - 1]--;
				j++;
			}
		}
		else
			j++;
	}
	return j == str2.size();
}
};