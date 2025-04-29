class Solution {
public:
   int dfs(int node, vector<vector<int>>& graph, vector<bool>& vis,vector<int>&isSave) {
	vis[node] = 1;
	int ans = 1;
	for (auto it : graph[node]) {
		if (!vis[it]) {
			isSave[it] = dfs(it, graph, vis, isSave);
			if (isSave[it] == 1 && ans != -1) {
				ans = 1;
			}
			else if (isSave[it] == -1) {
				ans = -1;
			}
		}
		else if(isSave[it]==-1 || isSave[it]==0){
			ans = -1;
			isSave[it] = -1;
		}
	}
	return ans;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	vector<int>ans, isSave(graph.size(), 0);
	vector<bool>vis(graph.size(), 0);

	for (int i = 0; i < graph.size(); i++) {
		if (graph[i].size() == 0) {
			isSave[i] = 1;
		}
	}

	for (int i = 0; i < graph.size(); i++) {
		if (!vis[i]) {
			isSave[i] = dfs(i, graph, vis, isSave);
		}
	}
	for (int i = 0; i < graph.size(); i++) {
		if (isSave[i] == 1) {
			ans.push_back(i);
		}
	}
	return ans;
}
};