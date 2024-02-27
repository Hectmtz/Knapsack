#include<stdio.h>

int knapsack(int s, int i, int n, int* w, int* v, int** tab);
int max(int a, int b);

int main()
{
    int s, n;
    scanf("%d", &s);
    scanf("%d", &n);
    int w[n];
    int v[n];
    int tab[s+1][n+1];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        scanf("%d", &v[i]);
    }
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tab[i][j] = -1;
        }
    }
    printf("%d", knapsack(s, 0, n, w, v, tab));
}

int knapsack(int s, int i, int n, int* w, int* v, int** tab)
{
    if(s == 0)
    {
        return 0;
    }

    if(i == n)
    {
        return 0;
    }
    if(tab[s][i] == -1)
    {
        if(w[i-1] > s)
        {
            tab[s][i] = knapsack(s, i + 1, n, w, v, tab);
        }
        else
        {
            tab[s][i] = max(knapsack(s - w[i-1], i + 1, n, w, v, tab) + v[i-1], knapsack(s, i + 1, n, w, v, tab));
        }
    }
    return tab[s][i];
}

int max(int a, int b)
{
    if(a == b)
    {
        return b;
    }

    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
