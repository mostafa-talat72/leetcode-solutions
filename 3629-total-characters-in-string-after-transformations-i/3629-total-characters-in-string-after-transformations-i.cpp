class Solution {
public:
    vector<int> getRemovableIndices(string str1, string str2)
{
    vector<int> ans;   
    string s1 = "", s2 = "";
    int n = str1.size();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    char del ='_';
	 for (int i = n-1; i >= 0 && str2.size(); i--)
     {
         if (i != n - 1)
         {
             char newCh = del;
             del = str1.back();
             str1.pop_back();
             s1.push_back(newCh);
             if (s1.size() > s2.size())
             {
                 s2.push_back(str2.back());
                 str2.pop_back();
             }
         }else
         {
             del = str1.back();
             str1.pop_back();
         }
			
		 if (str1 == str2 && s1 == s2)
             ans.push_back(n - i - 1);
	 }
     if (ans.empty())
         ans.push_back(-1);
     return ans;

}
int lengthAfterTransformations(string s, int t) {
    

    int fr[26] = {0}, inc[26] = {0};
    for (auto it : s)
        fr[it - 'a']++;
    int mod = 1e9 + 7;
    while (t--)
    {
        for (int i = 0; i < 26; i++)
        {
            fr[i] += inc[i];
            if (fr[i] >= mod)
                fr[i] -= mod;
            inc[i] = 0;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (i == 25)
            {
                inc[0] += fr[i];
                if (inc[0] >= mod)
                    inc[0] -= mod;
                inc[1] += fr[i];
                if (inc[1] >= mod)
                    inc[1] -= mod;
                fr[i] = 0;
            }
            else
            {
                inc[i + 1] += fr[i];
                if (inc[i + 1] >= mod)
                    inc[i + 1] -= mod;
                fr[i] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0;i < 26;i++)
    {
        ans += inc[i];
        if (ans >= mod)
            ans -= mod;
    }
    return ans;
}
};