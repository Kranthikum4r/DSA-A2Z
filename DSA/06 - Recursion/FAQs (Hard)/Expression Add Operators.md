# 282. Expression Add Operators – Backtracking
[Problem Link](https://leetcode.com/problems/expression-add-operators/description/)

**Difficulty:** Hard  
**Topics:** Recursion, Backtracking, String, Expression Evaluation

## 1. Problem Statement

Given a string `num` containing only digits and an integer `target`, insert the operators `+`, `-`, and `*` between the digits to generate all possible expressions that evaluate to the target.

**Conditions:**
- We can use `+`, `-`, and `*`.
- An operand cannot contain leading zeros.
- An operand can contain multiple digits.
- Return all valid expressions.

### Example

**Input:**
```text
num = "123"
target = 6
```

**Output:**
```text
["1*2*3", "1+2+3"]
```

Both expressions evaluate to 6.

---

## 2. Approach: Recursion and Backtracking

We process the input string by selecting different possible operands and trying all three operators.

At every recursive call, we maintain the following information:

| Parameter | Meaning |
|---|---|
| `i` | Starting index of the next operand |
| `val` | Current evaluated expression value |
| `prev` | Previous operand, including its sign |
| `cur` | Expression constructed so far |
| `num` | Original input string |
| `target` | Required result |
| `ans` | Stores valid expressions |

### Step 1: Base Case

```cpp
if(i == num.length()) {
    if(val == target) {
        ans.push_back(cur);
    }
    return;
}
```

When `i` reaches the end of the string, all digits have been processed.

- If the current expression value equals the target, store the expression.
- Otherwise, discard it.

### Step 2: Generate Different Operands

```cpp
for(int j = i; j < num.length(); j++) {
    if(j > i && num[i] == '0') break;

    string part = num.substr(i, j - i + 1);
    long long x = stoll(part);
}
```

We try different lengths of operands starting at index `i`.

For `num = "123"`, starting at index 0, possible operands are:

```text
1
12
123
```

`substr(i, j-i+1)` extracts the current operand.

`stoll(part)` converts the string into a `long long`.

### Step 3: Avoid Leading Zeros

```cpp
if(j > i && num[i] == '0') break;
```

Operands cannot contain leading zeros.

Valid:
- `0`
- `1`
- `12`

Invalid:
- `05`
- `012`

If the first digit is zero, we stop extending that operand.

### Step 4: First Operand

```cpp
if(i == 0) {
    cur += part;

    solve(j + 1, x, x, cur, num, target, ans);

    cur.resize(len);
}
```

The first operand does not require an operator before it.

For example:

```text
num = "123"
```

We can initially choose:
- `1`
- `12`
- `123`

Both `val` and `prev` are initialized to `x`.

After recursion, `cur.resize(len)` restores the expression string to its previous length.

---

## 3. Trying Three Operators

For every operand after the first one, we try addition, subtraction, and multiplication.

### A. Addition (+)

```cpp
cur += "+" + part;

solve(j + 1, val + x, x,
      cur, num, target, ans);

cur.resize(len);
```

For addition:

\[
newValue = val + x
\]

The previous operand becomes the newly added operand.

Example:

```text
1 + 2
```

- `val = 1`
- `x = 2`
- New value = 3
- New previous operand = 2

### B. Subtraction (-)

```cpp
cur += "-" + part;

solve(j + 1, val - x, -x,
      cur, num, target, ans);

cur.resize(len);
```

For subtraction:

\[
newValue = val - x
\]

The previous operand is stored as negative.

Example:

```text
1 - 2
```

- `val = 1`
- `x = 2`
- New value = -1
- New previous operand = -2

Storing the negative value helps us handle multiplication correctly later.

### C. Multiplication (*)

```cpp
cur += "*" + part;

solve(j + 1,
      val - prev + (prev * x),
      prev * x,
      cur, num, target, ans);

cur.resize(len);
```

This is the most important part of the problem.

Multiplication has higher precedence than addition and subtraction.

Consider:

```text
1 + 2 * 3
```

Normal evaluation:

\[
1 + (2 \times 3) = 7
\]

But simple left-to-right evaluation would produce:

\[
(1 + 2) \times 3 = 9
\]

To handle this, we use:

\[
\boxed{newValue = val - prev + (prev \times x)}
\]

Why?

1. Remove the previous operand from the current evaluated value.
2. Multiply the previous operand by the new operand.
3. Add the multiplication result back.

Example:

```text
Expression: 1 + 2 * 3

val = 3
prev = 2
x = 3
```

Calculation:

\[
3 - 2 + (2 \times 3)
\]

\[
= 3 - 2 + 6
\]

\[
= 7
\]

The new previous operand becomes:

\[
prev \times x = 2 \times 3 = 6
\]

This also works with subtraction because we store the previous operand with its sign.

---

## 4. Backtracking Using `resize()`

```cpp
int len = cur.length();
```

Before trying an operator, we save the current expression length.

After the recursive call:

```cpp
cur.resize(len);
```

We restore the expression to its previous state.

For example:

```text
Current expression = "1"
```

We try:

```text
1+2
```

After exploring that branch, we restore:

```text
1
```

Then we can try:

```text
1-2
```

And finally:

```text
1*2
```

This ensures that one recursive branch does not affect another.

---

## 5. Complete C++ Code

```cpp
class Solution {
public:
    // For multiplication:
    // newValue = currentValue - previousOperand
    //            + (previousOperand * newOperand)

    void solve(int i, long long val, long long prev,
               string& cur, string& num, int target,
               vector<string>& ans) {

        if(i == num.length()) {
            if(val == target) {
                ans.push_back(cur);
            }
            return;
        }

        for(int j = i; j < num.length(); j++) {

            // Avoid leading zeros
            if(j > i && num[i] == '0') break;

            string part = num.substr(i, j - i + 1);
            long long x = stoll(part);

            int len = cur.length();

            // First operand: no operator needed
            if(i == 0) {
                cur += part;

                solve(j + 1, x, x, cur, num, target, ans);

                cur.resize(len);
            }
            else {
                // Addition
                cur += "+" + part;

                solve(j + 1, val + x, x,
                      cur, num, target, ans);

                cur.resize(len);

                // Subtraction
                cur += "-" + part;

                solve(j + 1, val - x, -x,
                      cur, num, target, ans);

                cur.resize(len);

                // Multiplication
                cur += "*" + part;

                solve(j + 1,
                      val - prev + (prev * x),
                      prev * x,
                      cur, num, target, ans);

                cur.resize(len);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string cur;

        solve(0, 0, 0, cur, num, target, ans);

        return ans;
    }
};
```

---

## 6. Complexity Analysis

Let `N` be the length of the input string.

**Time Complexity:**

- We can generate different operand lengths at each position.
- For each operand, we can try three operators.
- The number of possible expressions grows exponentially.
- String construction and conversion also take time.

A commonly used upper-bound estimate is:

\[
O(N \cdot 4^N)
\]

**Auxiliary Space Complexity:**

- Recursion depth: O(N)
- Current expression string: O(N)

Therefore:

\[
O(N)
\]

Excluding the output vector.

---

## 7. Important Takeaways

1. Try every possible substring as an operand.
2. Use backtracking to explore `+`, `-`, and `*`.
3. Prevent operands with leading zeros.
4. Track the previous operand to handle multiplication precedence.
5. Restore the expression using `cur.resize(len)` after every recursive call.
6. Use `long long` for intermediate calculations.

### Most Important Formula

\[
\boxed{val - prev + (prev \times x)}
\]

This formula is the key to solving Expression Add Operators using recursion and backtracking.
