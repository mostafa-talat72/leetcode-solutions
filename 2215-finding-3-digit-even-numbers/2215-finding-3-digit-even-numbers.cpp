class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits)
{
    vector<int> ans, duplic;
    int mp[1000] = {0};
    sort(digits.begin(), digits.end());
    int cnt = 1;
    duplic.push_back(digits[0]);
    for (int i = 1; i < digits.size(); i++)
    {
        if (digits[i] == digits[i - 1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        if (cnt <= 3)
            duplic.push_back(digits[i]);
    }

    for (int i = 0; i < duplic.size(); i++)
    {
        for (int j = i + 1; j < duplic.size(); j++)
        {
            for (int k = j + 1; k < duplic.size(); k++)
            {
                vector<int> tst = {duplic[i], duplic[j], duplic[k]};
                sort(tst.begin(), tst.end());
                do
                {
                    if (tst[0] == 0 || (tst[2] & 1))
                        continue;
                    int num = tst[0];
                    num = num * 10 + tst[1];
                    num = num * 10 + tst[2];
                    if (mp[num])
                        continue;
                    ans.push_back(num);
                    mp[num] = 1;
                }
                while (next_permutation(tst.begin(), tst.end()));
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
};