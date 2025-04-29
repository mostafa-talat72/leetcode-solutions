class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& restack, int src) {
	vis[src] = true;
	restack[src] = true;
	for (auto it : adj[src]) {
		if (!vis[it]) {
			dfs(adj, vis, restack, it);
		}
		else if (restack[it]) {
			return;
		}
	}
	restack[src] = false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>>adj(numCourses);
	for(auto it:prerequisites){
		adj[it[0]].push_back(it[1]);
	}
	vector<bool>vis(numCourses, false), restack(numCourses,false);
	for (int i = 0; i < numCourses; i++) {
		if(!vis[i]){
			dfs(adj, vis, restack, i);
		}
	}
	for (int i = 0; i < numCourses; i++) {
		if (!vis[i] || restack[i]) {
			return false;
		}
	}
	return true;
}
};