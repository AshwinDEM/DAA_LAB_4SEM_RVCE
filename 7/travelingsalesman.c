#include <stdio.h>

/* Traveling Salesman Problem

The traveling salesman problem (TSP) is a classic problem in combinatorial optimization. The problem is to find the shortest possible route that visits each city exactly once and returns to the origin city. The problem is NP-hard, meaning that there is no known polynomial-time algorithm that can solve all instances of the problem.    

The TSP can be solved using a brute-force approach, but this is not practical for large instances of the problem. Instead, heuristic and approximation algorithms are used to find near-optimal solutions in a reasonable amount of time.

The TSP can be modeled as a graph, where the cities are the vertices and the distances between the cities are the edges. The goal is to find a Hamiltonian cycle (a cycle that visits each vertex exactly once) with the minimum total weight.

In this program, we implement the TSP using the nearest neighbor heuristic. The nearest neighbor heuristic is a simple algorithm that starts at a random city and repeatedly visits the nearest unvisited city until all cities have been visited. The algorithm then returns to the starting city to complete the cycle.

The nearest neighbor heuristic is not guaranteed to find the optimal solution to the TSP, but it is fast and easy to implement. It is a good choice for small instances of the problem or as a starting point for more sophisticated algorithms.    

```c */

#include <stdio.h>

#define N 4

int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[N] = {0};

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int nearestNeighbor(int start)
{
    int tour[N];
    int cost = 0;
    int current = start;
    visited[current] = 1;
    tour[0] = current;
    for (int i = 1; i < N; i++)
    {
        int nearest = -1;
        int minDist = 9999;
        for (int j = 0; j < N; j++)
        {
            if (!visited[j] && graph[current][j] < minDist)
            {
                nearest = j;
                minDist = graph[current][j];
            }
        }
        visited[nearest] = 1;
        tour[i] = nearest;
        cost += minDist;
        current = nearest;
    }
    cost += graph[current][start];
    printf("Tour: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", tour[i]);
    }
    printf("\n");
    return cost;
}

int main()
{
    int start = 0;
    int cost = nearestNeighbor(start);
    printf("Total cost: %d\n", cost);
    return 0;
}

