class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
	sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0]; });
	map<int, int> mp;
	for (int i = 0; i < items.size(); i++) {
		if (i != 0) {
			mp[items[i][0]] = max({ mp[items[i - 1][0]], mp[items[i][0]] , items[i][1] });
		}else
		{	
			mp[items[i][0]] = items[i][1];
		}
	}
	vector<int>ans;
	for (int i = 0; i < queries.size(); i++) {
		if(mp.begin()->first > queries[i]){
			ans.push_back(0);
			continue;
		}
		auto it = mp.upper_bound(queries[i]);
		it--;
		ans.push_back(it->second);
	}

	return ans;
}
};