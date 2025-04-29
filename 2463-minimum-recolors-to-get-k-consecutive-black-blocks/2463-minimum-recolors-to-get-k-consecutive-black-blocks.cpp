class Solution {
public:
    int minimumRecolors(string blocks, int k) {
	int l = 0, r = 0, cnt = 0, res = 101;
	while (l <= r && r < blocks.size()) {
		if (r - l + 1 > k) {
			if (blocks[l] == 'W') {
				cnt--;
			}
			l++;
		}
		else {
			if (blocks[r] == 'W') {
				cnt++;
			}
			if (r - l + 1 == k) {
				res = min(res, cnt);
				if (res == 0)
					return 0;
			}
			r++;
		}
	}
	res = min(res, cnt);
	return res;
}
};