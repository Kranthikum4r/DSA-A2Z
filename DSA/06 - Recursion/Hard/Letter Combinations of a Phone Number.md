# 17. Letter Combinations of a Phone Number
[Problem Link](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

**Platform:** LeetCode  
**Difficulty:** Medium  
**Topics:** Recursion, Backtracking, Strings

## Problem Statement

Given a string containing digits from `2` to `9`, return all possible letter combinations that the number could represent.

The mapping of digits to letters is the same as on a telephone keypad.

Return the combinations in any order.

## Phone Keypad Mapping

| Digit | Letters |
|---|---|
| 2 | abc |
| 3 | def |
| 4 | ghi |
| 5 | jkl |
| 6 | mno |
| 7 | pqrs |
| 8 | tuv |
| 9 | wxyz |

## Approach: Recursion + Backtracking

We solve this problem using recursion and backtracking.

For every digit, we find its corresponding letters using the phone keypad mapping.

We then explore each possible letter recursively.

### Steps

1. Create a vector of strings to store the phone keypad mapping.
2. Start recursion from index `0` of the input string.
3. Get the corresponding letters for the current digit.
4. Iterate through each available letter.
5. Add the current letter to the temporary string.
6. Make a recursive call for the next digit.
7. Backtrack using `pop_back()` to remove the last inserted character.
8. Continue until all digits have been processed.

### Base Condition

```cpp
if(i == digits.size()) {
    ans.push_back(curr);
    return;
}
```

When the current index reaches the length of the input string, we have formed one complete letter combination.

Add it to the answer and return.

### Backtracking

```cpp
curr += c;
generate(i + 1, digits, comb, curr, ans);
curr.pop_back();
```

- Add a letter to the current combination.
- Recursively process the next digit.
- Remove the last character to explore another possible letter.

## C++ Solution

```cpp
class Solution {
public:
    void generate(int i, string& digits, vector<string>& comb,
                  string curr, vector<string>& ans) {

        if(i == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = comb[digits[i] - '0'];

        for(char c : letters) {
            curr += c;

            generate(i + 1, digits, comb, curr, ans);

            // Backtrack
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> comb(10);

        comb[2] = "abc";
        comb[3] = "def";
        comb[4] = "ghi";
        comb[5] = "jkl";
        comb[6] = "mno";
        comb[7] = "pqrs";
        comb[8] = "tuv";
        comb[9] = "wxyz";

        vector<string> ans;
        string curr;

        // Empty input handling
        if(digits.empty()) return ans;

        generate(0, digits, comb, curr, ans);

        return ans;
    }
};
```

## Example

**Input:**

```text
digits = "23"
```

**Output:**

```text
["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
```

**Explanation:**

- Digit `2` represents `a`, `b`, `c`.
- Digit `3` represents `d`, `e`, `f`.

Every letter corresponding to digit `2` is combined with every letter corresponding to digit `3`.

Total combinations:

\[
3 \times 3 = 9
\]

## Recursion Tree

For `digits = "23"`:

```text
                    ""
               /     |     \
              a      b      c
            / | \  / | \  / | \
           ad ae af bd be bf cd ce cf
```

Each level represents one digit, and each branch represents a possible letter.

## Complexity Analysis

Let `N` be the length of the input string.

Each digit can represent at most 4 letters.

**Time Complexity:**

\[
O(4^N \times N)
\]

- There are at most `4^N` possible combinations.
- Each combination requires `O(N)` time to construct and store.

**Auxiliary Space Complexity:**

\[
O(N)
\]

- Recursion depth: `O(N)`.
- Current combination: `O(N)`.

Output space is excluded.

## Key Learnings

- Recursion with multiple choices at every level.
- Phone keypad digit-to-letter mapping.
- Backtracking using `push_back()` or `+=` and `pop_back()`.
- Generating all possible string combinations.
- Understanding recursion trees.
- Each recursive level processes one digit.

## Important Observations

1. Each digit represents multiple possible letters.
2. Every recursive call moves to the next digit using `i + 1`.
3. The number of possible combinations depends on the number of letters mapped to each digit.
4. Backtracking helps explore all possible combinations without retaining previous choices.
5. Empty input should return an empty answer.

**Pattern:** Digit Mapping → For Loop → Choose Character → Recursion → Backtrack.
