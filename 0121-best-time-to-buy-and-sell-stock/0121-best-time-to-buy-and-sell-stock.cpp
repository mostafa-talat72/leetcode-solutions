class Solution {
public:
    int maxProfit(vector<int>& prices) {
	priority_queue<int, vector<int>, greater<int>> pq;
	int ans = 0;
	for(auto x:prices) {
		if (!pq.empty())
			ans = max(ans, x - pq.top());
		pq.push(x);
	}
	return ans;
}
};