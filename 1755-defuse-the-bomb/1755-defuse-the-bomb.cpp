class Solution {
public:
   vector<int> decrypt(vector<int>& code, int k) {
	vector<int> ans(code.size(), 0);
	int n = code.size(), sum = 0;
	for(int i = 1; i < n; i++){
		code[i] += code[i - 1];
	}

	if (k != 0)
	{

		for (int i = 0; i < n; i++) {
			if (k > 0) {
				if (i + k < n)
				{
					ans[i] = code[i + k] - code[i];
				}
				else
				{
					ans[i] = code[n - 1] - code[i];
					ans[i] += code[k + i - n];
				}
			}else{
				if (i + k >= 0)
				{
					ans[i] = code[i - 1] - (i + k - 1 >= 0 ? code[i + k - 1] : 0);
				}
				else
				{
					ans[i] = (i - 1 >= 0 ? code[i - 1] : 0);
					ans[i] += code[n - 1] - code[n + (i + k) - 1];
				}
			}
		}
	}
	return ans;
}
};