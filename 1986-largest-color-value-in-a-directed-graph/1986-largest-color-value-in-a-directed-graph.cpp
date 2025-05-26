class Solution {
public:
   vector<bool>  cycled;
vector<bool> visited;
bool isCyclic = false;
vector<vector<int>> frq;
int mx = 1;
void dfs(int node, vector<vector<int>>& graph, string& colors)
{
    visited[node] = true;
    cycled[node] = true;
    if (isCyclic)
        return;
    for (int i : graph[node])
    {
        if (!visited[i])
        {
             dfs(i, graph, colors);
            for (int j = 0; j < 26; j++)
            {
                frq[j][node] = max(frq[j][node], frq[j][i]);
                mx = max(mx, frq[j][node]);
            }
            
        }
        else if (cycled[i])
        {
            isCyclic = true;
            return;
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {
                frq[j][node] = max(frq[j][node], frq[j][i]);
                mx = max(mx, frq[j][node]);
            }
        }
    }
    cycled[node] = false;
    frq[colors[node] - 'a'][node]++;
    mx = max(mx, frq[colors[node] - 'a'][node]);
}
 int largestPathValue(string colors, vector<vector<int>>& edges) {
	 
	 
	 visited.resize(colors.size(),0);
	 cycled.resize(colors.size(), 0);
     frq.resize(26,vector<int>(colors.size()));
     vector<vector<int>> graph(colors.size());
     for (auto it : edges)
	 {
         graph[it[0]].push_back(it[1]);
     }


     for (int i = 0; i < colors.size(); i++)
     {
         if (!visited[i])
         {
             dfs(i, graph, colors);
                      }
         if (isCyclic)
             return -1;
     }
     return mx;

 }
};