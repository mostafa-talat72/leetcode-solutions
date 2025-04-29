class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
	vector<int>ans;
	set<int>st;
	unordered_map<int, int>mp, mp2;
	for (auto it : queries) {
		if(mp[it[0]] == 0)
		{
			st.insert(it[1]);
			mp[it[0]] = it[1];
			mp2[it[1]]++;
		}
		else{
			mp2[mp[it[0]]]--;
			if (!mp2[mp[it[0]]])
				st.erase(mp[it[0]]);
			st.insert(it[1]);
			mp[it[0]] = it[1];
			mp2[it[1]]++;
		}
		ans.push_back(st.size());
	}
	return ans;
}
};