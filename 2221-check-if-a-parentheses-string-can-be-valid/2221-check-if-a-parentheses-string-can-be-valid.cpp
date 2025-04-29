class Solution {
public:
   bool canBeValid(string s, string locked) {
	vector<int> open, magic;
	for (int i = 0; i < s.size(); i++) {
		if (locked[i] == '0') magic.push_back(i);
		else if (s[i] == '(') open.push_back(i);
		else {
			if (open.size())open.pop_back();
			else if (magic.size())magic.pop_back();
			else return false;
		}
	}
	while(open.size() && magic.size() && open.back() < magic.back()) {
		open.pop_back();
		magic.pop_back();
	}
	return !open.size() && !(magic.size() & 1);
}
};