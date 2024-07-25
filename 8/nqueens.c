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

int solveNQueens(int board[][27], int n, int col)
{
    if (col >= n)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, n, i, col))
        {
            board[i][col] = 1;
            if (solveNQueens(board, n, col + 1))
            {
                return 1;
            }
            board[i][col] = 0;
        }
    }
    return 0;
}

void printSolution(int board[][27], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
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
    if (solveNQueens(board, n, 0))
    {
        printSolution(board, n);
    }
    else
    {
        printf("Solution does not exist\n");
    }
    return 0;
}