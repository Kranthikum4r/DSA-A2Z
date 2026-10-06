// Link - https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        int low = mat[0][0];
        int high = mat[0][cols-1];
        
        for(int i = 1; i < rows; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][cols-1]);
        }
        
        int req = (rows * cols) / 2;
        
        while(low < high) {
            int mid = (low + high) / 2;
            
            int count = 0;
            for(int i = 0; i < rows; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if(count <= req)
                low = mid+1;
            
            else 
                high = mid;
        }

        return low;
    }
};
