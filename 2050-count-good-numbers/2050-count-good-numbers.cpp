class Solution {
public:
    long long power(long long base, long long exponent, long long mod) {
	base %= mod;
	long long result = 1;

	while (exponent > 0) {
		if (exponent & 1)  // if exponent is odd
			result = (result * base) % mod;

		base = (base * base) % mod;
		exponent >>= 1;  // exponent = exponent / 2
	}

	return result;
}
int countGoodNumbers(long long n) {
	int mod = 1e9 + 7;
	long long odd = n / 2;
	long long even = n - odd;
	long long ans = 1;
	odd = odd % (mod - 1);
	even = even % (mod - 1);
	odd = (long long)power(4, odd, mod);
	even = (long long)power(5, even, mod);
	ans = ((odd % mod) * (even) % mod) % mod;
	return ans;
}
};