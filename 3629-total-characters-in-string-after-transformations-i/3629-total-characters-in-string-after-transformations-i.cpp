class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
    

    int fr[26] = {0}, inc[26] = {0};
    for (auto it : s)
        fr[it - 'a']++;
    int mod = 1e9 + 7;
    while (t--)
    {
        for (int i = 0; i < 26; i++)
        {
            if (!inc[i])
                continue;
            fr[i] += inc[i];
            if (fr[i] >= mod)
                fr[i] -= mod;
            inc[i] = 0;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (!fr[i])
                continue;
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
        if (!inc[i])
            continue;
        ans += inc[i];
        if (ans >= mod)
            ans -= mod;
    }
    return ans;
}
};