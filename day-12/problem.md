# Day 12

## Maximum Size Subarray Sum Equals K

**Difficulty:** Medium
**Pattern:** Prefix Sum + HashMap + Earliest Index

---

## Problem

Given an integer array `nums` and an integer `k`, find the **maximum length of a contiguous subarray** whose sum is exactly `k`.

The array can contain both **positive and negative numbers**.

If no such subarray exists, return `0`.

---

### Example 1

**Input**

```text
nums = [1, -1, 5, -2, 3]
k = 3
```

**Output**

```text
4
```

**Explanation**

The subarray:

```text
[1, -1, 5, -2]
```

has sum:

`1 - 1 + 5 - 2 = 3`

Its length is `4`.

---

### Example 2

**Input**

```text
nums = [-2, -1, 2, 1]
k = 1
```

**Output**

```text
2
```

**Explanation**

The subarray:

```text
[-1, 2]
```

has sum `1` and length `2`.

---

### Example 3

**Input**

```text
nums = [1, 2, 3]
k = 10
```

**Output**

```text
0
```

No contiguous subarray has sum `10`.

---

## Your Attempt First

Before looking at the optimized approach:

1. How would you generate all contiguous subarrays?
2. How would you calculate their sums?
3. How would you keep track of the longest valid one?
4. What would happen when `N` becomes `10⁵`?

Try to identify repeated calculations.

---

## Hint

Think back to **Day 9: Subarray Sum Equals K**.

For a current prefix sum:

```text
currSum
```

If we want a subarray whose sum is `k`:

```text
currSum - previousPrefixSum = k
```

Therefore:

```text
previousPrefixSum = currSum - k
```

What if we have already seen `currSum - k`?

---

## Concept Reveal

Use a HashMap to store:

```text
prefix sum → first index where it occurred
```

At index `i`:

```text
currSum = sum(nums[0...i])
```

If:

```text
currSum - k
```

was previously seen at index `j`, then:

```text
sum(nums[j+1...i]) = k
```

The length of that subarray is:

```text
i - j
```

So we update:

```text
maxLength = max(maxLength, i - j)
```

---

## Why Store the FIRST Occurrence?

This is the key part of today's problem.

Suppose the same prefix sum appears at multiple indices:

```text
prefix sum = 5
```

If we want the **longest** subarray ending at the current index, we want the earliest occurrence.

For example:

```text
5 first appears at index 1
5 appears again at index 4
```

For a current index `8`:

Using index `1`:

```text
8 - 1 = 7
```

Using index `4`:

```text
8 - 4 = 4
```

Therefore, we should **never overwrite the first occurrence**.

---

## Important Difference from Day 9

### Day 9

We wanted to know:

> How many valid subarrays exist?

Therefore, we stored the **frequency** of every prefix sum.

```text
prefix sum → frequency
```

### Day 12

We want to know:

> What is the longest valid subarray?

Therefore, we store the **earliest index**.

```text
prefix sum → first index
```

Same fundamental equation.

Different information stored because the question is different.

---

## Core Implementation

```python
seen = {0: -1}
curr = 0
max_len = 0

for i, num in enumerate(nums):
    curr += num

    if curr - k in seen:
        max_len = max(max_len, i - seen[curr - k])

    if curr not in seen:
        seen[curr] = i

return max_len
```

---

## Why `{0: -1}`?

Consider:

```text
nums = [2, 3]
k = 5
```

At index `1`:

```text
currSum = 5
currSum - k = 0
```

We need to recognize that a prefix sum of `0` existed **before the array started**.

So:

```text
seen = {0: -1}
```

allows:

```text
1 - (-1) = 2
```

which correctly gives the length of `[2, 3]`.

---

## Important Edge Case

### Why can't we simply overwrite the index?

Incorrect:

```python
seen[curr] = i
```

This could destroy the earliest position and therefore prevent us from finding the maximum-length subarray.

Instead:

```python
if curr not in seen:
    seen[curr] = i
```

Store it only the **first time**.

---

## Complexity

**Time:** `O(N)` average

We traverse the array once.

HashMap operations are `O(1)` on average.

**Space:** `O(N)`

In the worst case, every prefix sum can be different.

---

## Pattern to Remember

```text
Current Prefix Sum
        ↓
Need: currSum - k
        ↓
Was it seen before?
        ↓
Yes → valid subarray
        ↓
Use earliest index
        ↓
Maximize length
```

### Core Interview Pattern

**Prefix Sum + HashMap + Earliest Index**

---

## Related LeetCode Practice

### Required

**LeetCode #325 — Maximum Size Subarray Sum Equals K**

Try solving it yourself before looking at the solution.

### Recommended

**LeetCode #560 — Subarray Sum Equals K**

Revisit Day 9 and compare:

```text
Day 9 → store frequency
Day 12 → store earliest index
```

### Optional Challenge

Find the **actual longest subarray**, not just its length.

Return:

```text
start index
end index
maximum length
```

Try modifying the same HashMap approach rather than creating a completely new solution.

---

## µCode Takeaway

The goal is not to memorize:

```text
seen = {0: -1}
```

The goal is to understand:

> **Prefix sums turn a subarray-sum problem into a lookup problem.**

Then the required information in the HashMap depends on what the problem asks:

* **Count** → frequency
* **Longest length** → earliest index
* **Existence** → remember useful previous states
