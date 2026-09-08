# 🟢 MuCode — Day 5

## Product of Array Except Self

Given an integer array `nums`, return an array `answer` such that:

`answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

### ⚠️ Important

You **must not use the division operator**.

Try to solve the problem in **O(N)** time.

---

## 📥 Input Format

* The first line contains an integer `N`, the size of the array.
* The second line contains `N` space-separated integers representing the array.

## 📤 Output Format

Print `N` space-separated integers representing the resulting array.

---

## 📌 Constraints

* `2 ≤ N ≤ 10⁵`
* `-30 ≤ nums[i] ≤ 30`

---

## 🧪 Examples

### Example 1

**Input**

```text
4
1 2 3 4
```

**Output**

```text
24 12 8 6
```

### Example 2

**Input**

```text
4
-1 1 0 -3
```

**Output**

```text
0 0 3 0
```

### Example 3

**Input**

```text
3
2 3 4
```

**Output**

```text
12 8 6
```

---

## 💭 Your Attempt First

Before looking for a solution, think about:

> What does `answer[i]` depend on?

It depends on:

* Everything to the **left** of `i`
* Everything to the **right** of `i`

Can you calculate these separately?

### Questions to think about

1. Can you solve it using a straightforward approach?
2. Why is division not allowed?
3. Can you avoid recalculating products?
4. Can you achieve **O(N)** time?
5. Can you do it with **O(1) extra space**, excluding the output array?

---

## 🎯 Challenge

Try to solve this without:

* Using division
* Using nested loops
* Creating separate prefix and suffix arrays

Give it a genuine attempt before tomorrow's mentor discussion.

**Don't worry if you can't find the optimal solution — the goal is to understand the thinking process.**

---

### 🔗 Reference

Inspired by **LeetCode 238 — Product of Array Except Self**.
