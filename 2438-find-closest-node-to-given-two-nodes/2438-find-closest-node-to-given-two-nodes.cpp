class Solution {
public:
    void dfs(int node, int cnt, vector<vector<int>>& adj, int anyNode, vector<pair<int, int>>& val, int& ans, int& mx)
{
    if (anyNode == 1)
    {
        val[node].first = cnt;
    }
    else
    {
        val[node].second = cnt;
    }
    for (auto i : adj[node])
    {
        if (anyNode == 1)
        {
            if (val[i].first == -1)
            {
                
                dfs(i, cnt + 1, adj, anyNode, val, ans, mx);
            }

        }
        else
        {
            if (val[i].second == -1)
            {
                
                dfs(i, cnt + 1, adj, anyNode, val, ans, mx);
            }
        }
    }
    if (anyNode == 2)
    {
        if (val[node].first != -1)
        {
            if (mx > max(val[node].first, val[node].second))
            {
                mx = max(val[node].first, val[node].second);
                ans = node;
            }
            else if (mx == max(val[node].first, val[node].second))
            {
                ans = min(ans, node);
            }
        }
    }
}
int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    vector<vector<int>>adj(edges.size());
    for (int i = 0; i < edges.size(); i++)
    {
        if (~edges[i])
            adj[i].push_back(edges[i]);
    }
    vector<pair<int, int>>val(edges.size(), { -1 , -1 });
   
    int ans = -1, mx = INT_MAX;

    dfs(node1, 0, adj, 1, val, ans, mx);
    dfs(node2, 0, adj, 2, val, ans, mx);
    return ans;
}
};