class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=1e5,ret=0;
        for(auto it : prices)
        {
            ret=max(ret,it-mn);
            mn=min(mn,it);
        }
        return ret;
    }
};