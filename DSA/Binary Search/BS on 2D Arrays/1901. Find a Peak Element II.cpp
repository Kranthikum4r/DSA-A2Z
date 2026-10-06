// Link - https://leetcode.com/problems/find-a-peak-element-ii/description/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        int low = 0, high = r - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;

            int bestcol = 0;
            for(int i = 1; i < c; i++) {
                if(mat[mid][i] > mat[mid][bestcol]) {
                    bestcol = i;
                }
            }            

            // Move upward
            if(mat[mid][bestcol] > mat[mid + 1][bestcol]) {
                high = mid;
            }
            else {
                // Move downward
                low = mid + 1;
            }
        }
        // largest element in final answer row
        int bestcol = 0;
        for(int i = 1; i < c; i++) {
            if(mat[low][i] > mat[low][bestcol]) {
                bestcol = i;
            }
        }
        return {low, bestcol};
    }
};
