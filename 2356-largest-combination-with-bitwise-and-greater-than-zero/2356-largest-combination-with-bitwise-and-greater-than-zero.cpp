class Solution {
public:
    int largestCombination(vector<int>& candidates) {
	vector<bitset<32>>tst;
	for (auto it : candidates) {
		tst.push_back(bitset<32>(it));
	}
	int ans = 0, sum = 0;
	for (int i = 0; i < 32; i++) {
		sum = 0;
		for(int j = 0; j < tst.size(); j++) {
			sum += tst[j][i];
		}
		ans = max(ans, sum);
	}
	return ans;
}
};