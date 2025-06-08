class Solution {
public:
    vector<int> lexicalOrder(int n)
{ 
	
	set<string> s;
	for (int i = 1; i <= n; i++)
	{
		s.insert(to_string(i));
    }
    vector<int> ans;
	for (auto it : s)
	{
		ans.push_back(stoi(it));
    }
    return ans;
}
};