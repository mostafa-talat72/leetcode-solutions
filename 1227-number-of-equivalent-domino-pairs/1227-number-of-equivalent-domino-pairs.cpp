class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
{ int n = dominoes.size();
    for (auto &it :dominoes)
        sort(it.begin(), it.end());
    int m[10][10] = {0};
    int ans = 0;
    for (int i = 0; i < n; i++)
        m[dominoes[i][0]][dominoes[i][1]]++;
    for (int i = 1; i < 10; i++)
        for (int j = 1; j < 10; j++)
            if (m[i][j] > 1)
                ans += (m[i][j] * (m[i][j] - 1)) / 2;
    return ans;
}
};