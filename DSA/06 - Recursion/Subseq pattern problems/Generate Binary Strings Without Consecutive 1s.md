[Link here](https://takeuforward.org/practice/dsa/generate-binary-strings-without-consecutive-1s?tab=problem&discussion_id=7080)

```
class Solution {
public:
    void generate(int n, string& cur, vector<string>& ans) {
        if(cur.size() == n) {
            ans.push_back(cur);
            return;
        }

        cur.push_back('0');
        generate(n, cur, ans);
        cur.pop_back();

        if(cur.empty() || cur.back() != '1') {
            cur.push_back('1');
            generate(n, cur, ans);
            cur.pop_back();
        }
    }
    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        string cur;
        generate(n, cur, ans);
        return ans;
    }
};

```
