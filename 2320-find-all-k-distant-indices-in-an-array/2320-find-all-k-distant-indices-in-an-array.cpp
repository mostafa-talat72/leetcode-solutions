class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k)
{

    set<int> temp;
    int n = nums.size();
    vector<int> ans;
    vector<int> keyIndx;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == key)
        {
            keyIndx.push_back(i);
        }
    }

    for (int i = 0,j=0; i < n && j < keyIndx.size();)
    {
        if (abs(i - keyIndx[j]) <= k)
        {
            temp.insert(i);
        }
        else if (i >= keyIndx[j])
        {
            j++;
            continue;
        }
         i++;
    }
    for (auto it : temp)
	{
		ans.push_back(it);
    }
    return ans;
}
};