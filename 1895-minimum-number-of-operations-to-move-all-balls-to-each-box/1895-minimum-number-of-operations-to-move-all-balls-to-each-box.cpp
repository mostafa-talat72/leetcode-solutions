class Solution {
public:
    vector<int> minOperations(string boxes) {
	vector<int>ans(boxes.size(), 0), right(boxes.size(), 0);
	int cnt = 0;
	for(int i=0;i<boxes.size();i++){
		ans[i] = i != 0 ? ans[i - 1] : 0;
		ans[i] += cnt;
		if (boxes[i] == '1') {
			cnt++;
		}
	}
	cnt = 0;
	for (int i = boxes.size() - 1; i >= 0; i--) {
		right[i] = i != boxes.size() - 1 ? right[i + 1] : 0;
		right[i] += cnt;
		if (boxes[i] == '1') {
			cnt++;
		}
	}
	for (int i = 0; i < boxes.size(); i++) {
		ans[i] += right[i];
    }
	return ans;
}
};