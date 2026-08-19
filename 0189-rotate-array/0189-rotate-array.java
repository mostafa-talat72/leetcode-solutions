class Solution {
   public void rotate(int[] nums, int k) {
        Deque<Integer> deque = new ArrayDeque<>();
        for(int a : nums)
            deque.add(a);
        k %= nums.length;
        while(k-- != 0){
           deque.addFirst(deque.removeLast());
        }
        for(int i=0;i<nums.length;i++){
            nums[i] = deque.removeFirst();
        }
    }
}