# Rat in a Maze – Backtracking
[Problem Link](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)

**Platform:** GeeksforGeeks  
**Difficulty:** Medium  
**Topic:** Recursion, Backtracking, Matrix Traversal

## 1. Problem Statement

Given an `N × N` binary matrix `maze`, find all possible paths for a rat to travel from the top-left cell `(0,0)` to the bottom-right cell `(N-1,N-1)`.

- `1` represents an open cell.
- `0` represents a blocked cell.
- The rat can move in four directions: Up (`U`), Down (`D`), Left (`L`), and Right (`R`).
- The rat cannot visit the same cell more than once in a single path.
- Return all valid paths in lexicographically increasing order.

## 2. Approach: Recursion + Backtracking

We use recursion to explore all four possible directions from the current cell.

For every cell:

1. Check whether the current position is within the matrix boundaries.
2. Check whether the cell is open and not visited.
3. If we reach the destination, store the current path.
4. Mark the current cell as visited.
5. Explore all four directions.
6. Remove the last move from the path after each recursive call.
7. Restore the current cell during backtracking.

## 3. Direction Mapping

Here, `x` represents the row and `y` represents the column.

| Direction | Row (`x`) | Column (`y`) |
|---|---|---|
| Down (D) | `x + 1` | `y` |
| Left (L) | `x` | `y - 1` |
| Right (R) | `x` | `y + 1` |
| Up (U) | `x - 1` | `y` |

## 4. C++ Solution

```cpp
class Solution {
public:
    void solve(int x, int y, int X, int Y, string& s,
               vector<vector<int>>& maze, vector<string>& ans) {

        // Check boundaries and blocked/visited cells
        if(x < 0 || y < 0 || x > X || y > Y || maze[x][y] == 0)
            return;

        // Destination reached
        if(x == X && y == Y) {
            ans.push_back(s);
            return;
        }

        // Mark current cell as visited
        maze[x][y] = 0;

        // Down
        s.push_back('D');
        solve(x + 1, y, X, Y, s, maze, ans);
        s.pop_back();

        // Left
        s.push_back('L');
        solve(x, y - 1, X, Y, s, maze, ans);
        s.pop_back();

        // Right
        s.push_back('R');
        solve(x, y + 1, X, Y, s, maze, ans);
        s.pop_back();

        // Up
        s.push_back('U');
        solve(x - 1, y, X, Y, s, maze, ans);
        s.pop_back();

        // Restore current cell
        maze[x][y] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        vector<string> ans;
        string s;

        int n = maze.size();

        // Starting cell is blocked
        if(maze[0][0] == 0)
            return ans;

        solve(0, 0, n - 1, n - 1, s, maze, ans);

        // Sort paths lexicographically
        sort(ans.begin(), ans.end());

        return ans;
    }
};
```

## 5. Important Code Explanations

### A. Boundary and visited-cell checking

```cpp
if(x < 0 || y < 0 || x > X || y > Y || maze[x][y] == 0)
    return;
```

This prevents:
- Moving outside the matrix.
- Entering blocked cells.
- Visiting an already visited cell.

Notice that boundary checks come before accessing `maze[x][y]`.

### B. Destination condition

```cpp
if(x == X && y == Y) {
    ans.push_back(s);
    return;
}
```

When the rat reaches the destination, the current path is stored in the answer.

### C. Marking the current cell

```cpp
maze[x][y] = 0;
```

We temporarily mark the cell as visited so that the rat cannot visit it again in the same path.

### D. Path modification

```cpp
s.push_back('D');
solve(x + 1, y, X, Y, s, maze, ans);
s.pop_back();
```

- `push_back()` adds the current movement.
- Recursive call explores that movement.
- `pop_back()` removes the movement when recursion returns.

This allows us to explore different paths independently.

### E. Backtracking the maze

```cpp
maze[x][y] = 1;
```

After exploring all four directions, we restore the cell.

This allows other possible paths to use the same cell.

## 6. Example and Dry Run

**Input:**

```cpp
maze = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}
};
```

Starting position: `(0,0)`

Destination: `(3,3)`

Two valid paths exist.

**Path 1: DDRDRR**

| Movement | Position |
|---|---|
| Start | (0,0) |
| D | (1,0) |
| D | (2,0) |
| R | (2,1) |
| D | (3,1) |
| R | (3,2) |
| R | (3,3) |

**Path 2: DRDDRR**

| Movement | Position |
|---|---|
| Start | (0,0) |
| D | (1,0) |
| R | (1,1) |
| D | (2,1) |
| D | (3,1) |
| R | (3,2) |
| R | (3,3) |

**Output:**

```cpp
["DDRDRR", "DRDDRR"]
```

## 7. Complexity Analysis

Let `N` be the dimension of the square matrix.

- **Time Complexity:** `O(4^(N*N))` as a loose upper bound because each cell can potentially explore four directions. The visited-cell restriction reduces repeated exploration within each path.
- **Auxiliary Space:** `O(N*N)` for the recursion stack in the worst case, excluding the output.
- **Output Space:** Depends on the number of valid paths and their lengths.

## 8. Key Takeaways

1. Rat in a Maze is a classic backtracking problem.
2. Explore all four possible directions recursively.
3. Mark cells as visited to avoid cycles.
4. Use `push_back()` and `pop_back()` to maintain the current path.
5. Restore visited cells after exploring all directions.
6. Sort the final answer to obtain lexicographical order.

**Backtracking pattern:**

```cpp
// Choose
mark visited;
add movement;

// Explore
recursive call;

// Undo
remove movement;
unmark visited;
```

This pattern is useful in many other problems involving grid traversal, path generation, and recursive exploration.
