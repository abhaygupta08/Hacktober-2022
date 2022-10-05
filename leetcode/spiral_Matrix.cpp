#include <bits/stdc++.h>
using namespace std;

void spiralMatrix(int arr[][3])
{
    int row = 3;
    int col = 3;

    int count = 0;
    int total = row * col;

    int startRow = 0;
    int endRow = row - 1;
    int startCol = 0;
    int endCol = col - 1;

    while (count < total)
    {
        for (int index = startCol; index <= endCol && count < total; index++)
        { // printing starting row
            cout << arr[startRow][index];
            count++;
        }
        startRow++;
        for (int index = startRow; index <= endRow && count < total; index++)
        { // printing ending column
            cout << arr[index][endCol];
            count++;
        }
        endCol--;
        for (int index = endCol; index >= startCol && count < total; index--)
        { // printing ending row
            cout << arr[endRow][index];
            count++;
        }
        endRow--;
        for (int index = endRow; index >= startRow && count < total; index--)
        { // printing starting column
            cout << arr[index][startCol];
            count++;
        }
        startCol++;
    }
}

int main()
{
    int arr[3][3];

    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            cin >> arr[row][col];

    spiralMatrix(arr);
    return 0;
}
