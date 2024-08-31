#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void mergeSort(char a[100][30], int left, int right);
void merge(char a[100][30], int left, int mid, int right);
char* getname(char a[30]);
char b[100][30];
int main()
{
    char info[100][30];
    int i = 1;
    while(1) {
        fgets(info[i], sizeof(info[i]), stdin);
        info[i][strcspn(info[i], "\n")] = '\0';
        if (!strcmp(info[i], "#")) break;
        else i++;
    }
    printf("%d\n", i);
    //for (int j = 1; j < i; j++) printf("%s\n", info[j]);
    mergeSort(info, 1, i - 2);
    for (int j = 1; j < i; j++) printf("%s\n", info[j]);
    return 0;
}
 
 
void mergeSort(char a[100][30], int left, int right)
{
    //printf("%d %d_", left, right);
    if (left < right){
        int mid;
        if (((left + right)/2) % 2 != 0) mid = (left + right)/2;
        else mid = (left + right)/2 - 1;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 2, right);
        merge(a, left, mid, right);
    }
}
 

char* getname(char a[30])
{
    int len = strcspn(a, "\0"), i = len, j = 0;
    char *b;
    
    while (a[i] != ' ')
    {
        i--;
    }
    i++;
    b = (char*) malloc((len - i + 1) * sizeof(char));
    while (i < len)
    {
        b[j] = a[i];
        i++;
        j++;
    }
    return b;    
}

void merge(char a[100][30], int left, int mid, int right)
{
    int i = left, j = mid + 2, k = 0;
    while (i <= mid && j <= right) {
        char x[9], y[9];
        if (strcmp(getname(a[i]),getname(a[j])) < 0) {
            strcpy(b[k],a[i]);
            strcpy(b[k + 1],a[i + 1]);
            i+=2;
            k+=2;
        } else if (strcmp(a[i], a[j]) == 0)
        {
            if (strcmp(a[i + 1], a[j + 1]) > 0) {
                strcpy(b[k],a[i]);
                strcpy(b[k + 1],a[i + 1]);
                i+=2;
                k+=2;
            }
        }
        else 
        {
            strcpy(b[k],a[j]);
            strcpy(b[k + 1],a[j + 1]);
            j+=2;
            k+=2;
        }
    }
    while(i <= mid) {
        strcpy(b[k],a[i]);
        strcpy(b[k + 1],a[i + 1]);
        k+=2;
        i+=2;
    }
    while(j <= right) {
        strcpy(b[k],a[j]);
        strcpy(b[k + 1],a[j + 1]);
        k+=2;
        j+=2;
    }
    for (i = left; i <= right; i+=2) {
        strcpy(a[i], b[i - left]);
        strcpy(a[i + 1], b[i + 1 - left]);
        //printf("%s\n", b[i-left]);
    }
    //free(b);
}

