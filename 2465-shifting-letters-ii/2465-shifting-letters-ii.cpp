class Solution {
public:
   string shiftingLetters(string s, vector<vector<int>>& shifts) {

	vector<int> v(s.size() + 1);
	for(auto& shift : shifts)
	{
		if(shift[2])
		{
			v[shift[0]]++;
			v[shift[1] + 1]--;
		}
		else
		{
			v[shift[0]]--;
			v[shift[1] + 1]++;
		}
	}
	for(int i = 1; i < v.size(); i++)
	{
		v[i] += v[i - 1];
	}
	for(int i = 0; i < s.size(); i++)
	{
		int a = s[i] - 'a';
		int b = (v[i] + a) % 26;
		b = (b + 26) % 26;
		s[i] = 'a' + b;
	}
	return s;

}
};