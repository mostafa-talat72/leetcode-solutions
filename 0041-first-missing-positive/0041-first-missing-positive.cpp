class Solution {
public:
    
void removeDuplicates(vector<int>& vec) {
	sort(vec.begin(), vec.end());

	auto last = unique(vec.begin(), vec.end());

	vec.erase(last, vec.end());
}
int firstMissingPositive(vector<int>& nums) {
	removeDuplicates(nums);
	int ans = 1;
	for(int i = 0; i < nums.size(); i++){
		if (nums[i] > 0 && nums[i] != ans) {
			return ans;
		}
		else if (nums[i] == ans)
			ans++;
	}
	return ans;
}
};