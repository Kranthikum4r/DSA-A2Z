// Link - https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int r = arr.size();
        int c = arr[0].size();
        
        int ans = 0;
        int idx = -1;
        for(int i = 0; i < r; i++) {
            int low = 0, high = c - 1;
            int firstOne = c;
        
            while(low <= high) {
                int mid = (low + high) / 2;
        
                if(arr[i][mid] == 1) {
                    firstOne = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            if(ans < c - firstOne) {
                idx = i;
                ans = c - firstOne;
            }
        }
        return idx;
    }
};
