//Given a binary sequence s and a positive integer n. Count the number Q of binary sequences of 
//length n that does not contain s as a substring.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void count(int i, char q[], char b[20]);
int n, num = 0;

int main()
{
    char q[6];
    scanf("%d", &n);
    getchar();
    scanf("%[^\n]s", q);
    char* bina;
    bina = (char*) malloc(n*sizeof(char));
    count(0, q, bina);
    printf("%d", num);
}

void count(int i, char q[6], char bina[2])
{
    char j;
    for (j = '0'; j <= '1'; j++) {
        //if (i == 0) bina = "";
        //printf("%d %c %s\n", i, j, bina);
        bina[i] = j;  
        if (i == n-1) {
            //printf("%s\n", bina);
                if (!strstr(bina, q)) num++;
                
            }
            else count(i + 1, q, bina);
        
    }
}