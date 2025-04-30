class Solution {
public:
    
void dfs(int i, vector<vector<int>>& adj, vector<int>& visited) {
	visited[i] = 1;
	for(auto j : adj[i]) {
		if (!visited[j]) {
			dfs(j, adj, visited);
		}
		else
			visited[j]++;
	}

}

int findChampion(int n, vector<vector<int>>& edges) {
	vector<vector<int>>adj(n + 1);
	for(auto it : edges) {
		adj[it[0]].push_back(it[1]);
	}
	vector<int>visited(n + 1, 0);
	for (int i = 0; i < n; i++) {
		if(!visited[i])
			dfs(i, adj, visited);
		else
			visited[i]++;
	}
	int ans = -1, cnt = 0;
	for(int i = 0; i < n; i++) {
		if(visited[i] ==1)
		{
			cnt++;
			ans = i;
		}
	}
	return cnt == 1 ? ans : -1;
}
};