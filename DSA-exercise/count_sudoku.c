#include <stdio.h>
#include <stdlib.h>
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
void fil(int c, int r);


int a[10][10], row[10][10], col[10][10], count = 0, check3x3[10][10][11];
 
int main(int argc, char *argv[]) {
	//FILE* inp;
	//FILE* out;
	//inp = fopen("in.txt", "r");
	//out = fopen("out.txt", "w");
	//if (inp == NULL) printf("cannot");
	//printf("can");
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			scanf("%d", &a[i][j]);
			//printf("%d", a[i][j]);
			row[i][a[i][j]] = a[i][j];
			col[j][a[i][j]] = a[i][j];
            check3x3[i/3 + (i % 3 != 0)][j/3 + (j % 3 != 0)][a[i][j]] = a[i][j];
		}
	}
	fil(1, 1);
	printf("%d",count);
	return 0;
}
 


void fil(int c, int r) 
{
//printf(" c = %d r =%d a[c][r] = %d\n", c, r, a[c][r]);
	int i, j;
	
	//int i, j;
	if (a[r][c] == 0) {
	for (i = 1; i <= 9; i++) {
		    if (row[r][i] == 0 && col[c][i] == 0 && check3x3[r/3 + (r % 3 != 0)][c/3 + (c % 3 != 0)][i] == 0) {
    			a[r][c] = i;
    			row[r][i] = i;
    			col[c][i] = i;
                check3x3[r/3 + (r % 3 != 0)][c/3 + (c % 3 != 0)][i] = i;
        		if (c == 9) {
        			if (r < 9) fil(1, r + 1);
        			else count++;
        		}
        		else {
        			//printf("0. c = %d r =%d a[c][r] = %d\n", c, r, a[c][r]);
        			fil (c + 1, r);
                }
                a[r][c] = 0;
                row[r][i] = 0;
                col[c][i] = 0;
                check3x3[r/3 + (r % 3 != 0)][c/3 + (c % 3 != 0)][i] = 0;
    		}
		}
	}
	else {
		    if (c == 9) {
        		if (r < 9) fil(1, r + 1);
            	else count++;
        	}
        	else {
        	    //printf("1. c = %d r =%d a[c][r] = %d\n", c, r, a[r][c]);
        		fil (c + 1, r);
        		}
		}
}


