/*
SUDOKU SOLVER
// Time ->O(9^(n*n))
*/

#include <bits/stdc++.h>
using namespace std;

bool check(int mat[9][9], int no, int i, int j)
{
    // checking row and column
    for (int k = 0; k < 9; k++)
    {
        if (mat[i][k] == no || mat[k][j] == no)
        {
            return false;
        }
    }
    // checking 3x3 subgrid
    int si = i - i % 3;
    int sj = j - j % 3;
    for (int i = si; i < si + 3; i++)
    {
        for (int j = sj; j < sj + 3; j++)
        {
            if (mat[i][j] == no)
            {
                return false;
            }
        }
    }
    return true;
}
bool solve(int matrix[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int no = 1; no <= 9; no++)
                {
                    if (check(matrix, no, i, j))
                    {
                        matrix[i][j] = no;
                        if (solve(matrix) == true)
                            return true;
                        else
                            matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9])
{
    // Write your code here.
    if (solve(matrix) == true)
    {
        return true;
    }
    return false;
}
void printGrid(vector<vector<int>> &grid)
{
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid.size(); col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

int main()
{

    vector<vector<int>> grid{{3, 0, 6, 5, 0, 8, 4, 0, 0},
                             {5, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 8, 7, 0, 0, 0, 0, 3, 1},
                             {0, 0, 3, 0, 1, 0, 0, 8, 0},
                             {9, 0, 0, 8, 6, 3, 0, 0, 5},
                             {0, 5, 0, 0, 9, 0, 6, 0, 0},
                             {1, 3, 0, 0, 0, 0, 2, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 7, 4},
                             {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    // printGrid(grid);
    if (solve(grid) == true)
        printGrid(grid);
    else
        cout << "No solution exists";

    return 0;
}
