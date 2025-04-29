class Solution {
public:
   int numberOfAlternatingGroups(vector<int>& colors, int k) {
	int r = 0, last = 0, ans = 0, n = colors.size(), cnt = 1;
	while (r<n+k-1) {
		if (colors[r%n] == colors[last%n] && r != 0) {
			cnt = 1;
		}
		
		if (cnt>=k) {
			ans++;
		}
		cnt++;
		last = r;
		r++;

	}
	return ans;
}
};