class Solution {
public:
    int findLucky(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
    int ans = -1;
    for (int i = 0; i < arr.size(); i)
    {
        int idx = upper_bound(arr.begin() + i, arr.end(), arr[i]) - arr.begin();
        if (arr[i] == idx - i)
        {
            ans = arr[i];
        }
        i = idx;
    }
    return ans;
}
};