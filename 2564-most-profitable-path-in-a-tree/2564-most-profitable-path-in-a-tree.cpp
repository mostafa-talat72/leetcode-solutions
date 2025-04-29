class Solution {
public:
   
bool dfsBob(int i,int cnt, vector<vector<int>>& adj, vector<int>& vis) {
	if (i == 0)
		return true;
	vis[i] = cnt;
	bool res = 0;
	for (int j = 0; j < adj[i].size() && !res; j++) {
		if (vis[adj[i][j]]==INT_MAX) {
			res = dfsBob(adj[i][j],cnt+1, adj, vis);
			if(!res)
			{
				vis[adj[i][j]] = INT_MAX - 1;
			}
		}
	}
	return res;
}

int alicBfs(int s, vector<vector<int>>& adj, vector<int>& amount, vector<int>& bobVis) {
	queue<pair<int, pair<int,int>>>q;
	vector<int>vis(amount.size(), 0);
	q.push({ s,{1,amount[s]} });
	int ans = INT_MIN;
	vis[s] = 1;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		if (adj[it.first].size() == 1 && it.first != 0)
			ans = max(ans, it.second.second);
		for (int i = 0; i < adj[it.first].size(); i++) {
			if (!vis[adj[it.first][i]]) {
				int cost = it.second.second;
				if (bobVis[adj[it.first][i]] > it.second.first + 1) {
					cost += amount[adj[it.first][i]];
				}
				else if (bobVis[adj[it.first][i]] == it.second.first + 1) {
					cost += amount[adj[it.first][i]] / 2;
				}
				q.push({ adj[it.first][i],{it.second.first + 1,cost} });
				vis[adj[it.first][i]] = 1;
			}
		}
	}
	return ans;
}


int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
	vector<vector<int>>adj(amount.size(), vector<int>());
	for (int i = 0; i < edges.size(); i++) {
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}

	vector<int>bobVis(amount.size(), INT_MAX);
	dfsBob(bob,1, adj, bobVis);
	return alicBfs(0, adj, amount, bobVis);
}
};