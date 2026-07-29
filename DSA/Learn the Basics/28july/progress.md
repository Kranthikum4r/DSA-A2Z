# LC POTD
## 3517. Smallest Palindromic Rearrangement I  

You are given a palindromic string s.  

Return the lexicographically smallest palindromic permutation of s.

```
Example 1:

Input: s = "z"

Output: "z"

Explanation:

A string of only one character is already the lexicographically smallest palindrome.
```
```
Example 2:

Input: s = "babab"

Output: "abbba"

Explanation:

Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.
```
```
Example 3:

Input: s = "daccad"

Output: "acddca"

Explanation:

Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.
```
 
```
Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
s is guaranteed to be palindromic.
```

## Code:  
```
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        for(int i = 0; i < n/2; i++)
            freq[s[i] - 'a']++;

        int idx = 0;
        // sorted the first half
        for(int i = 0; i < 26; i++) {
            while(freq[i] > 0) {
                s[idx] = char(i + 'a');
                idx++;
                freq[i]--;
            }
        }
        // second half should be reverse of first half (palindrome)
        for(int i = 0; i < n / 2; i++) {
            s[n - i - 1] = s[i];
        }
        return s;
    }
};
```
