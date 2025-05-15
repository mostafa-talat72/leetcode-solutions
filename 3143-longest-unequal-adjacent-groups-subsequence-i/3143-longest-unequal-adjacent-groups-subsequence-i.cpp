class Solution {
public:
    vector<string> startWith(int start,vector<string>& words, vector<int>& groups) { 
    vector<string> ret;
    for (int i = 0; i < groups.size(); i++)
    {
        if (groups[i] == start)
        {
            ret.push_back(words[i]);
            start = 1 - start;
        }
    }
    return ret;
}
vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups)
{
    vector<string> ans1 = startWith(0, words, groups);
    vector<string> ans2= startWith(1, words, groups);
    return ans1.size() > ans2.size() ? ans1 : ans2;
}
};