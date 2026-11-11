# Merge K Sorted Linked Lists
[Problem Link](https://leetcode.com/problems/merge-k-sorted-lists/)

**Problem:** Given an array of `K` sorted linked lists, merge all the linked lists into one sorted linked list and return its head.

---

## Approach 1: Sequential Merging (Using a Loop)

### Intuition

We can merge K sorted linked lists one by one using the `mergeTwoLists()` function.

1. Consider the first linked list as the initial result.
2. Iterate through the remaining linked lists.
3. Merge the current result with the next linked list.
4. Update the result after every merge.
5. Return the final merged linked list.

### Code (C++)

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if(list1) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0) return NULL;

        ListNode* head = lists[0];

        for(int i = 1; i < k; i++) {
            head = mergeTwoLists(head, lists[i]);
        }

        return head;
    }
};
```

### Dry Run

**Input:**

```text
lists = [
    1 -> 4 -> 5,
    1 -> 3 -> 4,
    2 -> 6
]
```

**Step 1:** Merge the first two lists.

```text
1 -> 4 -> 5
1 -> 3 -> 4

Result: 1 -> 1 -> 3 -> 4 -> 4 -> 5
```

**Step 2:** Merge the result with the third list.

```text
1 -> 1 -> 3 -> 4 -> 4 -> 5
2 -> 6

Final: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
```

### Complexity Analysis

Let:
- `N` = Total number of nodes across all lists.
- `K` = Number of linked lists.

- **Time Complexity:** `O(N * K)` in the worst case.
- **Auxiliary Space Complexity:** `O(1)`.

The algorithm reuses existing nodes and uses only a constant amount of auxiliary space.

---

## Approach 2: Min Heap (Priority Queue)

### Intuition

Instead of merging lists one by one, we can use a Min Heap to efficiently find the smallest node among all K linked lists.

A Min Heap always keeps the smallest element at its top.

**Algorithm:**

1. Create a Min Heap using a priority queue.
2. Insert the first node of every non-empty linked list into the heap.
3. Create a dummy node and a tail pointer.
4. While the heap is not empty:
   - Extract the smallest node from the heap.
   - Store its next node.
   - Insert the next node into the heap if it exists.
   - Attach the extracted node to the merged list.
5. Return `dummy->next`.

### Code (C++)

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min heap comparator
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>,
                       decltype(cmp)> pq(cmp);

        // Insert first node of every list
        for(auto node : lists) {
            if(node) {
                pq.push(node);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!pq.empty()) {

            // Get smallest node
            ListNode* node = pq.top();
            pq.pop();

            // Save next node
            ListNode* next = node->next;

            // Insert next node into heap
            if(next) {
                pq.push(next);
            }

            // Attach current node
            tail->next = node;
            tail = node;

            // Disconnect current node
            tail->next = NULL;
        }

        return dummy->next;
    }
};
```

### Understanding the Min Heap Comparator

```cpp
auto cmp = [](ListNode* a, ListNode* b) {
    return a->val > b->val;
};
```

- The comparator compares two linked-list nodes based on their values.
- Using `a->val > b->val` creates a Min Heap.
- Therefore, `pq.top()` always gives the node with the smallest value.

### Dry Run

**Input:**

```text
lists = [
    1 -> 4 -> 5,
    1 -> 3 -> 4,
    2 -> 6
]
```

**Initial Min Heap:**

```text
1, 1, 2
```

Now repeatedly extract the smallest node and insert its next node.

| Step | Extracted Node | Inserted Next Node | Merged Result |
|---|---:|---:|---|
| 1 | 1 | 4 | 1 |
| 2 | 1 | 3 | 1 -> 1 |
| 3 | 2 | 6 | 1 -> 1 -> 2 |
| 4 | 3 | 4 | 1 -> 1 -> 2 -> 3 |
| 5 | 4 | 5 | 1 -> 1 -> 2 -> 3 -> 4 |
| 6 | 4 | None | 1 -> 1 -> 2 -> 3 -> 4 -> 4 |
| 7 | 5 | None | 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 |
| 8 | 6 | None | 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6 |

**Final Output:**

```text
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
```

### Complexity Analysis

Let:
- `N` = Total number of nodes across all lists.
- `K` = Number of linked lists.

- **Time Complexity:** `O(N log K)`.
  - Each node is inserted into and removed from the heap at most once.
  - Each heap operation takes `O(log K)` time.
- **Auxiliary Space Complexity:** `O(K)`.
  - The heap stores at most K nodes at a time.

---

## Comparison of Both Approaches

| Feature | Sequential Merging | Min Heap |
|---|---|---|
| Technique | Merge lists one by one | Priority Queue |
| Data Structure | Linked List | Min Heap |
| Time Complexity | `O(N * K)` | `O(N log K)` |
| Auxiliary Space | `O(1)` | `O(K)` |
| Implementation | Simple | Moderate |
| Efficiency | Less efficient | More efficient |

## Key Takeaways

1. **Sequential Merging:** Easy to implement and understand, but becomes slower when K increases.
2. **Min Heap:** Efficiently finds the smallest node among K lists.
3. Both approaches reuse existing linked-list nodes.
4. Both approaches use a dummy node to simplify linked-list construction.
5. For larger values of K, the **Min Heap approach** is generally preferable because it achieves `O(N log K)` time complexity.
