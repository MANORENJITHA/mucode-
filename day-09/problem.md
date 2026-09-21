# Day 9 — Subarray Sum Equals K

**Difficulty:** Medium
**Pattern:** Prefix Sum + HashMap
**Focus:** Counting Subarrays Efficiently

---

## 🧩 Problem

Given an array of integers `nums` and an integer `K`, find the **number of contiguous subarrays** whose sum is exactly `K`.

The array may contain **positive numbers, negative numbers, and zeroes**.

---

## What is a Subarray?

A subarray is a **contiguous** part of an array.

For:

```text
[1, 2, 3]
```

Some valid subarrays are:

```text
[1]
[2]
[3]
[1, 2]
[2, 3]
[1, 2, 3]
```

But:

```text
[1, 3]
```

is **not** a subarray because the elements are not contiguous.

---

## Input

The first line contains:

```text
N K
```

The second line contains `N` integers.

## Output

Print the number of subarrays whose sum is exactly `K`.

---

## Constraints

```text
1 ≤ N ≤ 10^5
-10^9 ≤ nums[i] ≤ 10^9
-10^14 ≤ K ≤ 10^14
```

---

## Example 1

### Input

```text
5 3
1 2 1 1 1
```

### Output

```text
3
```

The valid subarrays are:

```text
[1, 2]
[2, 1]
[1, 1, 1]
```

---

## Example 2

### Input

```text
5 0
1 -1 1 -1 1
```

### Output

```text
6
```

Notice that **negative numbers are allowed**.

---

## Example 3

### Input

```text
4 5
5 -2 2 3
```

### Output

```text
2
```

Valid subarrays:

```text
[5]
[-2, 2, 3]
```

---

# 🧠 Your Attempt First

Before looking for the optimal approach, try solving it yourself.

### Step 1 — Brute Force

Can you generate every possible subarray and calculate its sum?

Try to achieve:

```text
O(N²)
```

rather than using three nested loops.

### Step 2 — Look for Repeated Work

Ask yourself:

> "Am I calculating the same sums again and again?"

Can previously calculated information help?

### Step 3 — Think About Prefix Sums

If:

```text
currentPrefixSum
```

is the sum up to the current position, what would need to have appeared earlier for a subarray to have sum `K`?

Think about:

```text
currentPrefixSum - previousPrefixSum = K
```

---

# 💡 Concept Reveal

The key observation is:

```text
currentPrefixSum - previousPrefixSum = K
```

Rearranging:

```text
previousPrefixSum = currentPrefixSum - K
```

So at every position, we ask:

> **"How many times have I already seen `currentPrefixSum - K`?"**

We can store prefix sums and their frequencies in a **HashMap**.

This gives:

```text
Time: O(N)
Space: O(N)
```

---

# 🔥 The Pattern

The powerful combination is:

```text
Prefix Sum + HashMap
```

The prefix sum helps us represent subarray sums.

The HashMap lets us quickly find how many previous prefix sums can form the required sum.

---

# 🚀 Challenge

After solving this problem, try to answer:

> How would you modify the approach to find the **longest** subarray whose sum is `K`, instead of counting how many exist?

Don't look for the solution immediately.

Think about what information the HashMap would need to store differently.
