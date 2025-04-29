class Solution {
public:
    int minimizeXor(int num1, int num2) {
	bitset<33> b2(num2);
	int  numOnes = 0;
	bitset<33> b1(num1);
	bitset<33> ans = 0;
	
	for(int i = 0; i < 33; i++) {
		if(b2[i]==1)numOnes++;
	}
	for(int i=32;i>=0 && numOnes;i--)
	{
		if(b1[i]==1) {
			ans[i] = 1;
			numOnes--;
		}
	}
	
	for(int i=0;i<33 && numOnes;i++)
	{
		if(ans[i]==0)
		{
			ans[i] = 1;
			numOnes--;
		}
	}
	return ans.to_ulong();
}
};