class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        int n=nums.size();
        for(auto it:nums)
            st.insert(it);
        nums.clear();
        for(auto it : st)
            nums.push_back(it);

        return st.size();
    }
};