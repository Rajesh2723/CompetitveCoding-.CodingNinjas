/*
You have been given a 9 X 9 2D matrix 'MATRIX' with some cells filled with digits(1 - 9), and some empty cells (denoted by 0).
You need to find whether there exists a way to fill all the empty cells with some digit(1 - 9) such that the final matrix is a valid Sudoku solution.
  1. Each of the digits 1 - 9 must occur exactly once in each row.
2. Each of the digits 1 - 9 must occur exactly once in each column.
3. Each of the digits 1 - 9 must occur exactly once in each of the 9, 3 x 3 sub-matrices of the matrix.
  1. There will always be a cell in the matrix which is empty.
2. The given initial matrix will always be consistent according to the rules mentioned in the problem statement.
1
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6

  Explanation of the Sample Input1:
One of the possible solutions is:
9 4 1 3 2 6 7 5 8
6 3 7 1 5 8 2 4 9
8 2 5 4 9 7 6 1 3
2 6 8 7 1 4 3 9 5
1 7 4 5 3 9 8 6 2
3 5 9 6 8 2 4 7 1
4 1 3 2 6 5 9 8 7
5 9 6 8 7 3 1 2 4
7 8 2 9 4 1 5 3 6
*/
bool isPossible(int matrix[9][9] ,int row ,int col , int num)

{

     for(int i=0;i<9;i++)

     {

         if(matrix[row][i]==num)

         {

             return false;

         }

         if(matrix[i][col]==num)

         {

             return false;

         }

         if(matrix[3*(row/3)+i/3][3*(col/3)+i%3]==num) /The purpose of this specific code snippet is to check if the same number num exists in the 3x3 subgrid (also known as a box or block) that contains the cell (row, col)

         {

             return false;

         }

     }

     return true;

}

bool Solve(int matrix[9][9])

{

    //find next empty 

    for(int i=0;i<9;i++)

    {

        for(int j=0;j<9;j++)

        {

            if(matrix[i][j]==0)

            {

              for (int num = 1; num <= 9; num++)

              {

 

                if (isPossible(matrix , i ,j,num))

                {

                   matrix[i][j]=num;

                   if(Solve(matrix))

                   {

                       return true;

                   } 

                   else 

                    {

                       matrix[i][j]=0;

                    }

                }

              }

               return false;

            }

           

        }

    } 

 

    return true;

 

}

bool isItSudoku(int matrix[9][9]) {

    if(Solve(matrix))

    {

        return true;

    }

    return false;

   

}

 /*
The expression 3*(row/3)+i/3 calculates the row index within the 3x3 subgrid, and 3*(col/3)+i%3 calculates the column index within the 3x3 subgrid. The variable i is likely a loop variable ranging from 0 to 8, iterating over all the cells within the 3x3 subgrid.
   Here's a step-by-step explanation:

    row/3 and col/3: These divisions by 3 determine which 3x3 subgrid the cell (row, col) belongs to. It essentially maps each 3x3 subgrid to a unique value.

    3*(row/3)+i/3: This expression calculates the row index within the 3x3 subgrid. It combines the information about the 3x3 subgrid and the loop variable i to determine the row within that subgrid.

    3*(col/3)+i%3: This expression calculates the column index within the 3x3 subgrid in a similar manner.

    matrix[3*(row/3)+i/3][3*(col/3)+i%3]: This accesses the value in the cell within the 3x3 subgrid specified by the calculated row and column indices.

    ==num: This checks if the value in the selected cell is equal to the number num.
   */
/*
bool isValid(int matrix[9][9], int row, int col, int k) {
  for (int i = 0; i < 9; i++) {
    if (matrix[row][i] == k) {
      return false;
    }
    if (matrix[i][col] == k) {
      return false;
    }
    if (matrix[3 * (row/3) + i / 3][3 * (col/3) + i % 3] == k){
        return false;
    }
  }

  return true;
}

bool isItSudoku(int matrix[9][9]) {
  // Write your code here.
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (matrix[i][j] == 0) {
        for (int k = 1; k <= 9; k++) {
          if (isValid(matrix, i, j, k)) {
            matrix[i][j] = k;

            if (isItSudoku(matrix)) {
              return true;
            } else {
              matrix[i][j] = 0;
            }
          }
        }

        return false;
      }
    }
  }

  return true;
}
*/

