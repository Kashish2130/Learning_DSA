## ✅ **General Approach for Solving Backtracking Questions**

### 1. **Understand the Problem**

* Identify the **goal**: Do you need all solutions, one valid solution, or just a count?
* Check constraints: size of input, uniqueness, range, etc.

---

### 2. **Define the Decision Space**

* What are the **choices** at each step?
* What's the **base case** (when to stop)?
* What's the **recursive case** (how to explore further)?

---

### 3. **Backtracking Template (Standard DFS Style)**

```cpp
void backtrack(parameters) {
    if (base condition) {
        // Save/print the solution
        return;
    }

    for (each choice) {
        if (isValid(choice)) {
            // Make the move
            choose(choice);

            // Recurse
            backtrack(updated parameters);

            // Undo the move (backtrack)
            unchoose(choice);
        }
    }
}
```

---

## 🧠 Think in These Terms:

* **State**: current position or situation.
* **Choices**: possible moves from the current state.
* **Constraints**: conditions that must be satisfied.
* **Goal**: when to stop and save a result.

---

## 🛠️ Common Techniques

| Problem Type                          | Backtracking Strategy                    |
| ------------------------------------- | ---------------------------------------- |
| **Subsets**                     | Include/exclude current element          |
| **Permutations**                | Use a visited\[] array                   |
| **Combinations**                | Start from index `i`, avoid duplicates |
| **Sudoku / N-Queens**           | Try all placements with constraints      |
| **Word Search / Grid Problems** | DFS with visited marking                 |
| **Palindrome Partitioning**     | Recurse on valid partitions              |

---

## 🔁 Optimization Tips

* **Prune early** (skip invalid choices early).
* **Use hashing/boolean arrays** to avoid revisits.
* **Sort input** to handle duplicates.
* **Memoization** if overlapping subproblems exist.

---

## 🧩 Practice Examples

| Problem                               | Type                    |
| ------------------------------------- | ----------------------- |
| Subsets / Subsets II (Leetcode 78/90) | Subset Generation       |
| Permutations (Leetcode 46)            | Permutation             |
| Combination Sum (Leetcode 39/40)      | Combination             |
| N-Queens (Leetcode 51)                | Grid + Constraint       |
| Sudoku Solver (Leetcode 37)           | Constraint Satisfaction |
