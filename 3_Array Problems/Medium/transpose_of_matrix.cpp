//tranpose of a matrix

#include <vector>
using namespace std;        
void transposeMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    // Transpose the matrix in place
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < m; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

