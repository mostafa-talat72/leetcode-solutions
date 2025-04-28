class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
    int cnt = 0, mp[2002] = {0}, out = 0;
    int n = nums.size();
	for (auto it : nums)
	{
        if (mp[it])
            continue;
        mp[it]++;
        cnt++;
	}
    for (int i = cnt-1; i < n; i++)
    {
        memset(mp, 0, sizeof(mp));

        int l = 0, r = 0, dist = 0;
        while (l <= r && r < n)
        {
            if (!mp[nums[r]])
            {
                dist++;
            }
            mp[nums[r]]++;
            if (r - l  == i)
            {
                if (dist==cnt)
                {
                    out++;
                }
                mp[nums[l]]--;
                if (!mp[nums[l]])
                {
                    dist--;
                }
                l++;
            }
            r++;
        }
    }
    return out;
}
};