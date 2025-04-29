class Solution {
public:
    bool ok(int punNum, int num,int sum) {
	if (!punNum)
		return sum == num;
	bool res = 0;
	for (int i = 10;; i *= 10) {
		
		res |= ok(punNum / i, num, sum + (punNum % i));
		if (punNum < i)
			break;
	}
	return res;
}

int punishmentNumber(int n) {
	int ans = 1;
	for (int i = 2; i <= n; i++) 		{
		ans += ok(i * i, i, 0) ? i * i : 0;
	}
	return ans;
}
};