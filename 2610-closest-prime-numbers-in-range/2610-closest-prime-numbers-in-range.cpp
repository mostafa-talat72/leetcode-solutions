class Solution {
public:
    int N = 1e6 + 1;
bool prime[1000001];
vector<int>primesNum;
void  sieve_v2(int left, int right) {
	memset(prime, 1, sizeof prime);
	prime[0] = prime[1] = 0;
	for (int i = 4; i <= right; i += 2) {
		prime[i] = 0;
	}
	for (int i = 3; i * i <= right; i += 2) {
		if (prime[i]) {
			for (int j = i * i; j <= right; j += i + i) {
				prime[j] = 0;
			}
		}
	}
	for (int i = left; i <= right; i++)
		if (prime[i])
			primesNum.push_back(i);
}
vector<int> closestPrimes(int left, int right) {
	sieve_v2(left, right);
	int mnDiff = INT_MAX, a = -1, b = -1;
	for (int i = 0; i < primesNum.size(); i++) {
		if (i + 1 < primesNum.size() && primesNum[i + 1] - primesNum[i] < mnDiff) {
			mnDiff = primesNum[i + 1] - primesNum[i];
			a = primesNum[i];
			b = primesNum[i + 1];
		}
	}
	return { a, b };

}
};