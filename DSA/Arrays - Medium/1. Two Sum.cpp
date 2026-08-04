class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(mp.count(complement))
                return {mp[complement], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};

// optimal

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numIndices;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            numIndices.push_back({nums[i], i});
        }
        
        sort(numIndices.begin(), numIndices.end());
        int left = 0, right = n-1;
        while(left < right) {
            int sum = numIndices[left].first + numIndices[right].first;
            if(target == sum)
                return {numIndices[left].second, numIndices[right].second};
            else if(target > sum)
                left++;
            else
                right--;
        }
        return {-1, -1};
    }
};
