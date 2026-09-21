# Day 11

## Continuous Subarray Sum

**Difficulty:** Medium
**Pattern:** Prefix Sum + Modulo + HashMap

### Problem

Given an integer array `nums` and an integer `k`, determine whether there exists a **contiguous subarray of length at least 2** whose sum is a multiple of `k`.

A number is a multiple of `k` if it can be written as:

`k × n`

where `n` is an integer.

Return `True` if such a subarray exists; otherwise, return `False`.

---

### Example 1

**Input**

```text
nums = [23, 2, 4, 6, 7]
k = 6
```

**Output**

```text
True
```

**Explanation**

The subarray `[2, 4]` has sum:

`2 + 4 = 6`

and `6` is a multiple of `6`.

---

### Example 2

**Input**

```text
nums = [23, 2, 6, 4, 7]
k = 6
```

**Output**

```text
True
```

**Explanation**

The subarray `[23, 2, 6, 4, 7]` has sum `42`, which is a multiple of `6`.

There are also smaller valid subarrays such as `[2, 6, 4]`, whose sum is `12`.

---

### Example 3

**Input**

```text
nums = [23, 2, 6, 4, 7]
k = 13
```

**Output**

```text
False
```

---

### Constraints

* `2 ≤ len(nums) ≤ 10⁵`
* `-10⁹ ≤ nums[i] ≤ 10⁹`
* `k ≠ 0`

Your solution should handle large inputs efficiently.

---

## Your Attempt First

Before looking for an optimized solution:

1. How would you generate all contiguous subarrays?
2. How would you calculate their sums?
3. How can you check whether a sum is divisible by `k`?
4. What would the time complexity be?

Think about whether the same work is being repeated.

---

## Hint

Suppose two prefix sums have the **same remainder when divided by `k`**.

For example:

```text
prefix1 % k = r
prefix2 % k = r
```

What can you say about:

```text
prefix2 - prefix1
```

Remember:

`prefix2 - prefix1` is the sum of the subarray between those two positions.

---

## Concept Reveal

The key idea is:

> **If two prefix sums have the same remainder modulo `k`, their difference is divisible by `k`.**

So instead of storing every prefix sum, store:

```text
remainder → earliest index where it appeared
```

For every element:

1. Update the prefix sum.
2. Calculate `prefixSum % k`.
3. If this remainder has appeared before, calculate the distance between the current index and the earliest index.
4. If the distance is at least `2`, we found a valid subarray.
5. Otherwise, store the remainder if it has not appeared before.

### Why store the earliest index?

We need the subarray to contain **at least 2 elements**.

The earliest occurrence gives us the maximum possible subarray length for the current remainder.

So once a remainder is stored, **do not overwrite its index**.

---

## Target Complexity

**Time:** `O(N)` average

**Space:** `O(K)` in terms of distinct remainders, bounded by the number of entries stored.

---

## Core Pattern

```text
Prefix Sum
     ↓
Take modulo K
     ↓
Same remainder?
     ↓
Subarray sum is divisible by K
```

This is an important extension of the prefix-sum pattern from Day 9.

---

## Related LeetCode Practice

### Required

**LeetCode #523 — Continuous Subarray Sum**

Solve the original problem after understanding today's discussion.

### Recommended

**LeetCode #525 — Contiguous Array**

Look for the connection between prefix sums, transformed values, and storing an earliest index.

### Optional Challenge

Modify today's approach to answer:

> What is the **maximum length** subarray whose sum is divisible by `k`?

Do not immediately search for a new algorithm. Try to modify the existing idea.

### What to notice

Today's problem is not just about modulo.

The important interview pattern is:

**Prefix Sum + State Transformation + Earliest Index**
