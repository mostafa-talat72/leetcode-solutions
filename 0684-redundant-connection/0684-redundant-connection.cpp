    int  par[1001];
class Solution {
public:
int find(int u)
{
	if(u==par[u])return u;
	return par[u]=find(par[u]);
}
void join(int u,int v){
	u = find(u);
	v = find(v);
	if (u != v) {
		par[u] = v;
	}
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	iota(par, par + 1001, 0);
	for(auto edg :edges){
		if(find(edg[0]) == find(edg[1]))return edg;
		join(edg[0],edg[1]);
	}
	return {};
}
};