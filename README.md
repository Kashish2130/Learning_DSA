# Learning_DSA

[Link TO Striver's Sheet](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2)

#### NOTE: All the codes from step 3 are incomplete, they are just fucntions which contains the main logic so to run the function you need to write the entire code which is required to run the program.

# BREAK AND CONTINUE

## Example 1: continue in the inner loop

``for (int i = 0; i < 3; i++) {
    cout << "Outer loop i = " << i << endl;
    for (int j = 0; j < 3; j++) {
        if (j == 1) continue;
        cout << "  Inner loop j = " << j << endl;
    }
}``

## Output:

``Outer loop i = 0
  Inner loop j = 0
  Inner loop j = 2
Outer loop i = 1
  Inner loop j = 0
  Inner loop j = 2
Outer loop i = 2
  Inner loop j = 0
  Inner loop j = 2``

## Example 2: break in the inner loop

``for (int i = 0; i < 3; i++) {
    cout << "Outer loop i = " << i << endl;
    for (int j = 0; j < 3; j++) {
        if (j == 1) break;
        cout << "  Inner loop j = " << j << endl;
    }
}``

## Output:

``Outer loop i = 0
  Inner loop j = 0
Outer loop i = 1
  Inner loop j = 0
Outer loop i = 2
  Inner loop j = 0``

## Example 3: break in inner loop with condition

``for (int i = 0; i < 3; i++) {
    cout << "Outer i = " << i << endl;
    for (int j = 0; j < 3; j++) {
        if (i == 1 && j == 1) break;
        cout << "  Inner j = " << j << endl;
    }
}``

## Output:

``Outer i = 0
  Inner j = 0
  Inner j = 1
  Inner j = 2
Outer i = 1
  Inner j = 0
Outer i = 2
  Inner j = 0
  Inner j = 1
  Inner j = 2``

## Example 4: continue in inner loop with condition

``for (int i = 0; i < 3; i++) {
    cout << "Outer i = " << i << endl;
    for (int j = 0; j < 3; j++) {
        if (i == 1 && j == 1) continue;
        cout << "  Inner j = " << j << endl;
    }
}``

## Output:

``Outer i = 0
  Inner j = 0
  Inner j = 1
  Inner j = 2
Outer i = 1
  Inner j = 0
  Inner j = 2
Outer i = 2
  Inner j = 0
  Inner j = 1
  Inner j = 2``