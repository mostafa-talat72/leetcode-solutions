class Solution {
public:
    string decodeString(string s) {
	string  ans = "", num = "", str = "", tst = "";

	stack<pair<int, string>>st;
	int brack = 0;
	for (auto i : s)
	{
		if (i >= '0' && i <= '9')
		{
			num += i;
			if (!str.empty()) {
				int cnt = st.top().first;
				tst = "";
				if (cnt == 1) {
					while (cnt--)
					{
						tst += str;
					}
					st.pop();
					if (!st.empty())
					{
						st.top().second += tst;
					}
					else {
						ans += tst;
					}
				}
				else st.top().second += str;
				str.clear();

			}
		}
		else if (i == '[')
		{
			brack++;
			st.push({ stoi(num), "" });
			num.clear();
		}
		else if (i == ']')
		{
			int cnt = st.top().first;
			tst = "";
			if (str.empty()) str = st.top().second;
			while (cnt--)
			{
				tst += str;
			}
			st.pop();
			str.clear();
			brack--;
			if (!st.empty())
			{
				st.top().second += tst;
				if (st.size() == 1 && !brack)
				{
					cnt = st.top().first;
					str = st.top().second;
					while (cnt--)
					{
						ans += str;
					}
					st.pop();
					str.clear();
				}
			}
			else {
				ans += tst;
			}

		}
		else
		{
			str += i;
			if (st.empty() || (num.empty() && !st.empty() && !st.top().second.empty())) {
				st.push({ 1, "" });
			}
		}
	}

	if (!str.empty())
	{
		st.push({ 1,str });
	}
	tst = "";
	while (!st.empty())
	{
		int cnt = st.top().first;
		while (cnt--)
		{
			ans += st.top().second;
		}
		st.pop();
	}
	return ans;
}
};