#include<stdio.h>
#include<stdlib.h>

int a[9][9];
int check_col();
int submatrix(int i, int j);
int check_submatrix();

int main()
{
    int n, i, j, k, mark[10] = {0};
    scanf("%d", &n);
    int* sudo;
    sudo = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; i++) {
        sudo[i] = 1;
        for (j = 0; j < 9; j++) {
            for (int t = 0; t <= 9; t++) mark[t] = 0;
            for (k = 0; k < 9; k++)
                scanf("%d", &a[j][k]);
                if (mark[a[j][k]] == 0)
                    mark[a[j][k]] = 1;
                else sudo[i] = 0;
        }
        if (sudo[i] == 1) {
            sudo[i] = check_col() && check_submatrix();
            //printf("%d", check_submatrix());
        }
        printf("%d\n", sudo[i]);
    }
    // for (i = 0; i < n; i++) {
    //     if (sudo[i] == 1) {
    //         sudo[i] = check_col() && check_submatrix();
    //     }
    //     printf("%d\n", sudo[i]);
    // }
}

int check_col()
{
    int i, j, mark[10], t;
    for (i = 0; i < 9; i++){
        for (t = 0; t <= 9; t++) mark[t] = 0;
        for (j = 0; j < 9; j++)
            {
                //printf("%d %d %d\n", i, j, mark[a[j][i]]);
            if (mark[a[j][i]] == 0){
                mark[a[j][i]] = 1;
                //printf("%d %d %d\n", i, j, mark[a[j][i]]);
            }
            else { //printf("%d %d", i, j);
                return 0;}}
    }
    return 1;
}

int submatrix(int a1, int b1)
{
    int i, j, mark[10] = {0};
    for (i = a1; i < a1 + 3; i++)
        for (j = b1; j < b1 + 3; j++) 
            if (mark[a[i][j]] == 0)
                mark[a[i][j]] = 1;
            else return 0;
    return 1;
}

int check_submatrix()
{
    int i = 0, j = 0;
    while (i < 7)
    {
        while (j < 7){
            if (submatrix(i, j) == 0) return 0;
            else {
                j += 2;
            }
        }
        i += 2;
    }
    return 1;
}