class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int ans=0,cnt=0;
       for(auto it:nums){
            if(cnt==0)
                ans=it;
            if(ans!=it)
                cnt--;
            else
                cnt++;
       }
       return ans;
    }
};