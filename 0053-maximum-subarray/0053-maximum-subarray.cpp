class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	priority_queue<int>pq;

	int ans = nums[0], sum = nums[0];
	pq.push(-nums[0]);
	for (int i = 1; i < nums.size(); i++) {
		sum += nums[i];
		while (pq.size() && sum < -pq.top()) {
			ans = max({ ans,sum  , sum + pq.top() });
			pq.pop();
		}
		ans = max({ ans,sum  , sum + (pq.size() ? pq.top() : 0) });
		pq.push(-sum);
	}
	return ans;
}
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();