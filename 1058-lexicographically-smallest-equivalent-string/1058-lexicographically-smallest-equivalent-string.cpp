class Solution {
public:
    vector<int> parent;
int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]); // path compression
    return parent[x];
}

void join(int x, int y)
{
    int px = find(x);
    int py = find(y);
    if (px != py)
        parent[px] = parent[py] = min(px, py);
}
string smallestEquivalentString(string s1, string s2, string baseStr) { 
	parent.resize(26);
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < s1.size(); ++i) {
		join(s1[i] - 'a', s2[i] - 'a');
    }
	string result;
	for (char c : baseStr) {
		int root = find(c - 'a');
		result += (char)(root + 'a');
	}
    return result;
}
};