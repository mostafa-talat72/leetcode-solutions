class Solution {
public:
int shortestSubarray(vector<int>& nums, int k) {
	deque<pair<long long, int>> pq;
	long long sum = 0;
	int ans = 1e9;
	
	for (int r = 0; r < nums.size(); r++) {
		sum += nums[r];
		if(sum >= k) {
			ans = min(ans, r + 1);
		}
		while(pq.size() && sum - pq.front().first  >= k){
			ans = min(ans, r - pq.front().second );
			pq.pop_front();
		}

		while(pq.size() && sum <= pq.back().first){
			pq.pop_back();
		}
		pq.push_back({ sum, r });
	}
	return ans == 1e9 ? -1 : ans;
}
};