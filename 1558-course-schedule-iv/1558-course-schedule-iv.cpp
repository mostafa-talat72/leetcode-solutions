class Solution {
public:
    
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		if (!visited[graph[start][i]]) {
			dfs(graph, visited, graph[start][i]);
		}
	}
}

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
	
	vector<vector<int>> graph(numCourses);
	vector<vector<bool>>checkIfPrerequisite(numCourses, vector<bool>(numCourses));
	for (auto& p : prerequisites) {
		graph[p[0]].push_back(p[1]);
	}
	for (int i = 0; i < numCourses; i++) {
		vector<bool> visited(numCourses);
		dfs(graph, visited, i);
		for (int j = 0; j < numCourses; j++) {
			checkIfPrerequisite[i][j] = visited[j];
		}
	}
	vector<bool> res;
	for (auto& q : queries) {
		res.push_back(checkIfPrerequisite[q[0]][q[1]]);
	}
	return res;
}
};