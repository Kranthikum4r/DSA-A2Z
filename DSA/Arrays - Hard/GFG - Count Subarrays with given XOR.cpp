class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        unordered_map<int, int> freq;
        freq[0] = 1;
        
        int prefiXor = 0;
        int count = 0;
        
        for(int num : arr) {
            prefiXor ^= num;
            
            int target = prefiXor ^ k; // now, target ^ prefiXor = k
            
            if(freq.count(target)) count += freq[target];
            
            freq[prefiXor]++;
        }
        
        return count;
    }
};
