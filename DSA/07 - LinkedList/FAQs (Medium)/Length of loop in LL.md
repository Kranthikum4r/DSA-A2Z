# Find the Length of a Loop in a Linked List
[Problem Link](https://takeuforward.org/practice/dsa/length-of-loop-in-ll)

## Problem Statement

Given the head of a singly linked list, determine the length of the loop (cycle) in the linked list.

- If a loop exists, return its length.
- If no loop exists, return `0`.

## Approach: Floyd's Cycle Detection Algorithm

We use **Slow and Fast Pointers** to detect whether a cycle exists and calculate its length.

### Step 1: Detect the Loop

- Initialize two pointers, `slow` and `fast`, at the head.
- Move `slow` one step at a time.
- Move `fast` two steps at a time.
- If both pointers meet (`slow == fast`), a loop exists.
- If `fast` or `fast->next` becomes `NULL`, no loop exists.

### Step 2: Calculate the Loop Length

Once both pointers meet inside the loop:

1. Move `slow` one step forward.
2. Initialize `len = 1` because the meeting node is already counted.
3. Continue moving `slow` one step at a time.
4. Increment `len` after every movement.
5. Stop when `slow` reaches the meeting node again.

The final value of `len` is the length of the loop.

## C++ Solution

```cpp
class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        if(!head || !head->next) return 0;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect the loop
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {

                // Step 2: Calculate loop length
                slow = slow->next;
                int len = 1;

                while(slow != fast) {
                    slow = slow->next;
                    len++;
                }

                return len;
            }
        }

        return 0;
    }
};
```

## Dry Run

Consider the following linked list:

```text
1 -> 2 -> 3 -> 4 -> 5
          ↑         |
          |_________|
```

The loop is:

```text
3 -> 4 -> 5 -> 3
```

**Step 1: Detect the loop**

| Iteration | Slow | Fast |
|---|---:|---:|
| Initial | 1 | 1 |
| 1 | 2 | 3 |
| 2 | 3 | 5 |
| 3 | 4 | 4 |

Both pointers meet at node `4`, confirming that a loop exists.

**Step 2: Calculate the loop length**

- Meeting node: `4`
- Move `slow` one step: node `5`, `len = 1`
- Move `slow` one step: node `3`, `len = 2`
- Move `slow` one step: node `4`, `len = 3`

Now `slow == fast`, so we stop.

**Output:**

```text
3
```

## Complexity Analysis

Let `N` be the total number of nodes in the linked list.

- **Time Complexity: O(N)** — Floyd's algorithm detects the loop in linear time, and counting the loop length takes at most one complete traversal of the cycle.
- **Space Complexity: O(1)** — Only two pointers and one integer variable are used.

## Edge Cases

| Input | Output | Explanation |
|---|---:|---|
| `NULL` | 0 | Empty linked list |
| `1 -> NULL` | 0 | No loop |
| `1 -> 2 -> 3 -> NULL` | 0 | No loop |
| `1 -> 1` | 1 | Self-loop |
| `1 -> 2 -> 3 -> 2` | 2 | Loop contains nodes 2 and 3 |
| `1 -> 2 -> 3 -> 4 -> 5 -> 3` | 3 | Loop contains nodes 3, 4 and 5 |

## Key Takeaways

1. Floyd's Cycle Detection Algorithm uses slow and fast pointers.
2. If the pointers meet, a cycle exists.
3. To calculate the cycle length, keep one pointer fixed and move the other until it returns to the meeting node.
4. Initialize `len = 1` because the meeting node is already counted.
5. The solution uses O(N) time and O(1) auxiliary space.

**Related Problems:**
- Detect a Loop in a Linked List.
- Find the Starting Point of a Loop in a Linked List.
- Find the Length of a Loop in a Linked List.
