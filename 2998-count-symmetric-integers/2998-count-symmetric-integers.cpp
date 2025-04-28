class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
	int ans = 0;
	for (int i = low;i <= high;i++) {
		if (i > 9 && i < 100 && i % 10 == i / 10)ans++;
		else if (i > 999 && ((i / 1000) + ((i / 100) % 10)) == ((i / 10) % 10 + (i % 10)))//1234
			ans++;
	}
	return ans;
}
};