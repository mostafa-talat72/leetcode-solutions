class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, vector<int>>mp;
	for (int i = 0; i < nums.size(); i++) {
		mp[nums[i]].push_back(i);
	}
	for (auto it : mp) {
		if (target - it.first == it.first && it.second.size() > 1) {
			return { it.second[0], it.second[1] };
		}
		else if (target - it.first != it.first && mp.find(target - it.first) != mp.end()) {
			return { it.second[0], mp[target - it.first][0] };
		}
	}
    return {};
}
};