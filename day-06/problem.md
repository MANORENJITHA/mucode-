# Day 6 — Move Zeroes

**Difficulty:** Easy
**Pattern:** Two Pointers / Write Pointer
**Focus:** In-place Array Manipulation

---

## 🧩 Problem

Given an array of integers, move all `0`s to the **end of the array** while maintaining the **relative order of all non-zero elements**.

The operation must be performed **in-place**.

### Input

* The first line contains an integer `N`, the size of the array.
* The second line contains `N` integers.

### Output

Print the modified array after moving all zeroes to the end.

### Constraints

```text
1 ≤ N ≤ 10^5
-10^9 ≤ A[i] ≤ 10^9
```

---

## Example 1

**Input**

```text
5
0 1 0 3 12
```

**Output**

```text
1 3 12 0 0
```

---

## Example 2

**Input**

```text
5
1 2 3 4 5
```

**Output**

```text
1 2 3 4 5
```

---

## Example 3

**Input**

```text
6
0 0 1 0 2 3
```

**Output**

```text
1 2 3 0 0 0
```

---

## 🎯 Your Task

Try to solve the problem **without using another array**.

Think about:

* Can you solve it with a single traversal?
* Can you modify the array in-place?
* How can you keep track of where the next non-zero element should go?
* Can you achieve **O(N)** time?

### 💡 Hint

Think about two positions:

* One pointer **reads** the array.
* Another pointer **writes** the next non-zero element.

Don't jump directly to the final solution. Try to discover the pattern yourself.

---

## 🚀 Challenge

Can you solve it in:

```text
Time: O(N)
Extra Space: O(1)
```

Be ready to explain **why your approach works**, not just the code.
