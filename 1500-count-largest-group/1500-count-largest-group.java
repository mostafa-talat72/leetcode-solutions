class Solution {
   
   
   
   
   
   
      public int countLargestGroup(int n) {
        int[] m = new int[50];
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            int num = i;
            while (num != 0) {
                sum += num % 10;
                num /= 10;
            }
            m[sum]++;
        }
        int[] mp = new int[10001];
        int maxCount = 0;
        for (int i = 1; i < 50; i++) {
            if (m[i] != 0) {
                mp[m[i]]++;
                maxCount = Math.max(maxCount, mp[m[i]]);
            }

        }
        for (int i = 10000; i >= 1; i--) {
            if (mp[i] != 0) {
                return mp[i];

            }
        }
        return 1;

    }

}