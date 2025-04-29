class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
	priority_queue<long long>pq;
	for (auto it : nums) {
		pq.push(-it);
	}
	int ans = 0;
	while (pq.size() >= 2 && -pq.top() < k) {
		long long num1 = -pq.top(); pq.pop();
		long long num2 = -pq.top(); pq.pop();
		long long added_num = min(num1, num2) * 2 + max(num1, num2);
		pq.push(-added_num);
		ans++;
	}
	return ans;
}
};