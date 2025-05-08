
int dr[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dc[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
class Solution {
public:
 int vis[751][751];
int minTimeToReach(vector<vector<int>>& moveTime)
{ 
	int n = moveTime.size(), m = moveTime[0].size();
    memset(vis, 0, sizeof(vis));
    priority_queue < pair<int, pair<int, pair<int,int>>>> pq;
    pq.push({0, {0, {0, 1}}});
    vis[0][0] = 1;
    int ans = 2e9;
    while (pq.size())
    {
        auto top = pq.top();
        pq.pop();
        int time = -top.first;
        int i = top.second.first;
        int j = top.second.second.first;
        int add = top.second.second.second;
        if (!(i == 0 && j == 0) && time > vis[i][j])
            continue;
        if (i == n - 1 && j == m - 1)
            return time;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dr[k];
            int nj = j + dc[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m)
            {
                int newTime = time >= moveTime[ni][nj] ? time + add : moveTime[ni][nj] + add;
                
                if (!vis[ni][nj] || newTime < vis[ni][nj])
                {
                    vis[ni][nj] = newTime;
                    pq.push({-newTime, {ni, {nj, add == 1? add + 1: add - 1}}});
                }
            }
		}

	}
    return ans;
}
};
