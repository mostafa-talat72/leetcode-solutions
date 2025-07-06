class FindSumPairs
{
private:
    unordered_map<int, int> mp;
    vector<int> nums2, nums1;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) { 
		mp.clear();
		for (int i = 0; i < nums2.size(); i++) {
			mp[nums2[i]]++;
        }
        this->nums1 = nums1;
        this->nums2 = nums2;
	}

    void add(int index, int val) { 
		mp[nums2[index]]--;
        if (mp[nums2[index]] == 0) {
			mp.erase(nums2[index]);
        }
        mp[nums2[index] + val]++;
        nums2[index] += val;
	}

    int count(int tot) { 
		int ret = 0;
		for (auto& it : nums1) {
            if (tot > it && mp.find(tot - it) != mp.end())
            {
                ret += mp[tot - it];
            }
        }
        return ret ;
	}

};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */