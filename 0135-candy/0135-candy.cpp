class Solution {
public:
     int candy(vector<int>& ratings) { 
	 
	 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	 int n = ratings.size();
     vector<int> candies(n, 1);
     for (int i = 0; i < n; i++)
     {
		 pq.push({ratings[i], i});
     }

	 while (!pq.empty())
     {
         auto [rating, index] = pq.top();
         pq.pop();
         rating = rating;
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
     }

	 int ans = 0;
	 for (int i = 0; i < n; i++)
	 {
		 ans += candies[i];
     }
     return ans;
 }
};