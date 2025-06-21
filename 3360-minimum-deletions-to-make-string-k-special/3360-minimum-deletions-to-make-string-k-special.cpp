class Solution {
public:
   
int minimumDeletions(string word, int k) {
	
	vector<int> fr(26, 0);
    for (auto it : word)
        fr[it - 'a']++;
    int ans = INT_MAX;
    sort(fr.begin(), fr.end());
    int idx = upper_bound(fr.begin(), fr.end(), 0) - fr.begin();
    int cnt = 0;
    for (int i=idx; i<26; i++) {
        int mx = fr[i] + k;
        int temp = 0;
        for (int j=i+1; j<26; j++) {
			if (fr[j] > mx) {
				temp += fr[j] - mx;
			}
        }
        ans = min(ans, temp + cnt);
        cnt += fr[i];
    }
    return ans;
  }
};