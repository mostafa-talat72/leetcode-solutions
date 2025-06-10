class Solution {
public:
    int maxDifference(string s) { 
	
	int fr[26] = {0};
	for (int i = 0; i < s.size(); i++) {
		fr[s[i] - 'a']++;
    }
    int mxOdd = 0, mnEven = s.size();
    for (int i = 0; i < 26; i++)
    {
        if (fr[i] == 0)
            continue; 
        if (fr[i] % 2 == 0)
        {
            mnEven = min(mnEven, fr[i]);
        }
        else
        {
            mxOdd = max(mxOdd, fr[i]);
        }
    }

	return mxOdd - mnEven;
}
};