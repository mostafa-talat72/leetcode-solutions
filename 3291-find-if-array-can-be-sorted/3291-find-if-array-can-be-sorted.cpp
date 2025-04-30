class Solution {
public:
    bool canSortArray(vector<int>& nums) {
	vector<pair<int,int>> range;
	
	int start = 0, end = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (bitset<32>(nums[i]).count() != bitset<32>(nums[i - 1]).count()) {
			end = i - 1;
			range.push_back({ start, end });
			start = i;
		}
	}
	end = nums.size() - 1;
	range.push_back({ start, end });
	for(auto it : range) {
		sort(nums.begin() + it.first, nums.begin() + it.second + 1);
	}
	for (int i = 1; i < range.size(); i++) {
		if(nums[range[i].first] < nums[range[i - 1].second]) return false;
	}
	return true;
}
};