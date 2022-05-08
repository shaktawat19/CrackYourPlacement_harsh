class Solution {
public:
void rotate(vector<vector<int>>& matrix) {
// Brute force: O(n*n) Create New empty matrix. Copy 1st row of matrix to last column of new matrix, 2nd row to 2nd last, so on...
  int n = matrix.size();
  vector < vector < int >> rotated(n, vector < int > (n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rotated[j][n - i - 1] = matrix[i][j];
    }
  }
        
 for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
     matrix[i][j] = rotated[i][j];
    }
  }
  

// optimal Approach: 
     // Time Complexity: O(N*N) + O(N*N).One O(N*N) for transposing the matrix and the other for reversing the matrix.
     // Space Complexity: O(1)
   int n = matrix.size();
  //transposing the matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  //reversing each row of the matrix
  for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }


 }
};