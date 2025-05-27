class Solution {
public:
    int differenceOfSums(int n, int m) { 
	
	int sum1 = 0, sum2 = 0;
    for (int i=m; i <= n; i+=m) {
		sum2 += i;
    }
    sum1 = (n * (n + 1)) / 2; 
	sum1 -= sum2; 
	return sum1 - sum2;
}
};