class Solution {
public:
    int bfs(vector<vector<int>>& edges, int start, int k) {
	queue<pair<int,int>> q;
    q.push({start, 0});
	vector<bool> visited(edges.size(), false);
	visited[start] = true;
    int ret = 0;
	while (!q.empty()) {
        auto [node, depth] = q.front();
        q.pop();
        if (depth <= k)
            ret++;
        for (int neighbor : edges[node]) {
			if (!visited[neighbor] && depth + 1 <= k) {
				visited[neighbor] = true;
				q.push({neighbor, depth + 1});
			}
        }

	}
	return ret; 
}

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k)
{

    vector<vector<int>> adj1(edges1.size() + 1);

    vector<vector<int>> adj2(edges2.size() + 1);
    for (const auto& edge : edges1)
    {
        adj1[edge[0]].push_back(edge[1]);
        adj1[edge[1]].push_back(edge[0]);
    }
    for (const auto& edge : edges2)
    {
        adj2[edge[0]].push_back(edge[1]);
        adj2[edge[1]].push_back(edge[0]);
    }
    int mx2 = 0;
    for (int i = 0; i < adj2.size(); i++)
    {
		mx2= max(mx2, bfs(adj2, i, k - 1));
	}
    vector<int> ans(adj1.size(), 1);
    for (int i = 0; i < adj1.size(); i++)
	{
        ans[i] = mx2 + bfs(adj1, i, k);
    }
    return ans;
}
};