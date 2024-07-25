#include <stdio.h>
#include <stdlib.h>

// Assignment Problem
/*
An assignment problem is a particular case of transportation problem. The objective is to assign a number of resources to an equal number of activities . So as to minimize total cost or maximize total profit of allocation*/

// The Hungarian method is a combinatorial optimization algorithm that solves the assignment problem in polynomial time. It was developed and published by Harold Kuhn in 1955, who gave the name "Hungarian method" because the algorithm was largely based on the earlier works of two Hungarian mathematicians: Dénes Kőnig and Jenő Egerváry.

// The Hungarian method is used to solve the assignment problem, which is a special case of the transportation problem. In the assignment problem, we have a set of resources and a set of activities, and we want to assign each resource to exactly one activity in such a way that the total cost or profit is minimized or maximized.

// The Hungarian method works by constructing a cost matrix that represents the cost of assigning each resource to each activity. The algorithm then finds the optimal assignment by iteratively reducing the cost matrix until an optimal assignment is found.

// The Hungarian method is guaranteed to find the optimal assignment for any instance of the assignment problem, and it runs in polynomial time, making it an efficient algorithm for solving this type of problem.

// In this program, we implement the Hungarian method to solve the assignment problem. The program takes a cost matrix as input and finds the optimal assignment of resources to activities that minimizes the total cost.

#define N 4

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}};

int rowCovered[N] = {0};

int colCovered[N] = {0};

int assignment[N][2] = {0};

int n = N;

void printAssignment()
{
    printf("Assignment:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Resource %d -> Activity %d\n", assignment[i][0], assignment[i][1]);
    }
}

int findUncoveredZero(int *row, int *col)
{
    for (int i = 0; i < n; i++)
    {
        if (!rowCovered[i])
        {
            for (int j = 0; j < n; j++)
            {
                if (!colCovered[j] && costMatrix[i][j] == 0)
                {
                    *row = i;
                    *col = j;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int findStarInRow(int row)
{
    for (int j = 0; j < n; j++)
    {
        if (assignment[j][0] == row && assignment[j][1] == 1)
        {
            return j;
        }
    }
    return -1;
}

int findStarInCol(int col)
{
    for (int i = 0; i < n; i++)
    {
        if (assignment[i][1] == col && assignment[i][1] == 1)
        {
            return i;
        }
    }
    return -1;
}

int findPrimeInRow(int row)
{
    for (int j = 0; j < n; j++)
    {
        if (assignment[j][0] == row && assignment[j][1] == 2)
        {
            return j;
        }
    }
    return -1;
}

void clearCovers()
{
    for (int i = 0; i < n; i++)
    {
        rowCovered[i] = 0;
        colCovered[i] = 0;
    }
}




void erasePrimes()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (assignment[i][0] == 2)
            {
                assignment[i][0] = 0;
            }
        }
    }
}

void step1()
{
    for (int i = 0; i < n; i++)
    {
        int min = costMatrix[i][0];
        for (int j = 1; j < n; j++)
        {
            if (costMatrix[i][j] < min)
            {
                min = costMatrix[i][j];
            }
        }
        for (int j = 0; j < n; j++)
        {
            costMatrix[i][j] -= min;
        }
    }
}

void step2()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (costMatrix[i][j] == 0 && !rowCovered[i] && !colCovered[j])
            {
                assignment[i][0] = 1;
                assignment[i][1] = 1;
                rowCovered[i] = 1;
                colCovered[j] = 1;
                break;
            }
        }
    }
    clearCovers();
}

void step3()
{
    int row = -1;
    int col = -1;
    while (findUncoveredZero(&row, &col))
    {
        assignment[row][0] = 2;
        assignment[row][1] = 0;
        int starCol = findStarInRow(row);
        if (starCol != -1)
        {
            rowCovered[row] = 1;
            colCovered[starCol] = 0;
        }
        else
        {
            assignment[row][0] = 3;
            assignment[row][1] = col;
            int starRow = findStarInCol(col);
            if (starRow != -1)
            {
                rowCovered[starRow] = 0;
                colCovered[col] = 1;
            }
            else
            {
                assignment[row][0] = 4;
                assignment[row][1] = col;
                return;
            }
        }
    }
}

void step4()
{
    int min = 9999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!rowCovered[i] && !colCovered[j] && costMatrix[i][j] < min)
            {
                min = costMatrix[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (rowCovered[i])
        {
            for (int j = 0; j < n; j++)
            {
                costMatrix[i][j] += min;
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (!colCovered[j])
        {
            for (int i = 0; i < n; i++)
            {
                costMatrix[i][j] -= min;
            }
        }
    }
}

void hungarian()
{
    clearCovers();
    step1();
    step2();
    step3();
    step4();
    step3();
    printAssignment();
}

int main()
{
    hungarian();
    return 0;
}
// The Hungarian method is a combinatorial optimization algorithm that solves the assignment problem in polynomial time. It was developed and published by Harold Kuhn in 1955, who gave the name "Hungarian method" because the algorithm was largely based on the earlier works of two Hungarian mathematicians: Dénes Kőnig and Jenő Egerváry.