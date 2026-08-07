class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 1; i <= numRows; i++) {
            vector<int> row(i, 1);

            for(int j = 1; j < i-1; j++) {
                row[j] = ans.back()[j-1] + ans.back()[j];
            }

            ans.push_back(row);
        }

        return ans;
    }
};
