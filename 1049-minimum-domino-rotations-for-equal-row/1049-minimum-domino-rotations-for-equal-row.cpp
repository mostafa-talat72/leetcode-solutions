class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) { 
	int n = tops.size(), num = -1;
	int fr[7] = {0};
    for (int i = 0; i < n; i++)
    {
        if (++fr[tops[i]] == n)
        {
            num = tops[i];
            break;
        }
        if (tops[i] != bottoms[i])
        {
            if (++fr[bottoms[i]] == n)
            {
                num = bottoms[i];
                break;
            }
        }
    }
    if (num == -1)
    {
        return -1;
    }
    int top = 0, down = 0;
    for (int i = 0; i < n; i++)
    {
        if (tops[i] == num && bottoms[i] == num)
        {
            continue;
        }
        if (tops[i] == num)
        {
            top++;
        }
        else if (bottoms[i] == num)
        {
            down++;
        }
    }
    return min(top, down);
}
};