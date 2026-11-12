# Clone a Linked List with Random and Next Pointer
[Problem Link](https://takeuforward.org/practice/dsa/clone-a-ll-with-random-and-next-pointer)

## Problem Statement

Given a linked list where each node contains three pointers:

- `val`: Stores the node's value.
- `next`: Points to the next node.
- `random`: Points to any node in the linked list or `NULL`.

Create a deep copy of the given linked list and return the head of the cloned list.

A deep copy means that every node in the cloned list must be a newly created node. No pointers in the cloned list should refer to nodes in the original list.

## Approach: Hash Map

We use an `unordered_map` to maintain the relationship between original nodes and their corresponding cloned nodes.

**Mapping:**

```text
Original Node  ->  Cloned Node
```

### Algorithm

**Step 1: Create all cloned nodes**

1. Initialize an empty hash map `mp`.
2. Traverse the original linked list using `temp`.
3. For every original node, create a new node with the same value.
4. Store the mapping:

```cpp
mp[temp] = new ListNode(temp->val);
```

At this stage, all cloned nodes are created, but their `next` and `random` pointers are not connected.

**Step 2: Connect next and random pointers**

1. Traverse the original linked list again.
2. Connect the cloned node's `next` pointer:

```cpp
mp[temp]->next = mp[temp->next];
```

3. Connect the cloned node's `random` pointer:

```cpp
mp[temp]->random = mp[temp->random];
```

4. Move to the next original node.

**Step 3: Return the cloned head**

```cpp
return mp[head];
```

## C++ Solution

```cpp
class Solution {
public:
    ListNode* copyRandomList(ListNode* head) {
        if(!head) return NULL;

        unordered_map<ListNode*, ListNode*> mp;

        ListNode* temp = head;

        // Step 1: Create cloned nodes
        while(temp) {
            mp[temp] = new ListNode(temp->val);
            temp = temp->next;
        }

        // Step 2: Connect next and random pointers
        temp = head;

        while(temp) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];

            temp = temp->next;
        }

        // Step 3: Return cloned head
        return mp[head];
    }
};
```

## Example Dry Run

**Original Linked List:**

```text
1 -> 2 -> 3 -> NULL
```

Random pointers:

```text
1.random -> 3
2.random -> 1
3.random -> 2
```

**Step 1: Create cloned nodes**

The hash map stores:

| Original Node | Cloned Node |
|---|---|
| Node 1 | New Node 1 |
| Node 2 | New Node 2 |
| Node 3 | New Node 3 |

**Step 2: Connect pointers**

The cloned nodes receive their corresponding `next` and `random` pointers.

```text
Clone 1 -> Clone 2 -> Clone 3 -> NULL

Clone 1.random -> Clone 3
Clone 2.random -> Clone 1
Clone 3.random -> Clone 2
```

**Output:**

A completely independent copy of the original linked list.

## Complexity Analysis

Let N be the number of nodes in the original linked list.

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(N) | Two traversals of the linked list. |
| Auxiliary Space | O(N) | Hash map stores N original-to-cloned node mappings. |

## Important Edge Cases

1. Empty linked list.
2. Linked list containing only one node.
3. All random pointers are `NULL`.
4. A node's random pointer points to itself.
5. Random pointers point to previous nodes.
6. Random pointers point to subsequent nodes.
7. Multiple nodes have random pointers pointing to the same node.

## Key Learnings

- A hash map can establish relationships between original and cloned nodes.
- Store node addresses as keys rather than node values because multiple nodes can have identical values.
- Create all cloned nodes before connecting their pointers.
- `mp[temp->next]` retrieves the cloned version of the original next node.
- `mp[temp->random]` retrieves the cloned version of the original random node.
- Accessing `mp[NULL]` creates or retrieves a NULL-key entry with a NULL pointer value, correctly handling NULL pointers here.
- Deep copying ensures that modifications to the cloned list do not affect the original list.

## Alternative Approach

The problem can also be solved using the **Three-Pass Interweaving Technique**, which achieves:

- Time Complexity: O(N)
- Auxiliary Space: O(1)

This avoids using a hash map by inserting cloned nodes between original nodes and then separating the two lists.
