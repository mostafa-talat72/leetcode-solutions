class Solution {
public:
    int candy(vector<int>& ratings) { 
 
 priority_queue<pair<int, int>> pq;

 int n = ratings.size();
    vector<int> candies(n, 1);
    for (int i = 0; i < n; i++)
    {
        ratings[i]++;
	 pq.push({-ratings[i] , i});
    }
    int ans = 0;

 while (!pq.empty())
    {
        auto [rating, index] = pq.top();
        pq.pop();
        rating = -rating;
        if (index == 0)
        {
            if (index+1<n && ratings[index] > ratings[index + 1])
		 {
			 candies[index] = candies[index + 1] + 1;
            }
        }
        else if (index == n - 1)
        {
            if (ratings[index] > ratings[index - 1])
                candies[index] = candies[index - 1] + 1;
        }
	 else {
            if (rating > ratings[index - 1] && rating > ratings[index + 1])
		 {
			 candies[index] = max(candies[index - 1], candies[index + 1]) + 1;
		 }
		 else if (rating > ratings[index - 1])
		 {
			 candies[index] = candies[index - 1] + 1;
		 }
		 else if (rating > ratings[index + 1])
		 {
			 candies[index] = candies[index + 1] + 1;
            }
	 }
        ans += candies[index];
    }
    return ans;
}
};