#include <stdio.h>

int isSafe(int board[][27], int n, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return 0;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return 0;
        }
    }
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j])
        {
            return 0;
        }
    }
    return 1;
}

void printSolution(int board[][27], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
            {
                printf("Q ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void solveNQueens(int board[][27], int n, int col)
{
    if (col >= n)
    {
        printSolution(board, n);  // Print the solution when a valid one is found
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, n, i, col))
        {
            board[i][col] = 1;   // Place queen
            solveNQueens(board, n, col + 1);  // Recur to place the rest
            board[i][col] = 0;   // Backtrack and remove the queen
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    int board[27][27];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    solveNQueens(board, n, 0);  // Find all solutions
    return 0;
}