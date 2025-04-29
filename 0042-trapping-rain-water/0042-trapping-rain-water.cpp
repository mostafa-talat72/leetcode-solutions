class Solution {
public:
    int trap(vector<int>& height) {
	int temp = 0, sum = 0, r = 0, last = -1;
	vector<pair<int, int>>bridg;

	while( r<height.size())
	{
		last = -1;
		while(!bridg.empty() && height[r]>bridg.back().first){
			temp += bridg.back().first;
			last = bridg.back().second;
			bridg.pop_back();
		}

		if (bridg.empty() && last != -1) {
			sum += ((r - last - 1) * height[last]) - temp + height[last];
			temp = 0;
		}
		bridg.push_back({ height[r],r++ });
	}

	if(!bridg.empty())
	{
		last=bridg.back().second;
		bridg.pop_back();
	}
	else
		temp = 0;
	
	while (!bridg.empty()) {
		sum += ((last - bridg.back().second - 1) * height[last]);
		last = bridg.back().second;
		bridg.pop_back();
	}	
	return sum - temp;
}
};