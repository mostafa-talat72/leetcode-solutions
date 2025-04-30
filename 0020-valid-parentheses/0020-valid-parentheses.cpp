class Solution {
public:
    bool isValid(string s) {
	stack<char> st;
	for(auto it:s){
		if (it == '(' || it == '{' || it == '[') st.push(it);
		else if (it == ')' || it == '}' || it == ']') {
			if (st.empty()) return false;
			if (it == ')' && st.top() != '(') return false;
			if (it == '}' && st.top() != '{') return false;
			if (it == ']' && st.top() != '[') return false;
			st.pop();
		}
	}
	return st.empty();
}
};