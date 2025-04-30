class Solution {
public:
   bool checkPrime(int n) {
	if (n <= 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}

bool primeSubOperation(vector<int>& nums) {
	vector<int>primes;

	for (int i = 2; i < 1000; i++) {
		if (checkPrime(i))primes.push_back(i);
	}
	int j = 1;

	for (int i = 0; i < nums.size(); i++) {
		int it = nums[i];
		if (j >= it) {
			if (i != 0 && nums[i] <= nums[i - 1])return false;
			j = it + 1;
			continue;
		}
		int diff = it - j;
		int idx = lower_bound(primes.begin(), primes.end(), diff) - primes.begin();
		if (primes[idx] >= it) {
			idx--;
			if(idx<0 && i==0){
				j = it + 1;
				continue;
			}
			if ((idx < 0 ) || (i != 0 && it - primes[idx] <= nums[i - 1]))return false;
			it -= primes[idx];
			j = it + 1;
		}
		else {
			if ((i != 0 && it - primes[idx] <= nums[i - 1])) {

				idx--;
				if (idx < 0 && (i != 0 && it > nums[i - 1])){
					j = it + 1;
					continue;
				}
				if ((idx < 0) || (i != 0 && it - primes[idx] <= nums[i - 1]))
					return false;
			}
			it -= primes[idx];
			j = it + 1;
		}
		nums[i] = it;
	}
	return true;
}
};