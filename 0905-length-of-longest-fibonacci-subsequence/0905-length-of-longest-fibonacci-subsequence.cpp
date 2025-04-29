class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
	int ans = 0, n = arr.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int a = arr[i], b = arr[j], c = a + b;
			int len = 2;
			while (binary_search(arr.begin(), arr.end(), c)) {
				a = b;
				b = c;
				c = a + b;
				len++;
			}
			ans = max(ans, len > 2 ? len : 0);
		}
	}
	return ans;
}
};