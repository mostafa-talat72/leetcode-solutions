class Solution {
public:
    int power(long long x, int y, int mod)
{
    int res = 1;

    x = x % mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = ((res % mod) * (x % mod)) % mod;
        y = y >> 1;
        x = ((x % mod) * (x % mod)) % mod;
    }
    return res;
}

int numSubseq(vector<int>& nums, int target) { 

	sort(nums.begin(), nums.end());
    int n = nums.size(), ans = 0, mod = 1e9 + 7;
    for (int i = 0; i < n;i++) {
        int siz = upper_bound(nums.begin() + i, nums.end(), target - nums[i]) - nums.begin();
        if (siz > i)
        {
            int cnt = siz - i - 1;
            ans = (ans + power(2, cnt, mod)) % mod;
        }
    }
    return ans;
}
};