class Solution {
public:
    int bfs(int n, vector<vector<int>>& edges) {
	vector<int> visited(n + 1);
	queue<pair<int,int>> q;
	q.push({ 0,0 });
	while(q.size()){
		auto p = q.front();
		q.pop();
		if(p.first == n - 1) return p.second;
		for (int i = 0; i < edges[p.first].size(); i++) {
			if (!visited[edges[p.first][i]]) {
				visited[edges[p.first][i]] = 1;
				q.push({ edges[p.first][i],p.second + 1 });
			}
		}
	}
	return -1;
}
vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
	vector<vector<int>> adj(n + 1);
	vector<int> res(queries.size());
	for(int i = 0; i < n; i++) {
		adj[i].push_back(i + 1);
	}
	for (int i = 0; i < queries.size(); i++) {
		int u = queries[i][0], v = queries[i][1];
		adj[u].push_back(v);
		res[i] = bfs(n, adj);
	}
	return res;
}
};