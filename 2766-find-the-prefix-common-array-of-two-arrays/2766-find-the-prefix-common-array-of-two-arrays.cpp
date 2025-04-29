class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
	vector<int>ans(A.size(), 0), mp(A.size() + 1, 0);
	for(int i=0;i<A.size();i++)
	{
		mp[A[i]]++;
		if (mp[A[i]] == 2)
			ans[i]++;

		mp[B[i]]++;
		if(mp[B[i]]==2)
			ans[i]++;

		ans[i] += i == 0 ? 0 : ans[i - 1];
	}

	return ans;
}
};