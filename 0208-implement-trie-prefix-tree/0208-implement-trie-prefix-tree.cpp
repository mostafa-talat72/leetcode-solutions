map<string, bool>mp2;
class Trie {
public:
	Trie() {
		mp2.clear();
	}

	void insert(string word) {
		mp2[word] = true;
	}
	bool search(string word) {
		if (mp2.find(word) != mp2.end())
			return true;

		return false;
	}

	bool startsWith(string prefix) {
		for (auto it : mp2) {
			if (it.first.substr(0, prefix.size()) == prefix)
				return true;
		}

		return false;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */