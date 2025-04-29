class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
	cout << fixed << setprecision(5);
	double ans = 0;
	cout << ((double)(2) / double(3) > (double)(4) / (double)(6)) << endl;
	priority_queue<pair<double, pair<int, int>>>q;
	for (int i = 0; i < classes.size(); i++) {
		double cur=(double)classes[i][0] / (double)classes[i][1];
		double afterAddOne = (double)(classes[i][0] + 1) / (double)(classes[i][1] + 1);
		q.push({ afterAddOne - cur, {classes[i][0], classes[i][1]} });
	}

	while (extraStudents--) {
		auto it = q.top();
		q.pop();
		it.second.first++;
		it.second.second++;
		double cur = (double)(it.second.first) / (double)(it.second.second);
		double afterAddOne = (double)(it.second.first + 1) / (double)(it.second.second + 1);
		q.push({ afterAddOne - cur,{it.second.first, it.second.second} });
	}
	
	while (!q.empty()) {
		auto it = q.top();
		q.pop();
		ans += (double)it.second.first / (double)it.second.second;
	}

	return ans / (classes.size());
}
};