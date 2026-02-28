--------Removing Digit--------

Q.Problem Statement

Given a number `n`, you can repeatedly remove one of its non-zero digits.
Your task is to find the **minimum number of steps** required to reduce the number to `0`.

Example:

Input:27

Output:5

Explanation: 27 → 20 → 18 → 10 → 9 → 0

## 🚀 Approaches Used

### 1️⃣ Recursive Method

* Try subtracting each digit.
* Take the minimum steps.
* Slower for large inputs (exponential complexity).

### 2️⃣ Tabulation (Dynamic Programming)

* Build solution from `0` to `n`.
* Efficient for large inputs.
* Time Complexity: **O(n × digits)**

---

## 🧠 Concepts Used

* Dynamic Programming (DP)
* Recursion
* Tabulation (Bottom-Up)
* Vectors
* Digit Extraction
----
Time Complexity: O(n × d)

Where d = number of digits (≤ 6 for n ≤ 10⁶)

So practical complexity ≈ O(n log n)

Space Complexity: O(n)
                  ----
## ⭐ Learning Outcome

* Understanding DP state transitions
* Converting recursion to tabulation
* Optimizing brute force solutions
