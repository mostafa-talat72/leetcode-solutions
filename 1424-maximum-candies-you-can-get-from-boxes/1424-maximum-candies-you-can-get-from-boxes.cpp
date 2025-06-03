class Solution {
public:
     int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
               vector<vector<int>>& containedBoxes, vector<int>& initialBoxes)
{
	 int n = status.size();
    vector<pair<bool, bool>> vis(n, {0, 0});
     int ans = 0;
    queue<int> q;
	for (int i = 0; i < initialBoxes.size(); i++) {
		q.push(initialBoxes[i]);
	}
	while (!q.empty()) {
		int box = q.front();
		q.pop();
        vis[box].first = true;
		if (status[box] == 1) {
            if (vis[box].second)
                continue;
			ans += candies[box];
            vis[box].second = true;
			for (int key : keys[box]) {
                if (vis[key].first && !vis[key].second)
                {
                    q.push(key);
				}
                status[key] = true;
			}
			for (int nextBox : containedBoxes[box]) {
				if (!vis[nextBox].first) {
					q.push(nextBox);
				}
			}
		}
	}

    return ans;
}
};