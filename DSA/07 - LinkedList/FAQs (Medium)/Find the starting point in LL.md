# Find the Starting Point of a Loop in a Linked List
[Problem Link](https://leetcode.com/problems/linked-list-cycle-ii/)

## Problem Statement

Given the head of a singly linked list that contains a cycle, return the node where the cycle begins.

If there is no cycle, return `NULL`.

The solution must identify the actual node (memory address), not just a node with the same value.

### Example 1

**Input:** `3 -> 2 -> 0 -> -4 -> 2 ...`

**Output:** Node with value `2`

**Explanation:** The last node points back to the node containing `2`, forming a cycle.

### Example 2

**Input:** `1 -> 2 -> NULL`

**Output:** `NULL`

**Explanation:** There is no cycle in the linked list.

---

## Approach: Floyd's Cycle Detection Algorithm

We use the **Slow and Fast Pointer (Tortoise and Hare)** technique in two phases.

### Phase 1: Detect the Cycle

1. Initialize `slow` and `fast` to `head`.
2. Move `slow` one step at a time.
3. Move `fast` two steps at a time.
4. If both pointers meet, a cycle exists.
5. If `fast` or `fast->next` becomes NULL, no cycle exists.

### Phase 2: Find the Starting Point

Once the two pointers meet:

1. Reset `slow` to `head`.
2. Keep `fast` at the meeting point.
3. Move both pointers one step at a time.
4. The point where they meet again is the starting node of the cycle.

If no cycle exists, return `NULL`.

---

## C++ Solution

```cpp
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect the cycle
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {

                // Phase 2: Find the starting point
                slow = head;

                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};
```

---

## Mathematical Explanation

This is the most important part of Floyd's Cycle Detection Algorithm.

Let's define:

- **L:** Distance from HEAD to the LOOP START.
- **C:** Total length of the cycle.
- **X:** Distance from LOOP START to the MEETING POINT.

### Step 1: Distance travelled by both pointers

Suppose slow and fast meet after `t` steps.

Slow pointer travels:

\[
D_s = t
\]

Fast pointer travels:

\[
D_f = 2t
\]

Therefore:

\[
D_f = 2D_s
\]

### Step 2: Express the distances

Since the pointers meet inside the cycle, they may have completed different numbers of full cycles.

For slow:

\[
t = L + X + pC
\]

For fast:

\[
2t = L + X + qC
\]

Where `p` and `q` represent the number of complete cycles traversed.

Subtracting the equations:

\[
t = (q-p)C
\]

Therefore, `t` is a multiple of the cycle length.

Substituting:

\[
L + X + pC = (q-p)C
\]

Rearranging:

\[
L+X = (q-2p)C
\]

Thus:

\[
L+X \equiv 0 \pmod C
\]

Finally:

\[
\boxed{L \equiv C-X \pmod C}
\]

### What does this mean?

- `L` is the distance from HEAD to LOOP START.
- `C - X` is the distance from MEETING POINT to LOOP START, moving forward inside the cycle.

Therefore, both distances are equal modulo the cycle length.

This is why resetting one pointer to `head` and moving both pointers one step at a time makes them meet at the LOOP START.

---

## Dry Run

Consider:

`3 -> 2 -> 0 -> -4`

Suppose `-4` points back to node `2`.

### Phase 1: Detect the cycle

| Iteration | Slow | Fast |
|---|---|---|
| Initial | 3 | 3 |
| 1 | 2 | 0 |
| 2 | 0 | 2 |
| 3 | -4 | -4 |

Both pointers meet at node `-4`.

### Phase 2: Find the starting point

Reset `slow = head`.

| Iteration | Slow | Fast |
|---|---|---|
| Initial | 3 | -4 |
| 1 | 2 | 2 |

Both pointers meet at node `2`.

**Final Output:** Node with value `2`.

---

## Complexity Analysis

- **Time Complexity:** O(N)
  - Phase 1 detects the cycle in linear time.
  - Phase 2 finds the cycle starting point in linear time.

- **Auxiliary Space Complexity:** O(1)
  - Only two pointers are used.
  - No additional data structures are required.

---

## Edge Cases

| Linked List | Output |
|---|---|
| `NULL` | `NULL` |
| `1 -> NULL` | `NULL` |
| `1 -> 2 -> NULL` | `NULL` |
| `1 -> 1 ...` (self-loop) | Node `1` |
| `1 -> 2 -> 3 -> 2 ...` | Node `2` |
| `1 -> 2 -> 3 -> 4 -> 1 ...` | Node `1` |

---

## Key Takeaways

1. Floyd's algorithm uses two pointers moving at different speeds.
2. The fast pointer moves twice as fast as the slow pointer.
3. If both pointers meet, a cycle exists.
4. After the first meeting, reset the slow pointer to the head.
5. Move both pointers one step at a time.
6. Their next meeting point is the starting node of the cycle.
7. The mathematical reason is that the distance from HEAD to LOOP START equals the distance from MEETING POINT to LOOP START modulo the cycle length.

**Pattern:** Linked List – Floyd's Cycle Detection + Mathematical Observation

**Related Problems:**
- Detect a Loop in a Linked List
- Find the Middle of a Linked List
- Find the Length of a Loop in a Linked List
