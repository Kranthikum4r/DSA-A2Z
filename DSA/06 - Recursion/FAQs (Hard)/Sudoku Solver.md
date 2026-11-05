# Sudoku Solver – Backtracking
[Problem Link](https://leetcode.com/problems/sudoku-solver/description/)

## Problem Statement

Given a partially filled 9 × 9 Sudoku board, solve the Sudoku by filling the empty cells (`'.'`) with digits from `'1'` to `'9'`.

A valid Sudoku board must satisfy three conditions:

1. Each row must contain digits 1–9 without repetition.
2. Each column must contain digits 1–9 without repetition.
3. Each 3 × 3 sub-box must contain digits 1–9 without repetition.

## Approach: Backtracking

We use **recursion and backtracking** to fill the empty cells one by one.

### 1. `isValid()` Function

```cpp
bool isValid(int row, int col, vector<vector<char>>& board, char c)
```

This function checks whether placing digit `c` at position `(row, col)` is valid.

It checks three conditions:

**A. Same Column**

```cpp
for(int i = 0; i < 9; i++) {
    if(board[i][col] == c) return false;
}
```

Checks whether the digit already exists in the current column.

**B. Same Row**

```cpp
for(int j = 0; j < 9; j++) {
    if(board[row][j] == c) return false;
}
```

Checks whether the digit already exists in the current row.

**C. 3 × 3 Sub-box**

```cpp
int rowstart = 3 * (row / 3);
int colstart = 3 * (col / 3);

for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
        if(board[rowstart + i][colstart + j] == c)
            return false;
    }
}
```

Finds the starting position of the 3 × 3 sub-box containing the current cell and checks all nine cells.

If none of these conditions is violated, the function returns `true`.

### 2. `solve()` Function

```cpp
bool solve(vector<vector<char>>& board)
```

This function recursively solves the Sudoku.

Steps:

1. Traverse the entire board using two nested loops.
2. Find an empty cell represented by `'.'`.
3. Try every digit from `'1'` to `'9'`.
4. Call `isValid()` to check whether the digit can be placed.
5. If valid, place the digit in the board.
6. Recursively call `solve()` to solve the remaining board.
7. If recursion returns `true`, the Sudoku is solved.
8. Otherwise, undo the placement by restoring `'.'` and try another digit.
9. If no digit works for the current empty cell, return `false`.

### 3. Base Case

```cpp
return true;
```

If the loops finish without finding any empty cell, the entire board is filled successfully.

Therefore, we return `true`.

### 4. Backtracking

```cpp
board[i][j] = c;

if(solve(board)) return true;

board[i][j] = '.';
```

- First, place a valid digit.
- Recursively try to solve the remaining board.
- If the recursive call fails, remove the previously placed digit.
- Try the next possible digit.

This process is called **backtracking**.

## Complete Code

```cpp
class Solution {
public:
    bool isValid(int row, int col, vector<vector<char>>& board, char c) {
        // same column
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) return false;
        }

        // same row
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == c) return false;
        }

        // sub-box
        int rowstart = 3 * (row / 3);
        int colstart = 3 * (col / 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[rowstart + i][colstart + j] == c)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(isValid(i, j, board, c)) {
                            board[i][j] = c;

                            if(solve(board)) return true;

                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
```

## Complexity Analysis

Let `E` be the number of empty cells in the Sudoku board.

**Time Complexity:**

- For each empty cell, we may try up to 9 digits.
- Each validity check takes O(9) time.
- In the worst case, the search explores up to \(9^E\) combinations.

Therefore, the worst-case time complexity is approximately:

\[
O(9 \times 9^E)
\]

**Space Complexity:**

- The Sudoku board uses O(81) space.
- Recursive calls can go up to E levels.

Auxiliary recursion space:

\[
O(E)
\]

## Key Concepts Used

- Recursion
- Backtracking
- Constraint checking
- 2D matrix traversal
- Base case and recursive case

## Important Takeaway

The main idea of Sudoku Solver is:

**Choose an empty cell → Try digits 1–9 → Check validity → Place digit → Recurse → Backtrack if necessary.**

Backtracking ensures that whenever a choice leads to an invalid solution, we undo that choice and explore another possibility.
