# N-Queens Problem – Backtracking (Column-wise Placement)

## Problem

The N-Queens problem asks us to place `N` queens on an `N × N` chessboard such that no two queens attack each other.

A queen can attack another queen if they share:
- The same row.
- The same column.
- The same diagonal.

We need to return all possible valid board arrangements.

## Approach: Backtracking

We solve this problem using **column-by-column placement**.

Instead of placing queens randomly, we place exactly one queen in each column.

For every column:
1. Try placing a queen in each row.
2. Check whether the position is safe.
3. If safe, place the queen.
4. Recursively move to the next column.
5. After returning from recursion, remove the queen (backtracking).

## Why Do We Check Only the Left Side?

Our recursion processes columns from left to right:

```cpp
solve(0, board, ans, n);
```

Then:

```cpp
solve(col + 1, board, ans, n);
```

When placing a queen in column `col`:

- All columns before `col` may contain queens.
- All columns after `col` are empty.
- The current column does not contain any previously placed queen.

Therefore, we only need to check the left side.

| Direction | Check? | Reason |
|---|---|---|
| Same row on the left | Yes | Previous columns may contain queens |
| Same column | No | Exactly one queen is placed per column |
| Upper-left diagonal | Yes | May contain previously placed queens |
| Lower-left diagonal | Yes | May contain previously placed queens |
| Right side | No | Future columns are empty |

## C++ Code

```cpp
class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, int n) {
        // col-by-col arrangement, so only left of board is to checked
        // because, right of board still doesn't have queens

        // Check same row on the left
        for(int j = 0; j < col; j++) {
            if(board[row][j] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }

        // Check lower-left diagonal
        for(int i = row, j = col; i < n && j >= 0; i++, j--) {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int col, vector<vector<char>>& board,
               vector<vector<string>>& ans, int n) {

        // All columns have been filled successfully
        if(col == n) {
            vector<string> temp;

            for(int i = 0; i < n; i++) {
                string row(board[i].begin(), board[i].end());
                temp.push_back(row);
            }

            ans.push_back(temp);
            return;
        }

        // Try placing a queen in every row of current column
        for(int row = 0; row < n; row++) {

            if(isSafe(row, col, board, n)) {

                // Place queen
                board[row][col] = 'Q';

                // Move to next column
                solve(col + 1, board, ans, n);

                // Backtrack: remove queen
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<char>> board(n, vector<char>(n, '.'));

        vector<vector<string>> ans;

        solve(0, board, ans, n);

        return ans;
    }
};
```

## Base Case

```cpp
if(col == n)
```

When `col == n`, it means we have successfully placed one queen in every column.

Since all placements passed the safety checks, we have found a valid arrangement.

We convert the character board into strings and store it in the answer.

## Backtracking

```cpp
board[row][col] = 'Q';

solve(col + 1, board, ans, n);

board[row][col] = '.';
```

This is the most important part of the algorithm.

- Place the queen.
- Explore the next column recursively.
- Remove the queen when returning.

Removing the queen allows us to try another row in the same column.

## Complexity Analysis

Let `N` be the size of the chessboard.

- **Time Complexity:** Approximately `O(N! × N)` for the search and board construction, commonly expressed as `O(N!)` when ignoring the output-copying cost.
- **Auxiliary Space:** `O(N²)` for the board and `O(N)` recursion depth.
- **Output Space:** Depends on the number of valid solutions, with `O(N²)` storage per solution.

## Key Takeaways

1. N-Queens is a classic backtracking problem.
2. Place one queen per column to avoid checking the same column.
3. Check the same row and both left diagonals.
4. Backtracking means placing, exploring, and undoing a choice.
5. The base case is reached when all `N` columns have been processed.

**Important:** If we instead place queens row by row, we would check the upper-left diagonal, left, and lower-left diagonal in the same way, but the placement direction and safety checks would be adjusted accordingly.
