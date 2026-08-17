class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int last = -1, first = -1;
        
        int low = 0, high = arr.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
        
            if(arr[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if(arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        low = 0, high = arr.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
        
            if(arr[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if(arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return last == -1 ? 0 : last - first + 1;
    }
};
