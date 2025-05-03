class Solution {
public:
    int maxArea(vector<int>& height) {
	int l = 0, r = height.size() - 1;
	int mx = (r - l) * min(height[l], height[r]);
	while (l < r)
	{
		if(height[l] < height[r])
		{
			l++;
		}
		else
		{
			r--;
		}
		mx = max(mx, (r - l) * min(height[l], height[r]));
	}
	return mx;
}
};