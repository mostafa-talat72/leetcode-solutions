class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
	int ans = arr.size();
	int right = arr.size() - 1;


	while (right > 0 && arr[right - 1] <= arr[right])
		right--;
	if(!right) return 0;
	ans = right;
	for (int left = 0; left < arr.size(); left++) {
		if (left > 0 && arr[left - 1] > arr[left]) break;
		while (right<arr.size() && arr[left]>arr[right]) {
			right++;
		}
		ans = min(ans, right - left - 1);
	}
	return ans;
}
};