class Solution {
public:
    bool canConstruct(string s, int k) {
	int odd=0,even=0;
	vector<int>freq(26,0);
	for (int i = 0; i < s.size(); i++)
	{
		freq[s[i] - 'a']++;
		if(freq[s[i] - 'a'] & 1) odd++;
		else{
			odd--;
			even++;
		}
	}

	if (odd > k) return false;
	k -= odd;
	return (even * 2) >= k;
}
};