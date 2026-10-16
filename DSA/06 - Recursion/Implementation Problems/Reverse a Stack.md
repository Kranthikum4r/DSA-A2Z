[Problem Link](https://takeuforward.org/practice/dsa/reverse-a-stack)

```
class Solution {
public:
    void reverseStack(stack<int>& st) {
        if (st.size() <= 1) {
            return;
        }

        int topValue = st.top();
        st.pop();

        reverseStack(st);

        insertAtBottom(st, topValue);
    }

    void insertAtBottom(stack<int>& st, int value) {
        if (st.empty()) {
            st.push(value);
            return;
        }

        int topValue = st.top();
        st.pop();

        insertAtBottom(st, value);

        st.push(topValue);
    }
};
```
