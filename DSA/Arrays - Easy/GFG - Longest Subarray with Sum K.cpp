class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0;
        unordered_map<int, int> mp;
        int maxlen = 0;
        mp[0] = -1; // len = i - (-1) = i + 1 
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            
            if(!mp.count(sum))
                mp[sum] = i;
            
            if(mp.count(sum - k))
                maxlen = max(maxlen, i - mp[sum - k]);
        }
        return maxlen;
    }
};
