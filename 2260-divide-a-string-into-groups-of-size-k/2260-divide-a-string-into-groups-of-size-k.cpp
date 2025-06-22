class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
	
	vector<string> ans;
    string temp = "";
    for (auto it : s)
    {
        temp.push_back(it);
		if (temp.size() == k) {
            ans.push_back(temp);
            temp = "";
		}
	}
    while (temp.size() )
    {
        temp.push_back(fill);
        if (temp.size() == k)
        {
            ans.push_back(temp);
            break;
        }
	}
    return ans;
    
}
};