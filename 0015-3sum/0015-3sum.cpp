class Solution {
public:
void removeDuplicates(vector<int>& vec) {
	sort(vec.begin(), vec.end());

	auto last = unique(vec.begin(), vec.end());

	vec.erase(last, vec.end());
}
   vector<vector<int>> threeSum(vector<int>& nums) {
	set<vector<int>>calc;
	sort(nums.begin(), nums.end());
	unordered_map<int, int>mp;

	for(int i = 0; i < nums.size(); i++) {
		mp[nums[i]]++;
	}
	removeDuplicates(nums);

	for (int i = 0; i < nums.size(); i++) {
		
		mp[nums[i]]--;
		for (int j = nums.size() - 1; j >= i; j--) {
			if(mp[nums[j]] == 0)continue;
			mp[nums[j]]--;
			if (mp.find(-1 * (nums[i] + nums[j])) != mp.end() && mp[-1 * (nums[i] + nums[j])]) {
				cout << nums[i] << " " << nums[j] << " " << -1 * (nums[i] + nums[j]) << endl;
				vector<int>temp;
				temp.push_back(nums[i]);
				temp.push_back(nums[j]);
				temp.push_back(-1 * (nums[i] + nums[j]));
				sort(temp.begin(), temp.end());
				calc.insert(temp);
			}
			mp[nums[j]]++;
		}
		mp[nums[i]]++;
	}
	return vector<vector<int>>(calc.begin(), calc.end());
}
};