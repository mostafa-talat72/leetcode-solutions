class Solution {
public:
    int possibleStringCount(string word) {

	int cnt = 1, ans = 1;
    for (int i = 1; i < word.size(); i++)
    {
		if (word[i] != word[i - 1]) {
            ans += cnt - 1;
            cnt = 0;
		}
        cnt++;
	}
    ans += cnt - 1;
    return ans;
	
}
};