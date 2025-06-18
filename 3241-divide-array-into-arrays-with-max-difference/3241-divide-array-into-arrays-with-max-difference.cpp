class Solution {
public:
   vector<vector<int>> divideArray(vector<int>& nums, int k){
	sort(nums.begin(), nums.end());
    vector<vector<int>> ans(nums.size() / 3);
	for (int i = 0,idx = 0; i < nums.size(); i+=3, idx++) {
        if (nums[i+2] - nums[i] > k) {
            return {};
        }
		
		for (int j=0;j<3;j++) {
            ans[idx].push_back(nums[i + j]);   
        }
    }
    return ans;
}
};