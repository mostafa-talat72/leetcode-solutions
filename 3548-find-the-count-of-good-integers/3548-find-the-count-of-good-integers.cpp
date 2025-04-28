class Solution {
public:
   unordered_set<string>mp;
int fact[11] = { 1 };
long long calc(string num, int n, int k) {
	long long s = stoll(num);
	sort(num.begin(), num.end());
	if (s % k != 0 || mp.count(num))return 0;
	mp.insert(num);
	vector<int>frq(10);
	for (auto it : num) frq[it - '0']++;
	long long ret = (n - frq[0]) * fact[n - 1];
	for (int i = 0;i < 10;i++)
		ret /= fact[frq[i]];
	return ret;

}

long long solve(int i, string num, int n, int k) {
	if (i * 2 >= n + 1)
		return calc(num, n, k);
	long long ret = 0;
	for (int j = 0;j < 10;j++) {
		if (!i && !j)continue;
		num[i] = num[n - i - 1] = j + '0';
		ret += solve(i + 1, num, n, k);
	}
	return ret;
}

long long countGoodIntegers(int n, int k) {
	fact[0] = fact[1] = 1;
	for (int i = 2;i <= 10;i++)
		fact[i] = fact[i - 1] * i;
	string num = string(n, ' ');
	return solve(0, num, n, k);
}
};