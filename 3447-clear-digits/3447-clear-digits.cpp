class Solution {
public:
    string clearDigits(string s) {
	vector<int>q;
	string ans = "";

	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			s[q.back()] = '#';
			s[i] = '#';
			q.pop_back();
		}
		else {
			q.push_back(i);
		}
	}

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '#') {
			ans += s[i];
		}
	}
	return ans;
}
};