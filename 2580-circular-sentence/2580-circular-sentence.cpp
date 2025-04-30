class Solution {
public:
   bool isCircularSentence(string sentence) {
	if (sentence.front() != sentence.back()) return false;
	for(int i=1;i<sentence.size();i++){
		if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])return false;
	}

	return true;
}
};