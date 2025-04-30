class Solution {
public:
   vector<int> partitionLabels(string s) {
	vector<pair<int, int>> ranges(26, { -1,-1 });
	for (int i = 0; i < s.size(); i++) {
		if(ranges[s[i] - 'a'].first == -1) {
			ranges[s[i] - 'a'].first = i;
		}
		ranges[s[i] - 'a'].second = i;
	}
	sort(ranges.begin(), ranges.end());
	vector<int>ans;
	int cnt = 0, start, end;
	for (int i = 0; i < 26; i++) {
		if (ranges[i].first == -1)continue;
		if(i==0 || start == -1)
		{
			start=ranges[i].first;
			end = ranges[i].second;
		}
		else if (ranges[i].first <= end ){
			end = max(end, ranges[i].second);
		}
		else {
			ans.push_back(end - start + 1);
			start = ranges[i].first;
			end = ranges[i].second;
		}
	}
	ans.push_back(end - start + 1);
	return ans;
}
};