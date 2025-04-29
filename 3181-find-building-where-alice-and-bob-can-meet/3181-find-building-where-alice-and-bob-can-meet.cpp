class Solution {
public:
   vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
	vector < pair<int, pair<int, pair<int, int>>>>nums;
	vector<int>ans(queries.size(), -1);
	for (int i = 0; i < queries.size(); i++)
	{
		if (heights[queries[i][0]] > heights[queries[i][1]] && queries[i][0] >= queries[i][1]) {
			ans[i] = queries[i][0];
		}
		else if (heights[queries[i][0]] < heights[queries[i][1]] && queries[i][0] <= queries[i][1]) {
			ans[i] = queries[i][1];
		}
		else if (queries[i][0] == queries[i][1]) {
			ans[i] = queries[i][0];
		}
		else
		{
			nums.push_back({ max(heights[queries[i][0]],heights[queries[i][1]]), {max(queries[i][0], queries[i][1]),{min(queries[i][0], queries[i][1]),i}} });
		}
	}

	sort(nums.begin(), nums.end());
	priority_queue<pair<int, int>>pq;

	for (int i = 0; i < heights.size(); i++) {
		pq.push({ heights[i], i });
	}
	while(!pq.empty() && nums.size() && pq.top().first < nums[0].first) nums.pop_back();
	while (!pq.empty() && nums.size()) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i].first > pq.top().first) {	
				break;
			}
			else if (nums[i].second.first < pq.top().second &&
				heights[nums[i].second.second.first] < pq.top().first) {
				ans[nums[i].second.second.second] = ans[nums[i].second.second.second] == -1 ? pq.top().second : min(ans[nums[i].second.second.second],pq.top().second);
			}
		}
		pq.pop();
	}

	return ans;
}
};