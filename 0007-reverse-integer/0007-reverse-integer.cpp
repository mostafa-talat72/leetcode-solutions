class Solution {
public:
   
int reverse(int x) {
	
	bool ok = 0;
	long long temp = x;
	if(x<0){
		ok = 1;
		temp *= -1;
	}
	
	long long res = 0;
	while (temp) {
		res *= 10;
		res += temp % 10;
		temp /= 10;
	}
	
	if (ok){
		res *= -1;
	}
	
	return (res > INT_MAX || res < INT_MIN)		? 0 : res;
}
};