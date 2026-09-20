# Day 10 — Find Pivot Index

**Difficulty:** Easy
**Pattern:** Prefix Sum / Running Sum
**Focus:** Left Sum vs Right Sum

---

## 🧩 Problem

Given an integer array `nums`, find the **leftmost pivot index**.

A pivot index is an index where:

> The sum of all elements strictly to the **left** equals the sum of all elements strictly to the **right**.

The pivot element itself is **not included** in either sum.

If no pivot index exists, return `-1`.

---

## Example 1

### Input

```text
6
1 7 3 6 5 6
```

### Output

```text
3
```

### Explanation

At index `3`:

```text
Left:
1 + 7 + 3 = 11

Right:
5 + 6 = 11
```

Therefore, index `3` is a pivot index.

---

## Example 2

### Input

```text
3
1 2 3
```

### Output

```text
-1
```

There is no index where the left sum equals the right sum.

---

## Example 3

### Input

```text
3
2 1 -1
```

### Output

```text
0
```

At index `0`:

```text
Left = 0
Right = 1 + (-1) = 0
```

So index `0` is a valid pivot.

---

## Constraints

```text
1 ≤ N ≤ 10^5
-10^9 ≤ nums[i] ≤ 10^9
```

---

# 🤔 Your Attempt First

Before looking at the concept reveal, try to solve it.

### Think about the obvious approach

For every index:

1. Calculate the sum on the left.
2. Calculate the sum on the right.
3. Compare them.

What would the time complexity be if you repeatedly calculated these sums?

Can you do better?

---

# 💡 Concept Reveal

First calculate the **total sum** of the array.

Then maintain a running:

```text
leftSum
```

At index `i`:

```text
rightSum = totalSum - leftSum - nums[i]
```

Why?

Because:

```text
Total = Left + Current + Right
```

Therefore:

```text
Right = Total - Left - Current
```

Now simply check:

```text
leftSum == rightSum
```

If true, we found the pivot.

---

## 🚀 Target

Try to achieve:

```text
Time: O(N)
Extra Space: O(1)
```

---

## 🔗 Related LeetCode Practice

### 🟢 1. Find Pivot Index — LeetCode #724

Solve the original problem independently after the session.

Focus on understanding the relationship between:

```text
Total Sum
Left Sum
Current Element
Right Sum
```

---

### 🟢 2. Left and Right Sum Differences — LeetCode #2574

Given an array, calculate the absolute difference between:

```text
sum of elements to the left
```

and

```text
sum of elements to the right
```

**Why it's related:**

It uses the same idea of maintaining left/right information efficiently.

---

### ⭐ Optional Challenge

Try to solve the problem **without explicitly creating a prefix-sum array**.

Ask yourself:

> "Do I actually need to store every prefix sum?"

Can a single running variable be enough?

---

## 🧠 Pattern to Remember

When you see:

> "Compare the sum on the left with the sum on the right"

think:

```text
Total Sum
     ↓
Maintain Left Sum
     ↓
Right = Total - Left - Current
     ↓
Compare Left and Right
```

Sometimes you don't need to build a complete prefix array.

**A running prefix value is enough.**
