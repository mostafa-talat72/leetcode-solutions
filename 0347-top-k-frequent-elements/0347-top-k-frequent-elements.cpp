class Solution {
public:
   vector<int> topKFrequent(vector<int>& nums, int k) {
	vector<int>ret;
	unordered_map<int, int>mp;
	for (int i = 0; i < nums.size(); i++) {
		mp[nums[i]]++;
	}

	priority_queue<pair<int, int>>pq;
	for (auto it : mp) {
		pq.push({ it.second, it.first });
	}
	while (!pq.empty()) {
		ret.push_back(pq.top().second);
		if (ret.size() == k)break;
		pq.pop();
	}
	return ret;
}
};