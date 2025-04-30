class Solution {
public:
   
bool is_sorted(vector<int>::iterator start, vector<int>::iterator end) {
	while (start + 1 != end) {
		if (*start + 1 != *(start + 1)) return false;
		start++;
	}
	return true;
}

vector<int> resultsArray(vector<int>& nums, int k) {

	int i = 0;
	vector<int> results(nums.size() - k + 1, -1);

	while (i + k - 1 < nums.size()) {
		if (is_sorted(nums.begin() + i, nums.begin() + i + k)) {
			results[i] = nums[i + k - 1];
		}
		i++;
	}
	return results;
}
};