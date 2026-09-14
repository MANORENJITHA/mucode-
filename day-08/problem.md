# Day 8 — Range Sum Query

**Difficulty:** Easy
**Pattern:** Prefix Sum
**Focus:** Preprocessing + Fast Range Queries

---

## 🧩 Problem

You are given an array of integers.

You will receive multiple queries. For each query, you are given two indices `i` and `j`.

Your task is to find the **sum of all elements from index `i` to index `j`, inclusive**.

The number of queries can be large, so your solution should be efficient.

---

## Input

The first line contains:

```text
N Q
```

where:

* `N` = size of the array
* `Q` = number of queries

The second line contains `N` integers.

The next `Q` lines each contain two integers:

```text
i j
```

representing a query for the sum from index `i` to index `j`.

---

## Output

For each query, print the sum of elements from index `i` to `j`.

---

## Constraints

```text
1 ≤ N ≤ 10^5
1 ≤ Q ≤ 10^5
-10^9 ≤ A[i] ≤ 10^9
0 ≤ i ≤ j < N
```

---

## Example

### Input

```text
5 3
2 4 1 7 3
0 2
1 3
2 4
```

### Output

```text
7
12
11
```

### Explanation

For query `(0, 2)`:

```text
2 + 4 + 1 = 7
```

For query `(1, 3)`:

```text
4 + 1 + 7 = 12
```

For query `(2, 4)`:

```text
1 + 7 + 3 = 11
```

---

## 🤔 Think Before Coding

A straightforward approach would calculate the sum separately for every query.

But imagine:

```text
N = 100,000
Q = 100,000
```

Would calculating every range from scratch be efficient?

### Questions to think about:

* Are we repeatedly calculating the same sums?
* Can we do some work **before** answering the queries?
* Can we store useful information about the array?
* Can every query be answered faster than `O(N)`?

### 💡 Hint

Think about a **prefix sum** array.

If:

```text
nums = [2, 4, 1, 7, 3]
```

can you store the sum of elements from the beginning up to every position?

---

## 🚀 Target

Try to achieve:

```text
Preprocessing: O(N)
Each Query: O(1)
Total: O(N + Q)
```

Be ready to explain **why** your formula works.

---

## 🔗 Related LeetCode Practice

### 🟢 1. Range Sum Query — Immutable

**LeetCode #303**

This is the closest practice problem to today's concept.

Focus on understanding:

> How can one prefix-sum array answer many range-sum queries?

---

### 🟢 2. Find Pivot Index

**LeetCode #724**

**Pattern:** Prefix Sum

This uses the same idea of maintaining information about the sum on the left and comparing it with the sum on the right.

Think:

> "What has already been calculated, and what can I derive from it?"

---

### ⭐ Optional Challenge

### Range Sum Query 2D — Immutable

**LeetCode #304**

Now imagine the array is a **matrix** instead of a 1D array.

Can you extend the prefix-sum idea to answer rectangular region-sum queries efficiently?

This is optional and significantly more challenging.

---

## 🧠 Your Takeaway

Don't memorize:

```text
prefix[j + 1] - prefix[i]
```

Understand **why** subtracting the prefix before `i` leaves exactly the range `i...j`.

The bigger pattern is:

> **Precompute → store useful information → answer repeated queries quickly.**
