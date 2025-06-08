bool compare(int a,int b)
{ 
	return to_string(a) < to_string(b);
}
class Solution {
public:
   

vector<int> lexicalOrder(int n) { 
	
	vector<int> ans(n); 
	for (int i = 0; i < n; i++)
    {
        ans[i] = i + 1;
    }
    sort(ans.begin(), ans.end(), compare);
    return ans;
}
};