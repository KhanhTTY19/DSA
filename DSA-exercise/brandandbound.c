#include<stdio.h>
#include<stdlib.h>


void Try(int k);

int n, a[50][50], x[50], visited[50], min_road = (int) 1e5, x_road[50];
int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        a[i][i] = 0;
        x[i] = 0;
        visited[i] = 0;
        for (j = 1; j <= n; j++) {
            a[i][j] = (int) 1e5;
        }
    }
    for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
    }

    x[1] = 1;
    Try(2);
    printf("%d\n", min_road);
    for (j = 1; j <= n; j++) printf("%d ", x_road[j]);
}

void Try(int k)
{
    int i, j;
    for (i = 2; i <= n; i++) 
    {
        if (visited[i] == 0) 
        {
            visited[i] = 1;
            x[k] = i;
        
        if (k == n) 
        {
            int road = 0;
            for (j = 1; j < n; j++)
             {
                road += a[x[j]][x[j + 1]];
            }
            road += a[x[n]][x[1]];
            if (road <= min_road) 
            {
                min_road = road;
                for (j = 1; j <= n; j++) 
                    x_road[j] = x[j];
            }
        }
        else Try(k + 1);
            visited[i] = 0;

        }
    }
}