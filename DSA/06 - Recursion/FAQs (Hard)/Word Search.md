# 79. Word Search
[Problem Link](https://leetcode.com/problems/word-search/description/)

**Difficulty:** Medium  
**Topics:** Array, String, DFS, Backtracking, Matrix

## 1. Problem Statement

Given an `m x n` grid of characters `board` and a string `word`, return `true` if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.

The same cell cannot be used more than once in a single word path.

---

## 2. Approach: DFS + Backtracking

We use Depth First Search (DFS) to explore all possible paths in the matrix.

### Steps:

1. Traverse every cell in the board.
2. If the current cell matches the first character of the word, start DFS.
3. Check whether the current cell matches `word[idx]`.
4. If it matches, temporarily mark the cell as visited.
5. Explore all four directions:
   - Down: `(i + 1, j)`
   - Right: `(i, j + 1)`
   - Up: `(i - 1, j)`
   - Left: `(i, j - 1)`
6. If any recursive call successfully finds the remaining word, return `true`.
7. Otherwise, restore the original character using backtracking.

### Base Condition

```cpp
if(idx == word.length()) {
    return true;
}
```

When `idx` reaches the length of the word, it means every character has been successfully matched.

### Boundary and Character Check

```cpp
if(i < 0 || j < 0 || i >= m || j >= n ||
   board[i][j] != word[idx]) {
    return false;
}
```

This checks:

- Whether the current position is outside the matrix.
- Whether the current character matches the required character.

If any condition fails, return `false`.

---

## 3. C++ Solution

```cpp
class Solution {
public:
    int m, n;

    bool search(int idx, int i, int j, string word,
                vector<vector<char>>& board) {

        if(idx == word.length()) {
            return true;
        }

        if(i < 0 || j < 0 || i >= m || j >= n ||
           board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '\0';

        if(search(idx + 1, i + 1, j, word, board) ||
           search(idx + 1, i, j + 1, word, board) ||
           search(idx + 1, i - 1, j, word, board) ||
           search(idx + 1, i, j - 1, word, board)) {

            board[i][j] = temp;
            return true;
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        if(board.empty() || board[0].empty()) {
            return false;
        }

        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(search(0, i, j, word, board)) {
                    return true;
                }
            }
        }

        return false;
    }
};
```

---

## 4. Understanding the Important Variables

| Variable | Purpose |
|---|---|
| `idx` | Current character index in the word |
| `i` | Current row position |
| `j` | Current column position |
| `m` | Number of rows |
| `n` | Number of columns |
| `temp` | Temporarily stores the original character |
| `board` | Character matrix |

---

## 5. Dry Run

Consider the following input:

```cpp
board = {
    {'A', 'B', 'C', 'E'},
    {'S', 'F', 'C', 'S'},
    {'A', 'D', 'E', 'E'}
};

word = "ABCCED";
```

### Initial State

```text
A B C E
S F C S
A D E E
```

We start traversing the board.

### Step 1: Find the first character

At position `(0, 0)`:

```text
board[0][0] = 'A'
word[0] = 'A'
```

Both match.

Mark the cell as visited:

```cpp
char temp = board[0][0];
board[0][0] = '\0';
```

### Step 2: Explore Down

```cpp
search(1, 1, 0, word, board);
```

Current character:

```text
board[1][0] = 'S'
word[1] = 'B'
```

They do not match.

Return `false`.

### Step 3: Explore Right

```cpp
search(1, 0, 1, word, board);
```

Current character:

```text
board[0][1] = 'B'
word[1] = 'B'
```

They match.

Mark `B` as visited and continue.

### Step 4: Continue DFS

The algorithm explores the following path:

```text
A -> B -> C -> C -> E -> D
```

Coordinates:

```text
(0,0) -> (0,1) -> (0,2)
       -> (1,2) -> (2,2) -> (2,1)
```

Every character matches the corresponding character in `"ABCCED"`.

### Step 5: Base Condition

After matching `D`:

```cpp
idx = 6;
word.length() = 6;
```

Therefore:

```cpp
if(idx == word.length()) {
    return true;
}
```

The word is successfully found.

**Output:**

```cpp
true
```

---

## 6. Understanding Backtracking

Backtracking is the most important part of this problem.

```cpp
char temp = board[i][j];
board[i][j] = '\0';

// Explore all four directions

board[i][j] = temp;
```

### Why mark a cell as visited?

The same cell cannot be used more than once in a single word path.

For example, while searching for `"ABCCED"`, we should not revisit the same `A` or `B` cell.

### Why restore the character?

After exploring one path, we need to allow other possible paths to use the same cell.

Therefore, we restore the original character.

**Important rule:**

- Mark the cell before exploring.
- Restore the cell after exploring.
- Restore even when the recursive search succeeds.

---

## 7. Important Bugs in the Initial Code

### Bug 1: Variable Shadowing

Initially:

```cpp
int m, n;
```

Inside `exist()`:

```cpp
int m = board.size();
int n = board[0].size();
```

This creates new local variables instead of updating the class variables.

As a result, `search()` uses uninitialized class variables.

**Correction:**

```cpp
m = board.size();
n = board[0].size();
```

### Bug 2: Missing Board Restoration on Success

Initially:

```cpp
if(search(...) || search(...) || search(...)) {
    return true;
}
```

This returns without restoring the current cell.

**Correction:**

```cpp
if(search(...) || search(...) || search(...)) {
    board[i][j] = temp;
    return true;
}
```

### Bug 3: Empty Board Check

Before accessing `board[0]`, ensure the board is not empty.

```cpp
if(board.empty() || board[0].empty()) {
    return false;
}
```

---

## 8. Complexity Analysis

Let:

- `m` = Number of rows.
- `n` = Number of columns.
- `L` = Length of the word.

### Time Complexity

`O(m * n * 4 * 3^(L-1))`

Explanation:

- We can start DFS from every cell: `m * n`.
- The first character has at most 4 possible directions.
- Subsequent characters have at most 3 choices because the previously visited cell cannot be reused.

A simpler upper bound is `O(m * n * 4^L)`.

### Auxiliary Space Complexity

`O(L)`

The recursion stack can go as deep as the length of the word.

---

## 9. Key Takeaways

1. Use DFS to explore possible paths in a matrix.
2. Start searching from every cell because the word can begin anywhere.
3. Use `idx` to track the current character in the word.
4. Explore all four directions.
5. Mark visited cells to avoid reusing them in the same path.
6. Restore the original character during backtracking.
7. Return `true` once all characters are matched.

### General DFS + Backtracking Template

```cpp
bool dfs(int idx, int i, int j) {

    if(idx == word.length()) {
        return true;
    }

    if(outOfBounds || invalidCell) {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '\0';

    // Explore all possible directions

    board[i][j] = temp;

    return result;
}
```

**Core Concept:** DFS explores possible paths, while backtracking restores the visited cells so that other paths can be explored independently.

This pattern is useful in Word Search, Rat in a Maze, Path Finding, and other matrix-based DFS problems.
