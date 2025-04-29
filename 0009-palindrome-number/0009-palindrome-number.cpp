class Solution {
public:
   bool isPalindrome(int x) {
	if(x < 0) return false;
	long long rev = 0,tst=x;
	while(x){
		rev = rev * 10 + x % 10;
		x /= 10;
	}
	return rev==tst;
}
};