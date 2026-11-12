# Find Pairs with Given Sum in Doubly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/find-pairs-with-given-sum-in-doubly-linked-list)

## Problem Statement

Given the head of a sorted doubly linked list and an integer `target`, find all pairs of nodes whose values add up to the given target.

Return the pairs in a 2D vector.

## Approach: Two-Pointer Technique

Since the doubly linked list is sorted, we can use two pointers to find the required pairs efficiently.

- `front` starts at the head of the DLL.
- `last` starts at the last node of the DLL.

We move these pointers towards each other based on the calculated sum.

### Algorithm

1. Create an empty 2D vector `ans` to store the pairs.
2. If the list is empty or contains only one node, return `ans`.
3. Find the last node by traversing the DLL.
4. Initialize `front = head`.
5. Traverse while the pointers have not met or crossed:
   - Calculate `sum = front->val + last->val`.
   - If `sum == target`:
     - Store the pair in `ans`.
     - Move `front` forward and `last` backward.
   - If `sum > target`:
     - Move `last` backward to get a smaller sum.
   - If `sum < target`:
     - Move `front` forward to get a larger sum.
6. Return `ans`.

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        vector<vector<int>> ans;

        if(!head || !head->next) return ans;

        // Find the last node
        ListNode* last = head;

        while(last->next) {
            last = last->next;
        }

        // Two-pointer approach
        ListNode* front = head;

        while(last != front && last->next != front) {
            int sum = front->val + last->val;

            if(sum == target) {
                ans.push_back({front->val, last->val});

                front = front->next;
                last = last->prev;
            }
            else if(sum > target) {
                last = last->prev;
            }
            else {
                front = front->next;
            }
        }

        return ans;
    }
};
```

## Example Dry Run

**Input:**

```text
DLL:    1 <-> 2 <-> 3 <-> 4 <-> 5
Target: 6
```

| Front | Last | Sum | Action |
|---|---|---|---|
| 1 | 5 | 6 | Store (1, 5) |
| 2 | 4 | 6 | Store (2, 4) |
| 3 | 3 | 6 | Stop |

**Output:**

```text
[[1, 5], [2, 4]]
```

## Understanding the Loop Condition

```cpp
while(last != front && last->next != front)
```

This condition checks two things:

1. `last != front`: Both pointers should not point to the same node.
2. `last->next != front`: Both pointers should not have crossed each other.

Since `last` moves backward and `front` moves forward, this condition ensures that we only process valid pairs.

An equivalent condition is:

```cpp
while(front != last && front->prev != last)
```

## Complexity Analysis

Let N be the number of nodes in the DLL.

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(N) | Finding the last node takes O(N), and the two-pointer traversal takes O(N). |
| Auxiliary Space | O(1) | Only two pointers are used, excluding the output vector. |

## Important Edge Cases

1. Empty DLL.
2. DLL containing only one node.
3. No valid pairs exist.
4. Multiple valid pairs exist.
5. Pointers meet at the same node.
6. Pointers cross each other.

## Key Learnings

- A sorted DLL allows efficient pair searching using two pointers.
- Move the right pointer backward when the sum is greater than the target.
- Move the left pointer forward when the sum is smaller than the target.
- Move both pointers when a valid pair is found.
- The two pointers must stop when they meet or cross.
- This technique achieves O(N) time complexity without using an additional hash map.
