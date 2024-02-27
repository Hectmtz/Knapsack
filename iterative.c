#include<stdio.h>

int main()
{
    int s, n;
    scanf("%d", &s);
    scanf("%d", &n);
    int w[n];
    int v[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        scanf("%d", &v[i]);
    }

    printf("%d", knapsack(s, n, w, v));
}

int knapsack(int s, int n, int* w, int* v)
{
    int tab[n+1][s+1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= s; j++)
        {
            if( i == 0 || j == 0)
            {
                tab[i][j] = 0;
            }
            else if(w[i-1] > j)
            {
                tab[i][j] = tab[i-1][j];
            }
            else
            {
                tab[i][j] = max(v[i-1] + tab[i-1][j-w[i-1]], tab[i-1][j]);
            }
        }
    }
    return tab[n][s];
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
