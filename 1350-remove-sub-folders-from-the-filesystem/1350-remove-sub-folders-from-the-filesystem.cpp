class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
	sort(folder.begin(), folder.end());
	map<int, map<string,int>>mp;
	for (auto it : folder)
	{
		bool ok = 0;
		int cnt = count(it.begin(), it.end(), '/');
		string temp = it;
		int cntT=cnt;
		cntT--;
		while (!temp.empty())
		{
			temp.pop_back();
			if (temp.back() == '/')
			{
                temp.pop_back();
				if (mp[cntT].find(temp) == mp[cntT].end()) {
					ok = 1;
				}
				else
				{
					ok = 0;
					break;
				}
				cntT--;
			}
			
			
		}

		if (ok) {
			mp[cnt][it] = 1;
		}
	}
	vector<string>ans;

	for (auto it : mp)
	{
		for (auto i : it.second)
		{
			ans.push_back(i.first);
		}
	}
	return ans;
}
};