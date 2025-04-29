class Solution {
public:
   
bool dfs(int i, int col,vector<vector<int>>& adj,vector<int>&color,vector<int>&v){
	color[i] = col;
	v.push_back(i);
	for (auto it : adj[i]) {
		 if (color[it] == color[i] || (color[it] == -1 && !dfs(it, 1 - col, adj, color, v))) {
			 return false;
		}
	}
	return true;
}
int bfs(int i, vector<vector<int>>& adj,vector<int>&v) {
	int ans = 1;
	for (auto it : v) {
		vector<bool>vis(adj.size(), 0);
		queue<pair<int, int>>q;
		q.push({ it,1 });
		vis[it] = 1;
		while (!q.empty()) {
			auto it = q.front();
			ans = max(ans, it.second);
			q.pop();
			for (auto it1 : adj[it.first]) {
				if (!vis[it1]) {
					q.push({ it1,it.second + 1 });
					vis[it1] = 1;
				}
			}
		}
	}
	return ans;
}
int magnificentSets(int n, vector<vector<int>>& edges) {
	vector<int>color(n + 1, -1);
	vector<vector<int>>adj(n + 1);

	for (auto it : edges) {
		adj[it[0]].push_back(it[1]);
		adj[it[1]].push_back(it[0]);
	}

	int ans = 0;
	for (int i = 1; i <= n ; i++) {
		if(color[i]!=-1)continue;
		vector<int>v;
		if (!dfs(i, 0, adj, color, v)) return -1;
		ans += bfs(i, adj,v);

	}
	return ans;
}
};