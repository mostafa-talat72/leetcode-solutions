class Solution {
public:
 
bool check(vector<int>& derived ,int bit){
	vector<int>ones(derived.size(), 0);
	for (int i = 0; i < derived.size() - 1; i++) {
		ones[i] = bit;
		bit = bit ^ derived[i];
	}
	ones.back() = bit;
	return ((bit ^ ones[0]) == derived.back());
}
bool doesValidArrayExist(vector<int>& derived) {

	return check(derived, 0) || check(derived, 1);
}
};