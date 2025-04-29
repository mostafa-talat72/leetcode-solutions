class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int r = 0, last = 0, ans = 0, n = colors.size(), cnt = 1,k=3;
while (r<n+k-1) {
	if (colors[r>=n?r-n:r] == colors[last>=n ? last-n:last]) {
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