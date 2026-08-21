class Solution {
  public:
    int nthRoot(int n, int m) {
        if(m == 0) return 0;
        
        int l = 1, h = m;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            
            long long res = 1LL * pow(mid, n);
            if(res == m) return mid;
            else if(res > m) h = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};
class Solution {
  public:
    int nthRoot(int n, int m) {
        int low = 1, high = m;
        
        if(m == 0) return 0;
        
        if(n == 1) return m;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;            
            
            long long ans = 1;
            for (int i = 0; i < n; i++) {
                ans *= mid;
                if (ans > m) break;
            }
            
            if(ans == m) return mid;
            
            if(ans < m) low = mid+1;
            
            else high = mid-1;
        }
        return -1;
    }
};
