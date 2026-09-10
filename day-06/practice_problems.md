## 🔗 Practice Problems

Finished the main problem? Don't stop there.

Try these **LeetCode problems using the same/similar pointer and in-place array patterns**:

### 🟢 1. Remove Duplicates from Sorted Array — LeetCode #26

**Pattern:** Write Pointer / Two Pointers

Given a sorted array, remove the duplicates **in-place** so that each unique element appears only once.

**Why this is related:**
Instead of writing every non-zero element like in Move Zeroes, you'll write only the **next unique element**.

> Think: **What should my `write` pointer represent?**

---

### 🟢 2. Remove Element — LeetCode #27

**Pattern:** Write Pointer / In-Place Array Modification

Given an array and a value `val`, remove all occurrences of `val` **in-place**.

**Why this is related:**
This is almost the same thought process as Move Zeroes:

```text
Scan → decide whether the element is valid → write it → move write pointer
```

> Think: **What changes if the element we want to ignore isn't always 0?**

---

### ⭐ Optional Challenge

Try solving both problems **without looking at the solution**.

For each one, be able to explain:

1. What does the `write` pointer represent?
2. When does it move?
3. Why is the relative order preserved?
4. What is the time complexity?
5. What is the extra space complexity?

**Don't just submit the code. Understand the pattern.**
