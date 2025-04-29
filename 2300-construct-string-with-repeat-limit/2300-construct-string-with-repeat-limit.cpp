class Solution {
public:
   string repeatLimitedString(string s, int repeatLimit) {
	int fr[26] = { 0 };

	for(auto it : s)
		fr[it - 'a']++;
	priority_queue<pair<char, int>>q;
	s.clear();
	for(int i = 0; i < 26; i++){
		if(!fr[i]) continue;
		q.push({ char(i + 'a'), fr[i] });
	}

	pair<char, int> prev = {'a', 0};
	while (!q.empty()) {
		
		auto it = q.top();
		int times = min({ it.second, repeatLimit , prev.second ? 1 : INT_MAX });
		q.pop();
		for(int i = 0; i < times; i++)
			s += it.first;
		if(prev.second > 0)
		{
			q.push(prev);
			prev = { it.first, it.second - times };
			if (prev.second > 0)
				q.push(prev);
			prev.second = 0;
		}
		else if (it.second - times > 0) {
			prev = { it.first, it.second - times };
		}


	}
	return s;
}
};