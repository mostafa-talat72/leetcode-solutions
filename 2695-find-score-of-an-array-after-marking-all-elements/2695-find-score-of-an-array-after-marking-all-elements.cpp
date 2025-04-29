class Solution {
public:
  long long findScore(vector<int>& nums) {
	vector<pair<int,int>>dq;
	vector<bool>vist(nums.size(), 0);
	for (int i = 0; i < nums.size(); i++) {
		dq.push_back({ nums[i],i });
	}
	sort(dq.begin(), dq.end());
	long long ans = 0;
	for(int i=0;i<dq.size();i++){
		auto it = dq[i];
		if(vist[it.second])
			continue;
		ans += it.first;
		vist[it.second] = 1;
		if(it.second+1<nums.size() ){
			vist[it.second + 1] = 1;
		}
		if(it.second-1>=0){
			vist[it.second - 1] = 1;
		}
	}

	return ans;
}
};