class Solution {
public:
long long minEnd(int n, int x) {
	if (n == 1) return x;
    n--;	bitset<45> num(x);
	for (int i = 0, j = 0; i < 45 && j < 45; i++) {
		if (num[i] == 0)
		{
			num[i] = (n & (1LL << j));
			j++;
		}
	}
	return num.to_ullong();
}
};