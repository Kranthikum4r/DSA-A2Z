class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n+1, 0);
        unordered_set<int> s(arr.begin(), arr.end());
        vector<int> ans(2);
        
        for(int x : arr) {
            freq[x]++;
            if(freq[x] == 2) {
                ans[0] = x;
                break;
            }
        }
        
        for(int i = 1; i <= n; i++) {
            if(!s.count(i)) {
                ans[1] = i;
                break;
            }
        }
        
        return ans;
    }
};
