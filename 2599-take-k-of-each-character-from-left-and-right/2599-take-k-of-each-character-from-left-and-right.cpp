class Solution {
public:
   int takeCharacters(string s, int k) {
	vector<pair<int, pair<int, int>>>mp(s.size(), { 0,{0,0} });
	for (int i = 0; i < s.size(); i++) {
		if (i == 0) {
			mp[i] = { s[i] == 'a' ? 1 : 0,{s[i] == 'b' ? 1 : 0,s[i] == 'c' ? 1 : 0} };
		}
		else {
			if(s[i] == 'a'){
				mp[i] = { mp[i - 1].first + 1,{mp[i - 1].second.first,mp[i - 1].second.second} };
			} else if(s[i] == 'b'){
				mp[i] = { mp[i - 1].first,{mp[i - 1].second.first + 1,mp[i - 1].second.second} };
			}else
			{
				mp[i] = { mp[i - 1].first,{mp[i - 1].second.first,mp[i - 1].second.second + 1} };
			}
		}
	}
	if (!k)return 0;
	else if (mp[s.size() - 1].first < k ||
		mp[s.size() - 1].second.first < k ||
		mp[s.size() - 1].second.second < k) return -1;
	int l = 1, r = s.size(), mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		bool ok = 0;
		if (mp[mid - 1].first >= k &&
			mp[mid - 1].second.first >= k &&
			mp[mid - 1].second.second >= k) ok = 1;
		else if(mp[s.size() - 1].first - ((mp.size() - mid - 1 >= 0 && mp.size() - mid - 1 < s.size() )? mp[s.size() -mid - 1].first : 0 ) >= k &&
			mp[s.size() - 1].second.first - ((mp.size() - mid - 1 >= 0 && mp.size() - mid - 1 < s.size()) ? mp[s.size() - mid - 1].second.first : 0) >= k &&
			mp[s.size() - 1].second.second - ((mp.size() - mid - 1 >= 0 && mp.size() - mid - 1 < s.size()) ? mp[s.size() - mid - 1].second.second : 0) >= k) ok = 1;
			
		else {

			for (int i = 1; i < mid; i++) {
				if (mp[i-1].first + mp[s.size()-1].first - mp[s.size()-(mid- i)-1].first>=k && 
					mp[i-1].second.first + mp[s.size()-1].second.first - mp[s.size() - (mid - i) - 1].second.first>=k &&
					mp[i-1].second.second + mp[s.size() - 1].second.second - mp[s.size() - (mid - i) - 1].second.second >= k){
					ok = 1;
					break;
				}
			}
		}
		if (ok) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return ans;
}
};