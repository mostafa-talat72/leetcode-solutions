class Solution {
public:
   long long minSum(vector<int>& nums1, vector<int>& nums2) {
    
    long long l = 1, r = 1e14, mid;
    long long sum1 = 0, sum2 = 0, zero1 = 0, zero2 = 0;
    for (auto it : nums1)
    {
        sum1 += it;
        zero1 += it == 0;
    }
    for (auto it : nums2)
    {
        sum2 += it;
        zero2 += it == 0;
    }

    if (zero1 && !zero2)
    {
        if (sum1 < sum2 && sum2 - sum1 >= zero1)
            return sum2;
        return -1;
    }
    else if (!zero1 && zero2)
    {
        if (sum2 < sum1 && sum1 - sum2 >= zero2)
            return sum1;
        return -1;
    }
    else if (!zero1 && !zero2)
        return sum1 == sum2 ? sum1 : -1;
    long long ans = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;

        bool ok = 1;
        long long s1 = mid - sum1, s2 = mid - sum2;
        if (s1 < zero1 || s2 < zero2 || (s1 && !zero1) || (s2 && !zero2))
            l = mid + 1;
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}
};