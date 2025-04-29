class Solution {
public:
 int isPrefixOfWord(string sentence, string searchWord) {
	stringstream ss(sentence);
	string word;
	int i = 1;
	while (ss >> word) {
		if (word.size() >= searchWord.size() && word.substr(0, searchWord.size()) == searchWord) {
			return i;
		}
		i++;
	}
	return -1;
}
};