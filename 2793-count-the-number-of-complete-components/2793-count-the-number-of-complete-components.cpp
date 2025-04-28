class Solution {
public:
    void dfs(int i,int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>&nodes) {
	vis[i] = 1;
	nodes.push_back(i);
	bool ok = adj[i].size() == 0;
	for (int j : adj[i]) {
		if (!vis[j]) {
			dfs(j, i, adj, vis, nodes);
		}
	}
}

int countCompleteComponents(int n, vector<vector<int>>& edges) {

	vector<vector<int>> adj(n);
	for (auto& e : edges) {
		adj[e[0]].push_back(e[1]);
		adj[e[1]].push_back(e[0]);
	}
	vector<int> vis(n), isCycle(n);
	int ans = 0;
	vector<vector<int>> nodes;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vector<int> nodesChild;
			dfs(i,-1, adj, vis, nodesChild);
			nodes.push_back(nodesChild);
		}
	}
	for (auto& node : nodes) {
		bool ok = 1;
		for (int i : node) {
			if (adj[i].size() != node.size() - 1) {
				ok = 0;
				break;
			}
		}
		ans += ok;
	}
	return ans;
}
};