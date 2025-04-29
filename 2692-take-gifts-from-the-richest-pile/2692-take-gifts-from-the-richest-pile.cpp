class Solution {
public:
  long long pickGifts(vector<int>& gifts, int k) {

	priority_queue<int>q(gifts.begin(), gifts.end());

	long long res = 0;

	while (k--) {
		int x = q.top();
		q.pop();
		q.push(sqrt(x));
	}
	while (!q.empty()) {
		res += q.top();
		q.pop();
	}
	return res;
}
};
