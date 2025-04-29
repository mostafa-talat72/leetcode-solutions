class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
	vector<int>ans(prices.size(), 0);
	priority_queue<pair<int,int>>q;

	for(int i=0;i<prices.size();i++)
	{
		while (!q.empty() && q.top().first >= prices[i])
		{
			ans[q.top().second] = q.top().first - prices[i];
			q.pop();
		}
		q.push({ prices[i],i });
	}
	while (!q.empty()){
		ans[q.top().second] = q.top().first;
		q.pop();
	}
	return ans;
}
};