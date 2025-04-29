class Solution {
public:
   long long coloredCells(int n) {
	long long nn = n * 2 - 1;
	return nn + (((nn - 1) / 2) * (nn * 2)) - (((nn - 1) / 2) * (2 + (nn - 1)));
}
};