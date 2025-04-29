class Solution {
public:
    
int maxProduct(vector<int>& nums) {
	int mx = -10, prod = 1;
	for (int i = 0; i < nums.size(); i++) {
		if(prod==0) prod = 1;
		prod *= nums[i];
		mx = max(mx, prod);
	}
     prod = 1;
	for(int i = nums.size() - 1; i >= 0; i--) {
		if(prod==0) prod = 1;
		prod *= nums[i];
		mx = max(mx, prod);
	}
	return mx;
}
};