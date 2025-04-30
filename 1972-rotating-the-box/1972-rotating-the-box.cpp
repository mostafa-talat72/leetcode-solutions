class Solution {
public:
   vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
	vector<vector<char>> ans(box[0].size(), vector<char>(box.size(), '.'));
	int r = box[0].size(), c = box.size();
	for (int i = c - 1; i >= 0; i--) {
		
		int lastI = r - 1;
		for (int j = r - 1; j >= 0; j--) {
			if(box[i][j] == '*')
			{
				ans[j][c - 1 - i] = '*';
				lastI = j - 1;
			}else if(box[i][j] == '#'){
				if(lastI != j){
					ans[lastI][c - 1 - i] = '#';
					
					lastI--;
				}else
				{
					ans[j][c - 1 - i] = '#';
					lastI = j - 1;
				}
			}
		}
	}

	return ans;
}
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();