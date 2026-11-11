# Reverse Linked List in Groups of K
[Problem Link](https://leetcode.com/problems/reverse-nodes-in-k-group/)

## Problem Statement

Given the head of a singly linked list and an integer `k`, reverse the nodes of the linked list in groups of `k` nodes.

- Reverse every complete group of `k` nodes.
- If the remaining nodes are fewer than `k`, leave them unchanged.
- Return the modified linked list.

### Example 1

**Input:**
```text
head = [1, 2, 3, 4, 5], k = 2
```

**Output:**
```text
[2, 1, 4, 3, 5]
```

**Explanation:**

- Reverse the first group: `[1, 2]` → `[2, 1]`.
- Reverse the second group: `[3, 4]` → `[4, 3]`.
- The remaining node `[5]` stays unchanged.

### Example 2

**Input:**
```text
head = [1, 2, 3, 4, 5], k = 3
```

**Output:**
```text
[3, 2, 1, 4, 5]
```

---

## Approach: Iterative Reversal + Two Pointers

### Intuition

Instead of reversing the entire linked list, we reverse it group by group.

We use:
- `getkth()` to find the kth node of the current group.
- `reverseList()` to reverse the current group.
- `prev` to connect the previously reversed group.
- `temp` to traverse the next group.

### Algorithm

1. If the list is empty or `k <= 1`, return the original head.
2. Initialize `temp = head` and `prev = NULL`.
3. Find the kth node using `getkth(temp, k)`.
4. If the kth node does not exist:
   - Connect the previous group's tail to the remaining nodes.
   - Stop the process.
5. Store the node after the current group in `next`.
6. Detach the current group by setting `kthNode->next = NULL`.
7. Reverse the detached group using `reverseList()`.
8. Connect the previous group's tail to the reversed group's head.
9. If this is the first group, update `head = kthNode`.
10. Update `prev = temp` because the original first node becomes the group's tail.
11. Move `temp = next` to process the next group.
12. Return the updated head.

---

## C++ Solution

```cpp
class Solution {
public:
    // Find kth node from current node
    ListNode* getkth(ListNode* cur, int k) {
        while(cur && k > 1) {
            cur = cur->next;
            k--;
        }
        return cur;
    }

    // Reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;

        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k <= 1) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp) {
            ListNode* kthNode = getkth(temp, k);

            // If fewer than k nodes remain
            if(kthNode == NULL) {
                if(prev != NULL) {
                    prev->next = temp;
                }
                break;
            }

            // Detach group
            ListNode* next = kthNode->next;
            kthNode->next = NULL;

            // Reverse detached group
            reverseList(temp);

            // Connect previous group
            if(prev) {
                prev->next = kthNode;
            }
            else {
                head = kthNode;
            }

            // Update pointers
            prev = temp;
            temp = next;
        }

        return head;
    }
};
```

---

## Dry Run

**Input:**
```text
head = [1, 2, 3, 4, 5]
k = 2
```

### Iteration 1

Current group: `1 -> 2`

- `kthNode = 2`
- Save `next = 3`
- Detach the group.
- Reverse `1 -> 2`.

Result:
```text
2 -> 1
```

Since this is the first group, update `head = kthNode`.

Update:
```cpp
prev = temp;  // Node 1
temp = next;  // Node 3
```

### Iteration 2

Current group: `3 -> 4`

- `kthNode = 4`
- Save `next = 5`
- Detach and reverse the group.

Result:
```text
4 -> 3
```

Connect the previous group:
```cpp
prev->next = kthNode;
```

Update:
```cpp
prev = temp;  // Node 3
temp = next;  // Node 5
```

### Iteration 3

Current group: `5`

- `getkth(temp, 2)` returns `NULL`.
- Fewer than `k` nodes remain.
- Leave the remaining node unchanged.

Final linked list:

```text
2 -> 1 -> 4 -> 3 -> 5 -> NULL
```

**Output:** `[2, 1, 4, 3, 5]`

---

## Important Pointer Connections

| Statement | Purpose |
|---|---|
| `next = kthNode->next` | Save the remaining linked list |
| `kthNode->next = NULL` | Detach the current group |
| `reverseList(temp)` | Reverse the current group |
| `head = kthNode` | Update head after reversing the first group |
| `prev->next = kthNode` | Connect the previous group |
| `prev = temp` | Original first node becomes the new tail |
| `temp = next` | Move to the next group |

### Key Observation

After reversing a group:

- The original first node becomes the last node.
- The original kth node becomes the first node.
- Therefore, `prev = temp` is essential for connecting subsequent groups.

---

## Complexity Analysis

Let `N` be the number of nodes.

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(N) | Every node is visited and reversed once. |
| Space Complexity | O(1) | Only a constant number of pointers are used. |

---

## Edge Cases

1. Empty linked list.
2. Single-node linked list.
3. `k = 1`: No reversal required.
4. Number of nodes equals `k`.
5. Number of nodes is not divisible by `k`.
6. `k` is greater than the number of nodes.

---

## Key Takeaways

- Use a helper function to find the kth node.
- Save the remaining list before detaching a group.
- Reverse each complete group independently.
- Carefully reconnect consecutive groups.
- Never reverse the incomplete final group.

**Pattern:** Linked List + Iterative Reversal + Pointer Manipulation
