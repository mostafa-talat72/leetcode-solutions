class Solution {
public:
   long long continuousSubarrays(vector<int>& nums) {
	set<pair<int,int>>st;
	int l = 0, r = 0;
	long long ans = 0;
	while (l <= r && r < nums.size()) {
		st.insert({ nums[r] ,r });
		auto it = st.end();
		it--;
		if(it->first - st.begin()->first <= 2)
			r++;
		else
		{
			ans += (r - l);
			st.erase({ nums[l] ,l });
			l++;
		}
	}
	if(st.size()) {
		ans += (st.size() * (st.size() + 1)) / 2;
	}
	return ans;
}
};