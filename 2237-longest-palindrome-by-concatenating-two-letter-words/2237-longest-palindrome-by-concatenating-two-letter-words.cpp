class Solution {
public:
    int longestPalindrome(vector<string>& words) {

	unordered_map<string, int> mp;
	for (auto& word : words) {
		mp[word]++;
    }
    int ans = 0;
    bool hasOdd = false;
    for (auto &it : mp) {
		string word = it.first;
		if (word[0] == word[1]) {
            if (it.second & 1)
            {
                ans += (it.second - 1) * 2;
				hasOdd = true;
			} else {
				ans += it.second * 2;
			}
        }
        else
        {
            string revWord = string(1, word[1]) + string(1, word[0]);
            if (mp.find(revWord) != mp.end()) {
				ans += min(it.second, mp[revWord]) * 4;
				mp.erase(revWord);
                mp[revWord] -= min(it.second, mp[revWord]);
                it.second -= min(it.second, mp[revWord]);
            }
		}
    }
    return ans + hasOdd * 2;
	
}
};