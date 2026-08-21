class Solution {
  public:
    int floorSqrt(int n) {
        int l = 1, h = n;
        int ans = 1;
        
        while(l <= h) {
            int mid = l + (h - l) / 2;
            
            long long sq = 1LL * mid * mid;
            
            if(sq == n) return mid;
            
            else if(sq < n) {
                ans = mid;
                l = mid + 1;
            }
            else {
                h = mid-1;
            }
        }
        return ans;
    }
};
