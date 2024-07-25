#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

double benchmark(int arr[], int n, void* func(int arr[], int n))
{
    clock_t start, end;
    double time_spent;
    start = clock();
    func(arr, n);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    return time_spent;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void randomarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

void asc(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

void desc(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
}


int bfs(int g[][100], int n, int s, int t)
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    memset(visited, 0, sizeof(visited));
    int queue[n];
    int front = 0;
    int rear = 0;
    queue[rear] = s;
    rear++;
    visited[s] = 1;
    while (front < rear)
    {
        int u = queue[front];
        front++;
        for (int i = 0; i < n; i++)
        {
            if (g[u][i] == 1 && visited[i] == 0)
            {
                queue[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }
    return visited[t];
}

int main()
{
    
}