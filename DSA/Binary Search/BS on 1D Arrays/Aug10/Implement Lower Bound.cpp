class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int l = 0, r = arr.size()-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(arr[mid] >= target) r = mid - 1;
            else l = mid+1;
        }
        return l;
    }
};
