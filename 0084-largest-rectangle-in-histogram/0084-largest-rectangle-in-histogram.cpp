class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
	stack<int>s;
	int sum = 0;
	for (int i = 0; i <= heights.size(); i++) {
		while (!s.empty() && (i == heights.size() || heights[s.top()] > heights[i])) {
			int h = heights[s.top()];
			s.pop();
			int w=(!s.size()) ? i : i - s.top() - 1;
			sum = max(sum, w * h);
		}
		s.push(i);
	}
	return sum;
}
};