class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        vector<vector<int>> ans;
        unordered_map<int, bool> visited;
        for(int num : arr) {
            if(!visited[num]) {
                ans.push_back({num, freq[num]});
                visited[num] = true;
            }
        }
        return ans;
    }
};