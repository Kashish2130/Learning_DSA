### 5 ways to solve any recursive problems :
    1. what is the simplest possible input?
    2. play around with examples and visualize.
    3. related hard cases to simpler cases
    4. generalize the pattern
    5. write code by combining recursive pattern with base case.

### how code works?
### Recursive leap of faith

### View Resource : https://youtu.be/ngCos392W4w?si=rJlpaKW2wbQxrTkp

### How to identify time complexity in recursive approaches?
1. Single recursive call reducing input by 1 → O(n)
    ```void recurse(int n) {
    if (n == 0) return;
    recurse(n - 1);  // one call
}```

2. Two recursive calls → T(n) = 2T(n-1) → Exponential O(2^n)
    ```void fib(int n) {
    if (n <= 1) return;
    fib(n-1);
    fib(n-2);
}```

3. Divide and Conquer (e.g., Merge Sort): T(n) = 2T(n/2) + O(n) → O(n log n)
