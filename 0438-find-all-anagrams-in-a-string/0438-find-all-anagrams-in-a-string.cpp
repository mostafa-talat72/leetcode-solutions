class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>frP(26, 0);
        vector<vector<int>>frS(s.size() + 2, vector<int>(26, 0));
        for (auto i : p)
            frP[i - 'a']++;
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++)
        {
            frS[i][s[i] - 'a']++;
        }
        for (int i = 1; i < s.size(); i++)
        {
            for (int j = 0; j < 26; j++)
                frS[i][j] += frS[i - 1][j];
        }

        bool ok = 0;
        vector<int>ret;
        while (r < s.size())
        {
            if (r - l + 1 == p.size())
            {
                ok = 1;
                for (int j = 0; j < 26; j++)
                {
                    if (l == 0)
                    {
                        if (frS[r][j] != frP[j])
                        {
                            ok = 0;
                            break;
                        }
                    }
                    else
                    {
                        if (frS[r][j] - frS[l - 1][j] != frP[j])
                        {
                            ok = 0;
                            break;
                        }
                    }
                }
                if (ok)
                    ret.push_back(l);
                l++;
            }
                r++;
        }
        return ret;
    }
};