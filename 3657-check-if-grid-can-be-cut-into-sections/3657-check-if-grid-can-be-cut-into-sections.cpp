class Solution {
public:
    bool checkcheckValidCutsxis(int n, vector<pair<int, int>>& axis) {
	int st = axis[0].first, en = axis[0].second, cnt = 0;
	for (int i = 1; i < axis.size(); i++) {
		if (axis[i].first < en) {
			en = max(en, axis[i].second);
		}
		else {
			if (axis[i].first - en + 1 >= 1 && axis[i].first != 0)
				cnt++;
			st = axis[i].first;
			en = axis[i].second;
			if (cnt > 1)
				return true;
		}
	}
	return false;
}

bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
	vector<pair<int, int>> x, y;
	for (int i = 0; i < rectangles.size(); i++) {
		x.push_back({ rectangles[i][0], rectangles[i][2] });
		y.push_back({ rectangles[i][1], rectangles[i][3] });
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	return checkcheckValidCutsxis(n, x) || checkcheckValidCutsxis(n, y);
}
};