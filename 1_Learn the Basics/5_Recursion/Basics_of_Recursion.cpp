#include<bits/stdc++.h>
using namespace std;

void printNameUsingRecursion(int i, int n) {
    if (i > n) {
        return;
    }
    cout << "kashish\n";  // Print "kashish" and move to the next line
    printNameUsingRecursion(i + 1, n);
}

void print1toN(int i, int n) {
    if (i > n) {
        return;
    }
    cout << i << " ";  // Print numbers in the same line separated by space
    print1toN(i + 1, n);
}

void printNto1(int n, int i) {
    if (n < i) {
        return;
    }
    cout << n << " ";  // Print numbers in the same line separated by space
    printNto1(n - 1, i);
}

void print1toNBackTracking(int i, int n) {
    if (i < 1) {
        return;
    }
    print1toNBackTracking(i - 1, n);
    cout << i << " ";  // Print numbers in the same line after backtracking
}

void printNto1BackTracking(int i, int n) {
    if (n > i) {
        return;
    }
    printNto1BackTracking(i, n + 1);
    cout << n << " ";  // Print numbers in the same line after backtracking
}

int main() {
    int n;
    cin >> n;

    // Print name `n` times
    cout << "Printing name using recursion:\n";
    printNameUsingRecursion(1, n);

    // Print numbers from 1 to n
    cout << "\n\nPrinting 1 to N:\n";
    print1toN(1, n);
    cout << "\n";

    // Print numbers from n to 1
    cout << "\nPrinting N to 1:\n";
    printNto1(n, 1);
    cout << "\n";

    // Print numbers from 1 to n using backtracking
    cout << "\nPrinting 1 to N using backtracking:\n";
    print1toNBackTracking(n, n);
    cout << "\n";

    // Print numbers from n to 1 using backtracking
    cout << "\nPrinting N to 1 using backtracking:\n";
    printNto1BackTracking(n, 1);
    cout << "\n";

    return 0;
}
