class Solution {
public:
    int numRabbits(vector<int>& answers) { 
	unordered_map<int, int> m;
    for (int i = 0; i < answers.size(); i++)
    {
        m[answers[i]]++;
    }
    int ans = 0;
    for (auto it : m)
    {
        int key = it.first;
        int cnt = it.second;
        while (cnt > 0)
        {
            ans += key + 1;
            cnt -= key + 1;
        }
    }
    return ans;
}
};