class Solution {
public:
   int maxDistance(string str, int k)
{
    int x = 0, y = 0;
    vector<int> dist;
    for (char it : str)
    {
        if (it == 'N')
            y++;
        else if (it == 'S')
            y--;
        else if (it == 'E')
            x++;
        else if (it == 'W')
            x--;
        dist.push_back(abs(x) + abs(y));
    }
    if (k == 0)
        return *max_element(dist.begin(), dist.end());
    int mxDist = dist[1];
    int prvDist = dist[0];
    int addDist = 0;
    for (int i= 1; i < dist.size(); i++)
	{
		if (dist[i] < prvDist && k) {
            addDist += 2;
            k--;
		}
        prvDist = dist[i];
        dist[i] += addDist;
        mxDist = max(mxDist, dist[i]);
    }
    return mxDist;
}
};