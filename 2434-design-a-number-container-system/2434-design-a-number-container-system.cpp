class NumberContainers {
public:
	unordered_map<int,set<int>>mp;
	unordered_map<int,int>mp2;
	NumberContainers() {
	}

	void change(int index, int number) {
		if (mp2[index] != 0) {
			mp[mp2[index]].erase(index);
			if (mp[mp2[index]].empty()) {
				mp.erase(mp2[index]);
			}
		}
		mp[number].insert(index);
		mp2[index] = number;
	}

	int find(int number) {
		if(mp[number].empty())return -1;
		return *mp[number].begin();
	}
};
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */