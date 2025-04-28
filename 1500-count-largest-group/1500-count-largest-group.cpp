class Solution {
public:
    int countLargestGroup(int n) { 
	int m[50] = {0};
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        int num = i;
        while (num)
        {
            sum += num % 10;
            num /= 10;
        }
        m[sum]++;
    }
    int mp[10001] = {}, maxCount = 0;
    for (int i = 1; i < 50; i++)
    {
        if (m[i])
        {
            mp[m[i]]++;
            maxCount = max(maxCount, mp[m[i]]);
        }

    }
    for (int i = 1e4; i >= 1; i--)
    {
        if (mp[i])
        {
            return mp[i];
            
        }
    }
    return 1;

}
};