class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
	int sum = 0, odd = 0, even = 0, ans = 0, mod = 1e9 + 7;
	for (auto it : arr) {
		sum += it;
		if (sum & 1)
			ans++,ans += even, odd++;
		else
			ans += odd, even++;
		if (ans >= mod)
			ans -= mod;
	}
	return ans;
}
};