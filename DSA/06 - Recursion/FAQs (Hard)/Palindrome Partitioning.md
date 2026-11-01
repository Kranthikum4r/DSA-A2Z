# 131. Palindrome Partitioning
[Problem Link](https://leetcode.com/problems/palindrome-partitioning/description/)

**Difficulty:** Medium  
**Topics:** Recursion, Backtracking, Strings

## Problem Statement

Given a string `s`, partition it such that every substring in the partition is a palindrome.

Return all possible palindrome partitioning of `s`.

### Example

**Input:**
```cpp
s = "aab";
```

**Output:**
```cpp
[
    ["a", "a", "b"],
    ["aa", "b"]
]
```

**Explanation:**

There are two possible ways to partition `"aab"` such that every substring is a palindrome:

1. `"a" | "a" | "b"`
2. `"aa" | "b"`

---

## 1. Approach: Recursion + Backtracking

The main idea is to explore every possible substring starting from the current index.

Instead of choosing a fixed substring length, we try all possible ending positions.

For every substring:

1. Generate a substring from `index` to `i`.
2. Check whether the substring is a palindrome.
3. If it is a palindrome, add it to the current partition.
4. Recursively process the remaining part of the string.
5. Backtrack by removing the last selected substring.

We continue until the entire string has been partitioned.

### Why Backtracking?

Backtracking helps us explore different possible partitions.

After exploring one choice, we undo that choice so that we can explore another possibility without affecting the previous state.

The three important operations are:

```cpp
// Choose
cur.push_back(sub);

// Explore
solve(i + 1, s, cur, ans);

// Undo the choice
cur.pop_back();
```

---

## 2. C++ Solution

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    void solve(int index, string& s,
               vector<string>& cur,
               vector<vector<string>>& ans) {

        // Base condition
        if(index == s.length()) {
            ans.push_back(cur);
            return;
        }

        // Try all possible substrings
        for(int i = index; i < s.length(); i++) {

            string sub = s.substr(index, i - index + 1);

            if(isPalindrome(sub)) {

                // Choose
                cur.push_back(sub);

                // Explore
                solve(i + 1, s, cur, ans);

                // Backtrack
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> cur;

        solve(0, s, cur, ans);

        return ans;
    }
};
```

---

## 3. Understanding the Important Variables

| Variable | Purpose |
|---|---|
| `index` | Starting position of the current substring |
| `i` | Ending position of the current substring |
| `sub` | Currently selected substring |
| `cur` | Stores the current valid partition |
| `ans` | Stores all valid partitions |

### Understanding `substr()`

```cpp
string sub = s.substr(index, i - index + 1);
```

The `substr()` function takes two arguments:

- First argument: Starting index.
- Second argument: Number of characters.

For example:

```cpp
string s = "aab";

s.substr(0, 1); // "a"
s.substr(0, 2); // "aa"
s.substr(0, 3); // "aab"
```

---

## 4. Dry Run: s = "aab"

Initially:

```cpp
index = 0;
cur = {};
ans = {};
```

### Step 1: index = 0

The loop starts:

```cpp
for(int i = 0; i < 3; i++)
```

**Iteration 1: i = 0**

```cpp
sub = s.substr(0, 1);
sub = "a";
```

`"a"` is a palindrome.

Select it:

```cpp
cur.push_back("a");
```

Current state:

```text
cur = ["a"]
```

Recursive call:

```cpp
solve(1, s, cur, ans);
```

### Step 2: index = 1

Current state:

```text
index = 1
cur = ["a"]
```

**Iteration 1: i = 1**

```cpp
sub = s.substr(1, 1);
sub = "a";
```

`"a"` is a palindrome.

Select it:

```cpp
cur.push_back("a");
```

Current state:

```text
cur = ["a", "a"]
```

Recursive call:

```cpp
solve(2, s, cur, ans);
```

### Step 3: index = 2

Current state:

```text
index = 2
cur = ["a", "a"]
```

**Iteration 1: i = 2**

```cpp
sub = s.substr(2, 1);
sub = "b";
```

`"b"` is a palindrome.

Select it:

```cpp
cur.push_back("b");
```

Current state:

```text
cur = ["a", "a", "b"]
```

Recursive call:

```cpp
solve(3, s, cur, ans);
```

### Step 4: Base Condition

```cpp
if(index == s.length()) {
    ans.push_back(cur);
    return;
}
```

Here:

```text
index = 3
s.length() = 3
```

The base condition is satisfied.

The first partition is stored:

```text
ans = [
    ["a", "a", "b"]
]
```

Now recursion returns to the previous function call.

---

## 5. Backtracking

After returning from the recursive call, this statement executes:

```cpp
cur.pop_back();
```

It removes the last selected substring `"b"`.

Before:

```text
cur = ["a", "a", "b"]
```

After:

```text
cur = ["a", "a"]
```

Now the loop at `index = 1` continues.

**Iteration 2: i = 2**

```cpp
sub = s.substr(1, 2);
sub = "ab";
```

Check whether `"ab"` is a palindrome.

Since:

```text
a != b
```

It is not a palindrome.

Therefore, this choice is rejected.

The recursive call at `index = 1` finishes.

We return to `index = 0`.

Another backtracking operation happens:

```cpp
cur.pop_back();
```

It removes the first `"a"`.

Current state:

```text
cur = []
```

Now we explore the next possibility from index 0.

---

## 6. Finding the Second Partition

### Step 5: index = 0, i = 1

The outer loop continues to its second iteration.

```cpp
sub = s.substr(0, 2);
sub = "aa";
```

`"aa"` is a palindrome.

Select it:

```cpp
cur.push_back("aa");
```

Current state:

```text
cur = ["aa"]
```

Recursive call:

```cpp
solve(2, s, cur, ans);
```

### Step 6: index = 2

```cpp
sub = s.substr(2, 1);
sub = "b";
```

`"b"` is a palindrome.

Select it:

```cpp
cur.push_back("b");
```

Current state:

```text
cur = ["aa", "b"]
```

Recursive call:

```cpp
solve(3, s, cur, ans);
```

### Step 7: Base Condition

Again:

```cpp
index == s.length()
```

Therefore:

```cpp
ans.push_back(cur);
```

Now the result becomes:

```text
ans = [
    ["a", "a", "b"],
    ["aa", "b"]
]
```

The second valid partition is found!

Finally, backtracking removes `"b"` and then `"aa"` as the recursive calls return.

The algorithm finishes after exploring all possibilities.

---

## 7. Recursion Tree

For the input `"aab"`:

```text
                         ""
                         |
              ---------------------
              |                   |
             "a"                 "aa"
              |                   |
             "a"                 "b"
              |                   |
             "b"                 END
              |
             END

        ["a","a","b"]       ["aa","b"]
```

Invalid choices:

```text
"aab" -> Not a palindrome
"ab"  -> Not a palindrome
```

Only valid palindrome substrings are selected.

---

## 8. Complete Execution Table

| Step | Index | Substring | Operation |
|---|---:|---|---|
| 1 | 0 | `"a"` | Push |
| 2 | 1 | `"a"` | Push |
| 3 | 2 | `"b"` | Push |
| 4 | 3 | — | Store first answer |
| 5 | 2 | — | Pop `"b"` |
| 6 | 1 | `"ab"` | Reject |
| 7 | 0 | — | Pop `"a"` |
| 8 | 0 | `"aa"` | Push |
| 9 | 2 | `"b"` | Push |
| 10 | 3 | — | Store second answer |
| 11 | 2 | — | Pop `"b"` |
| 12 | 0 | — | Pop `"aa"` |

---

## 9. Complexity Analysis

Let `n` be the length of the string.

**Time Complexity:**

`O(n * 2^n)` approximately.

- There are up to `2^(n-1)` possible partitions.
- Each partition can require up to `O(n)` work for substring creation and palindrome checking.

**Auxiliary Space Complexity:**

`O(n)` for the recursion stack and current partition, excluding the output storage.

---

## 10. Key Takeaways

1. Use an `index` to track where the next substring should begin.
2. Use a loop to generate all possible substrings.
3. Check whether each substring is a palindrome before selecting it.
4. Use recursion to process the remaining string.
5. Use `push_back()` to make a choice.
6. Use `pop_back()` to undo the choice and explore other possibilities.
7. When `index == s.length()`, the complete partition is valid.

### General Backtracking Template

```cpp
for(int i = index; i < n; i++) {

    if(isValid(choice)) {

        // Choose
        cur.push_back(choice);

        // Explore
        solve(i + 1);

        // Undo choice
        cur.pop_back();
    }
}
```

**Core Concept:** Recursion explores all possible choices, while backtracking ensures that each choice is explored independently without affecting other possibilities.

This pattern is useful in Subsets, Combination Sum, Palindrome Partitioning, and many other recursion and backtracking problems.
