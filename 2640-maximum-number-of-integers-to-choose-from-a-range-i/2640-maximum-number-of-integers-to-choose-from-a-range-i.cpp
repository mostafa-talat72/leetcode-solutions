class Solution {
public:
    
int maxCount(vector<int>& banned, int n, int maxSum) {
	int sum = 0, cnt = 0;
	vector<int>nums(n + 1, 0);
	for(int i = 0; i < banned.size(); i++){
		if(banned[i] > n) continue;
		nums[banned[i]] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if(nums[i]) continue;
		sum += i;
		cnt++;
		if(sum > maxSum) 
		{
			cnt--;
			sum -= i;
		}
	}
	return cnt;
}
};