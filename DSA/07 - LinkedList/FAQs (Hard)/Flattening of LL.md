# 235. Flattening of Linked List
[Problem Link](https://takeuforward.org/practice/dsa/flattening-of-ll)

**Problem:** Given a special linked list containing multiple sorted vertical linked lists connected through the `next` pointer, flatten the entire structure into a single sorted linked list using the `child` pointer.

### Node Structure

Each node contains:
- `val`: Stores the node's value.
- `next`: Points to the head of the next vertical list.
- `child`: Points to the next node in the current vertical list.

**Goal:** Flatten all vertical lists into one sorted linked list using `child`. All `next` pointers in the final list must be `NULL`.

---

## Approach 1: Sequential Merging

### Intuition

We can reuse the logic of merging two sorted linked lists.

Instead of merging all lists simultaneously, merge them one by one.

1. Consider the first vertical list as the initial result.
2. Traverse the remaining lists using the `next` pointer.
3. Merge the current result with each vertical list using `child` pointers.
4. Update the result after every merge.
5. Return the final flattened list.

### Code (C++)

```cpp
class Solution {
public:
    // Merge two sorted vertical lists
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(a && b) {
            if(a->val <= b->val) {
                tail->child = a;
                a = a->child;
            }
            else {
                tail->child = b;
                b = b->child;
            }

            tail = tail->child;
            tail->next = NULL;
        }

        if(a) {
            tail->child = a;
        }
        else {
            tail->child = b;
        }

        return dummy.child;
    }

    ListNode* flattenLinkedList(ListNode* &head) {
        if(!head) return NULL;

        ListNode* result = head;
        ListNode* curr = head->next;

        result->next = NULL;

        while(curr) {
            ListNode* nextList = curr->next;
            curr->next = NULL;

            result = mergeTwoLists(result, curr);

            curr = nextList;
        }

        return result;
    }
};
```

### Dry Run

Consider the following vertical lists:

```text
List 1:  1 -> 4 -> 7
List 2:  2 -> 5 -> 8
List 3:  3 -> 6 -> 9
```

**Step 1:** Merge List 1 and List 2.

```text
1 -> 2 -> 4 -> 5 -> 7 -> 8
```

**Step 2:** Merge the result with List 3.

```text
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
```

**Final Output:**

```text
head
 |
 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
```

All nodes are connected through `child`, and their `next` pointers are `NULL`.

### Complexity Analysis

Let:
- `M` = Total number of nodes across all lists.
- `K` = Number of vertical linked lists.

- **Time Complexity:** `O(M * K)` in the worst case.
- **Auxiliary Space Complexity:** `O(1)`.

The algorithm reuses existing nodes and performs iterative merging without using additional data structures.

---

## Approach 2: Min Heap (Priority Queue)

### Intuition

Since every vertical linked list is already sorted, we can use a Min Heap to efficiently find the smallest available node.

A Min Heap always keeps the smallest element at its top.

### Algorithm

1. Create a Min Heap using a priority queue.
2. Traverse the horizontal list using `next`.
3. Insert the head of every vertical list into the heap.
4. Create a dummy node and a tail pointer.
5. While the heap is not empty:
   - Extract the smallest node.
   - Store its next child before modifying pointers.
   - Insert that child into the heap if it exists.
   - Attach the extracted node to the flattened list using `child`.
   - Set its `next` pointer to `NULL`.
6. Return `dummy.child`.

### Code (C++)

```cpp
class Solution {
public:
    ListNode* flattenLinkedList(ListNode* &head) {

        // Min heap comparator
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>,
                       decltype(cmp)> pq(cmp);

        // Insert the head of every vertical list
        ListNode* temp = head;

        while(temp) {
            pq.push(temp);
            temp = temp->next;
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!pq.empty()) {

            // Extract the smallest node
            ListNode* node = pq.top();
            pq.pop();

            // Save the next child
            ListNode* nextNode = node->child;

            // Insert the next child into the heap
            if(nextNode) {
                pq.push(nextNode);
            }

            // Attach the current node
            tail->child = node;
            tail = node;

            // Remove horizontal connection
            node->next = NULL;
            node->child = NULL;
        }

        return dummy.child;
    }
};
```

### Understanding the Min Heap Comparator

```cpp
auto cmp = [](ListNode* a, ListNode* b) {
    return a->val > b->val;
};
```

- Compares two nodes based on their values.
- `a->val > b->val` creates a Min Heap.
- `pq.top()` always returns the node with the smallest value.

### Dry Run

Consider:

```text
List 1:  1 -> 4 -> 7
List 2:  2 -> 5 -> 8
List 3:  3 -> 6 -> 9
```

**Initial Min Heap:**

```text
1, 2, 3
```

Extract the smallest node and insert its child into the heap.

| Step | Extracted Node | Inserted Child | Merged Result |
|---|---:|---:|---|
| 1 | 1 | 4 | 1 |
| 2 | 2 | 5 | 1 -> 2 |
| 3 | 3 | 6 | 1 -> 2 -> 3 |
| 4 | 4 | 7 | 1 -> 2 -> 3 -> 4 |
| 5 | 5 | 8 | 1 -> 2 -> 3 -> 4 -> 5 |
| 6 | 6 | 9 | 1 -> 2 -> 3 -> 4 -> 5 -> 6 |
| 7 | 7 | None | 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 |
| 8 | 8 | None | 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 |
| 9 | 9 | None | 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 |

**Final Output:**

```text
head
 |
 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
```

### Complexity Analysis

Let:
- `M` = Total number of nodes.
- `K` = Number of vertical linked lists.

- **Time Complexity:** `O(M log K)`.
  - Every node is inserted into and removed from the heap once.
  - Each heap operation takes `O(log K)` time.
- **Auxiliary Space Complexity:** `O(K)`.
  - The heap contains at most K nodes at a time.

---

## Comparison of Both Approaches

| Feature | Sequential Merging | Min Heap |
|---|---|---|
| Technique | Merge lists one by one | Priority Queue |
| Data Structure | Linked List | Min Heap |
| Time Complexity | `O(M * K)` | `O(M log K)` |
| Auxiliary Space | `O(1)` | `O(K)` |
| Difficulty | Easy | Moderate |
| Efficiency | Less efficient | More efficient |

## Important Pointer Concepts

1. Use `next` to traverse the heads of different vertical lists.
2. Use `child` to traverse and merge individual vertical lists.
3. Save the `next` pointer before disconnecting horizontal connections.
4. Save the `child` pointer before modifying the current node's links.
5. The final flattened list must use only `child` pointers.
6. Every node's `next` pointer must be `NULL` in the final result.

## Key Takeaways

- **Sequential Merging:** Reuses the two-sorted-list merging technique. It is simple but can take `O(M * K)` time.
- **Min Heap:** Efficiently finds the smallest available node among K sorted lists and takes `O(M log K)` time.
- Both approaches reuse existing nodes without creating new data nodes.

**Recommendation:** Practice Sequential Merging first to strengthen your linked-list pointer manipulation. Then implement the Min Heap approach to understand how a priority queue helps merge K sorted lists efficiently.
