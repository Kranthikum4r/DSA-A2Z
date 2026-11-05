# M-Coloring Problem – Recursion and Backtracking
[Problem Link](https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1)

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

    for(int k = 0; k
