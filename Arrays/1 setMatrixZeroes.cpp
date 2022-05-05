void setZeroes(vector<vector<int>> &matrix)
{
     int rows = matrix.size(), cols = matrix[0].size();
     // Approach 1: if elems are not -ve then make  respective rows n cols to -1, n then to 0 finally.

     // Approach 2: use two dummy arrays
       vector < int > dummy1(rows,-1), dummy2(cols,-1);
       for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++) {
           if (matrix[i][j] == 0) {
             dummy1[i] = 0;
             dummy2[j] = 0;
           }
         }
       }
       for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++) {
           if (dummy1[i] == 0 || dummy2[j]==0) {
             matrix[i][j] = 0;
           }
         }
       }

     // optimised Approach 3: use 0th row n 0th col, instead of extra arrays.
     int col0 = 1;
     for (int i = 0; i < rows; i++)
     {
          // checking if 0 is present in the 0th column or not
          if (matrix[i][0] == 0)
               col0 = 0;
          for (int j = 1; j < cols; j++)
          {
               if (matrix[i][j] == 0)
               {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
               }
          }
     }
     // traversing in the reverse direction and
     // checking if the row or col has 0 or not
     // and setting values of matrix accordingly.
     for (int i = rows - 1; i >= 0; i--)
     {
          for (int j = cols - 1; j >= 1; j--)
          {
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
               {
                    matrix[i][j] = 0;
               }
          }
          if (col0 == 0)
          {
               matrix[i][0] = 0;
          }
     }
}