int dr[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dc[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
class Solution {
public:
   int vis[51][51];
int minTimeToReach(vector<vector<int>>& moveTime)
{ 
	int n = moveTime.size(), m = moveTime[0].size();
    memset(vis, 0, sizeof(vis));
    priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    vis[0][0] = 1;
    int ans = 2e9;
    while (pq.size())
    {
        auto top = pq.top();
        pq.pop();
        int time = top.first;
        int i = top.second.first;
        int j = top.second.second;
        if (i == n - 1 && j == m - 1)
            ans = min(ans, time);
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dr[k];
            int nj = j + dc[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m)
            {
                int newTime = time >= moveTime[ni][nj] ? time + 1 : moveTime[ni][nj] + 1;
                if (!vis[ni][nj] || newTime < vis[ni][nj])
                {
                    vis[ni][nj] = newTime;
                    pq.push({newTime, {ni, nj}});
                }
            }
		}

	}
    return ans;

}
};