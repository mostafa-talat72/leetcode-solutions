class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
	sort(events.begin(), events.end());
	vector<int>seh(events.size());

	int mx = 0;
	for (int i = events.size() - 1; i >= 0; i--){
		seh[i] = events[i][0];
		mx = max(mx, events[i][2]);
		events[i].push_back(mx);
	}
	for (int i = 0; i < events.size(); i++) {
		int nextIdx = upper_bound(seh.begin(), seh.end(), events[i][1]) - seh.begin();
		if (nextIdx < events.size()) {
			mx = max(mx, events[i][2] + events[nextIdx][3]);
		}
	}
	return mx;
}
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();