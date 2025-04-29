class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
	bitset<33>ans(0);
	int tst[33] = { 0 };
	for(int i=0;i<nums1.size();i++) {
		bitset<33>b(nums1[i]);
		
		for (int j = 0; j < 33; j++) {
			tst[j] += b[j]*nums2.size();
		}
	}
	for (int i = 0; i < nums2.size(); i++) {
		bitset<33>b(nums2[i]);
		for(int j=0;j<33;j++){
			tst[j] += b[j] * nums1.size();
		}
	}

	for (int i = 0; i < 33; i++) {
		if (tst[i] & 1)
			ans[i] = 1;
	}
	return ans.to_ulong();
}
};