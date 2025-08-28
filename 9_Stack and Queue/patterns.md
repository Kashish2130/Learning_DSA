Here’s the **stack question patterns** you should recognize:

---

### **1. Next / Previous Greater or Smaller Element**

* **Core idea:** Use a **monotonic stack** to find the next or previous element that is greater/smaller than the current one.
* **Examples:**

  * Next Greater Element I, II
  * Previous Smaller Element
  * Stock Span Problem
  * Daily Temperatures
* **Pattern trick:** Traverse array from one end, keep stack of indexes/elements in increasing or decreasing order.

---

### **2. Histogram / Range-based Problems** -- not done yet

* **Core idea:** Use stack to find **first smaller element on left and right** to determine ranges.
* **Examples:**

  * Largest Rectangle in Histogram
  * Maximal Rectangle in a binary matrix
* **Pattern trick:** Precompute boundaries using **monotonic stacks**.

---

### **3. Balanced Parentheses / Expression Validation**

* **Core idea:** Push opening brackets to stack, pop when a matching closing bracket is found.
* **Examples:**

  * Valid Parentheses
  * Minimum Add/Remove to Make Parentheses Valid
  * Remove Invalid Parentheses
* **Pattern trick:** Sometimes you track **indexes** instead of chars to help remove invalid ones.

---

### **4. Infix / Postfix / Prefix Conversions & Evaluation**

* **Core idea:** Stack is perfect for expression evaluation.
* **Examples:**

  * Infix to Postfix conversion
  * Evaluate Reverse Polish Notation (Postfix Evaluation)
* **Pattern trick:** Use two stacks — one for operators, one for operands — or a single operand stack if expression is already postfix/prefix.

---

### **5. Min / Max Stack (Supporting O(1) min/max retrieval)**

* **Core idea:** Use an **auxiliary stack** or store extra info in each node to keep track of min/max.
* **Examples:**

  * Min Stack
  * Max Stack
* **Pattern trick:** Push `(value, currentMin)` pair.

---

### **6. Stack Simulation Problems** - not done yet
 
* **Core idea:** Simulate behavior of undo/redo or text editors using stack.
* **Examples:**

  * Backspace String Compare
  * Browser History
* **Pattern trick:** Two stacks can simulate forward/back operations.

---

### **7. Two-Stack Problems / Stack using Queue**

* **Core idea:** Implement one data structure using stack(s) or vice versa.
* **Examples:**

  * Implement Queue using Stacks
  * Implement Stack using Queues
* **Pattern trick:** Focus is on **amortized analysis**.

---

### **8. Monotonic Stack for Trapping / Boundaries**

* **Core idea:** Find boundaries to solve water, gas, or skyline problems.
* **Examples:**

  * Trapping Rain Water
  * Sum of Subarray Minimums
  * Sum of Subarray Maximums

---

If you’ve done Striver’s stack section, you’ve already seen **most patterns from #1 to #4** and parts of #8.
The missing ones might be **Min Stack (#5)** and **expression-based problems (#4)**, which are also interview favorites.

---

If you want, I can make you a **flowchart** that helps you decide *which stack pattern applies to a question* just by looking at it. That way you won’t need to “guess” during contests.
