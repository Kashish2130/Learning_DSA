//! better approach(1)(own)
// tc : O(m * n * (m + n))
// sc: O(k) where k is the number of zeros in the matrix
// sc : o(m*n) in worst case

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> zeros;

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeros.push_back({i, j});
                }
            }
        }

        for (auto &pos : zeros)
        {
            int row = pos.first;
            int col = pos.second;

            for (int i = 0; i < n; i++)
            {
                matrix[row][i] = 0;
            }

            for (int i = 0; i < m; i++)
            {
                matrix[i][col] = 0;
            }
        }
    }
};

//! better approach(2)
// tc : O(2* m * n)
// sc: O(m + n) where m is the number of rows and n is the number of columns

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] || col[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//! optimal approach
// tc : O(m * n)
// sc: O(1) (in-place modification of the matrix)

//example matrix: {{1,0,2,9},{20,8,13,7},{0,6,5,19},{21,3,0,7}}
//what will be the output: {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,3,0,7}}
//how 3 will not be zeroed out? because it is not in the same row or column as a zero.
//explanation:
// We will use the first row and first column of the matrix to mark which rows and columns should be set to zero.   
// The first row and first column will be used as markers, so we need to handle them separately at the end.
// We will also use a boolean variable to track if the first column should be set to zero.
// We will iterate through the matrix, marking the first row and first column for any zeros found.
// Then, we will iterate through the matrix again, setting the cells to zero based on the markers.
// Finally, we will handle the first row and first column separately based on the markers.
// Note: This approach modifies the input matrix in place, so no additional space is used for storing the markers.
// This solution is efficient and works in O(m * n) time complexity with O(1) space complexity.


class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        bool col0 = false;

        // First pass: mark zeros in first row and column
        for (int row = 0; row < rowSize; row++)
        {
            if (matrix[row][0] == 0)
                col0 = true;
            for (int col = 1; col < colSize; col++)
            {
                if (matrix[row][col] == 0)
                {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0; 
                }
            }
        }

        // Second pass: set matrix cells to zero using markers
        for (int row = 1; row < rowSize; row++)
        {
            for (int col = 1; col < colSize; col++)
            {
                if (matrix[row][0] == 0 || matrix[0][col] == 0)
                {
                    matrix[row][col] = 0;
                }
            }
        }

        // Handle first row
        if (matrix[0][0] == 0)
        {
            for (int col = 0; col < colSize; col++)
            {
                matrix[0][col] = 0;
            }
        }

        // Handle first column
        if (col0)
        {
            for (int row = 0; row < rowSize; row++)
            {
                matrix[row][0] = 0;
            }
        }
    }
};