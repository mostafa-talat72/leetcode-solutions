class Solution {
       public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int l = 0, r = citations.length, mid = 0, out = 0;
        while(l<=r){
            mid=(l+r) / 2;
            System.out.println("mid = " + mid);
            int lowBound = lower_bound(citations, mid);
            if(citations.length -  lowBound >= mid ){
                l = mid+1;
                out = Math.max(out, mid);
            }else
                r=mid-1;
        }
        return out;
    }
    public int lower_bound(int[] citations, int num){
        int l = 0, r = citations.length, mid = 0, out = citations.length;
        while(l<r){
            mid=(l+r) / 2;
            if(citations[mid] >= num){
                r=mid;
                out = mid;
            }else
                l = mid+1;
        }
        System.out.println("num = " + out);
        return out;
    }
}