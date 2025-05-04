class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
{ int n = dominoes.size();
    for (auto &it :dominoes)
        sort(it.begin(), it.end());
    map<pair<int, int>, int> m;
    int ans = 0;
    for (auto it : dominoes)
        m[{it[0], it[1]}]++;
    for (auto it : m)
        ans += (it.second * (it.second - 1)) / 2;
    return ans;
}
};