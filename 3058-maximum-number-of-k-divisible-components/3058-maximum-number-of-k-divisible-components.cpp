class Solution {
public:
   long long dfs(int x,int k, vector<int>& values,vector<vector<int>>& adj,int& ans,vector<int>& vis) {
	vis[x] = 1;
	long long sum = values[x];
	for (int y : adj[x]) {
		if (vis[y] == 0) {
			sum += dfs(y, k, values, adj, ans, vis);
		}
	}
	if (sum % k == 0){
		ans++;
	}
	return sum;
}

int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
	vector<vector<int>> adj(n);

	for (auto it : edges) {
		adj[it[0]].push_back(it[1]);
		adj[it[1]].push_back(it[0]);
	}

	vector<int> vis(n, 0);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i] == 0) {
			dfs(i, k, values, adj, ans, vis);
		}
	}
	return ans;
}
};