class Solution {
public:
    string triangleType(vector<int>& nums) { 
    
    if (nums[0] + nums[1] > nums[2] && nums[0] + nums[2] > nums[1] && nums[1] + nums[2] > nums[0])
    {

        sort(nums.begin(), nums.end());
        if (nums[1] == nums[0] && nums[1] == nums[2])
            return "equilateral";
        else if (nums[1] == nums[0] || nums[1] == nums[2])
            return "isosceles";

        return "scalene";
    }
    return "none";
}
};