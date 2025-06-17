//brute force solution
//tc : O(n*m) = n^2
//sc : O(n*m) = n^2 -> where n is the number of rows and m is the number of columns
// This code rotates a square matrix 90 degrees clockwise.

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();

        vector<vector<int>> matrix2(colsize, vector<int>(rowsize));
        int temp = rowsize - 1;

        for (int row = 0; row < rowsize; row++)
        {
            for (int col = 0; col < colsize; col++)
            {
                matrix2[col][temp] = matrix[row][col];
            }
            temp--;       // Decrease temp after processing each row
        }
        matrix = matrix2; // Assign the rotated matrix back to the original matrix
    }
};

//optimal approach
//tc : O(n*m) = n^2
//sc : O(1) -> in place rotation

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();

        for (int row = rowsize - 1; row >= 0; row--) {
            for (int col = row - 1; col >= 0; col--) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        for (int i = 0; i < rowsize; i++) {
           reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

//is this code correct?



