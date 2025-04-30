class Solution {
public:
    string compressedString(string word) {
	string ret = "";
	char cnt = '1';
	for (int i = 1; i < word.size();i++){
		if (word[i] == word[i - 1])cnt++;
		if (cnt == ':' || word[i] != word[i - 1]) {
			ret += cnt == ':'? '9' : cnt;
			ret += word[i - 1];
			cnt = '1';
		}
	}
	ret += cnt;
	ret += word.back();
	return ret;
}
};