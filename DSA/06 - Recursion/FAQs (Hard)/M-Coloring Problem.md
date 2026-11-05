# M-Coloring Problem – Recursion and Backtracking

**Platform:** GeeksforGeeks  
**Difficulty:** Medium  
**Topic:** Recursion, Backtracking, Graphs

## 1. Problem Statement

Given an undirected graph with `V` vertices and `E` edges, determine whether the graph can be colored using at most `M` colors such that no two adjacent vertices have the same color.

- Each vertex must be assigned one color.
- Adjacent vertices cannot have the same color.
- We can use at most `M` different colors.

Return `true` if a valid coloring exists; otherwise, return `false`.

## 2. Approach: Recursion + Backtracking

We use recursion to assign colors to vertices one by one.

For every vertex:

1. Try assigning each color from `1` to `M`.
2. Check whether the selected color is safe.
3. If safe, assign that color to the current vertex.
4. Recursively move to the next vertex.
5. If the recursive call fails, remove the assigned color and try another color.
6. If all vertices are successfully colored, return `true`.

## 3. Graph Representation – Adjacency Matrix

We first convert the given edge list into an adjacency matrix.

```cpp
vector<vector<int>> graph(v, vector<int>(v, 0));

for(auto it : edges) {
    int i = it[0];
    int j = it[1];

    graph[i][j] = 1;
    graph[j][i] = 1;
}
```

Here:
- `graph[i][j] == 1` means vertices `i` and `j` are connected.
- `graph[i][j] == 0` means there is no edge between them.

Since the graph is undirected, we mark both directions.

**Important correction:** Your original initialization was:

```cpp
vector<vector<int>> graph(10, vector<int>(v, 10));
```

It should be:

```cpp
vector<vector<int>> graph(v, vector<int>(v, 0));
```

This ensures that the adjacency matrix has the correct dimensions and all entries initially represent no edges.

## 4. C++ Solution

```cpp
class Solution {
public:
    bool isSafe(int node, vector<int>& color,
                vector<vector<int>>& graph, int v, int col) {

        for(int k = 0; k < v; k++) {

            if(k != node && graph[k][node] == 1 && color[k] == col) {
                return false;
            }
        }

        return true;
    }

    bool solve(int node, vector<int>& color, int m, int v,
               vector<vector<int>>& graph) {

        // All vertices are successfully colored
        if(node == v) {
            return true;
        }

        // Try all available colors
        for(int i = 1; i <= m; i++) {

            if(isSafe(node, color, graph, v, i)) {

                // Assign color
                color[node] = i;

                // Move to next vertex
                if(solve(node + 1, color, m, v, graph))
                    return true;

                // Backtrack
                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(int v, vector<vector<int>>& edges, int m) {

        vector<int> color(v, 0);

        // Create adjacency matrix
        vector<vector<int>> graph(v, vector<int>(v, 0));

        for(auto it : edges) {
            int i = it[0];
            int j = it[1];

            graph[i][j] = 1;
            graph[j][i] = 1;
        }

        return solve(0, color, m, v, graph);
    }
};
```

## 5. Important Function Explanations

### A. isSafe() – Checking whether a color is valid

```cpp
bool isSafe(int node, vector<int>& color,
            vector<vector<int>>& graph, int v, int col) {

    for(int k = 0; k < v; k++) {

        if(k != node && graph[k][node] == 1 && color[k] == col) {
            return false;
        }
    }

    return true;
}
```

We check all vertices connected to the current vertex.

Three conditions:

1. `k != node`: Do not compare the vertex with itself.
2. `graph[k][node] == 1`: Check only adjacent vertices.
3. `color[k] == col`: Check whether an adjacent vertex already has the selected color.

If all three conditions are true, the selected color is unsafe.

Otherwise, the color can be assigned.

### B. solve() – Recursive color assignment

```cpp
if(node == v) {
    return true;
}
```

This is the base case.

When `node == v`, it means all vertices from `0` to `v-1` have been successfully colored.

```cpp
for(int i = 1; i <= m; i++) {
```

We try every available color, from `1` to `M`.

```cpp
color[node] = i;
```

If the color is safe, assign it to the current vertex.

```cpp
if(solve(node + 1, color, m, v, graph))
    return true;
```

Recursively try coloring the next vertex.

```cpp
color[node] = 0;
```

If the recursive call fails, undo the current assignment and try another color.

This is the backtracking step.

## 6. Dry Run

Consider a graph with four vertices:

```cpp
v = 4;
m = 3;

edges = {
    {0, 1},
    {0, 2},
    {1, 2},
    {1, 3},
    {2, 3}
};
```

The graph looks like:

```text
       0
      / \
     1---2
      \ /
       3
```

We have four vertices and three available colors.

One possible coloring:

| Vertex | Assigned color |
|---|---|
| 0 | 1 |
| 1 | 2 |
| 2 | 3 |
| 3 | 1 |

All adjacent vertices have different colors.

Therefore, the answer is:

```cpp
true
```

### What happens during backtracking?

Suppose vertex `2` cannot be assigned the current color.

The algorithm:

1. Removes the previously assigned color.
2. Tries the next available color.
3. Continues if a safe color is found.
4. Returns `false` if no color works.

If no color works for a vertex, recursion returns to the previous vertex and changes its color.

## 7. Complexity Analysis

Let:
- `V` = Number of vertices.
- `M` = Number of available colors.

| Operation | Complexity |
|---|---|
| Creating adjacency matrix | O(V²) |
| Checking whether a color is safe | O(V) |
| Trying colors for a vertex | O(M) |
| Recursive color assignment | O(M^V) |

**Overall Time Complexity:** O(V² + V × M^V), commonly expressed as O(V × M^V) for the backtracking search.

**Auxiliary Space Complexity:** O(V²) for the adjacency matrix and O(V) for the color array and recursion stack.

## 8. Key Takeaways

1. Graph Coloring is a classic backtracking problem.
2. Assign colors to vertices one by one.
3. Never assign the same color to adjacent vertices.
4. Use an adjacency matrix to identify neighboring vertices.
5. Try all available colors using a loop.
6. Undo an assignment when the recursive path fails.
7. If all vertices are colored, return `true`.

### General Backtracking Pattern

```cpp
for(each possible choice) {

    if(isSafe(choice)) {

        // Make a choice
        apply(choice);

        // Explore
        if(solve(next))
            return true;

        // Undo the choice
        remove(choice);
    }
}

return false;
```

This pattern is useful in N-Queens, Sudoku Solver, Graph Coloring, and other constraint-based backtracking problems.
