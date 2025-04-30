class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
	stack<pair<int, int>> st;
	vector<int>ret(temperatures.size(), 0);
	for (int i = 0; i < temperatures.size(); i++) {
		while (!st.empty() && st.top().first < temperatures[i]) {
			ret[st.top().second] = i - st.top().second;
			st.pop();
		}
		st.push({ temperatures[i],i });
	}
	return ret;
}
};