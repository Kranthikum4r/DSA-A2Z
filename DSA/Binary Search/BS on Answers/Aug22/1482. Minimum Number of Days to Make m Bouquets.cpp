class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int boquets = 0;
        int flowers = 0;

        for(int x : bloomDay) {
            if(x <= day) {
                flowers++;

                if(flowers == k) {
                    boquets++;
                    flowers = 0;
                }
            }
            else {
                flowers = 0;
            }

            if(boquets >= m) {
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        long long req = 1LL * m * k;

        if(n < req) return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(canMake(bloomDay, m, k, mid)) {
                ans = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
