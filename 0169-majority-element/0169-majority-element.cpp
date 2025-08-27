class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ret=0,n=nums.size();
        for(auto it:nums){
            mp[it]++;
            if(mp[it]>n/2 ){
                ret=it;
                break;
            }
        }
        return ret;
    }
};