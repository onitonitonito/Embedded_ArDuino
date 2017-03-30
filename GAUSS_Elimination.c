/*
Solving simultaneous equations by using
GAUSS Elimination Method

    ax + by = c
    Ax + By = C, deriving Solution for x and y.

     2x2     1x2   1x2 .... Matrix for simultaneous equations
    [a][b] . [x] = [c]
    [A][B] . [y] = [C]

*/

#include <stdio.h>
#include <conio.h>

void printarr();

int main() {
    int i,j,k,l,m,n,step=1,stepbull;
    int going = 0;
    double arr[6][7], rr[6][6], imsi[7], save;
    char select;

    while(going == 0) {
        printf("The number of Equations : ");
        scanf("%d", &n);
        for(i = 0; i <= n-1; i++) {
            for(j = 0; j<= n; j++) {
                printf("arr[%d][%d] : ", i, j);
                scanf("%lf", &arr[i][j]);
                printf("\n");
            }
        }

        printarr(&n, arr);

        getchar();
        printf("Is This a right Matrix which you intended (y/n)? )\n");
        scanf("%c", &select);

        if(select == 'Y')
            going = 1;
        else
            going = 0;
    }

    for(i=0;i<=n-1;i++) {
        for(j=0;j<=n-1;j++) {
            rr[i][j] = arr[i][j];
        }
    }

    getchar();
    printf("Wanna see the whole precess of GAUSS Elimination(y/n)?\n");
    scanf("%c", &select);

    if(select = 'Y')
        stepbull = 1;
    else
        stepbull = 0;

    going = 0;

// Make 0 at Bottom-Left at The Matrix
    for(j=0; j <= n-1; j++) {
        if(arr[j][j] == 0) {
            for(k = j+1; k <= n-1; k++) {
                if(arr[k][j] != 0) {
                    for(l = 0; l <= n; l++) {
                        imsi[l] = arr[k][l];
                        arr[k][l] = arr[j][l];
                        arr[j][l] = imsi[l];
                    }
                    break;
                }
            }
        }
    }

    for(j=0; j <= n-1; j++) {
        for(i = j+1; i <= n-1; i++) {
            if(arr[i][j] == 0)
                continue;
            else {
                save = arr[i][j] / arr[j][j];
                for(k = 0; k <= n; k++) {
                    arr[i][k] -= arr[j][k] * save;
                }
            }
        }
        if(stepbull == 1) {
            printf("\n- STEP%d -\n", step);
            printarr(&n, arr);
            step ++;
        }
    }

// TURN every diagonal POS to '1' -- Makeup Diagonal line to '1'
    for(i=0; i<=n-1; i++) {
        save = arr[i][i];
        for(j=i; j<=n; j++) {
            arr[i][j] /= save;
        }
    }

    if(stepbull == 1) {
            printf("\n- STEP%d -\n", step);
            printarr(&n, arr);
            step ++;
        }
   // Make 0 at Top-Right at The Matrix
    for(j=1; j<= n-1; j++) {
        for(i=0; i<= j-1; i++) {
            save = arr[i][j];
            for(k=j; k<= n; k++) {
                arr[i][k] -= save * arr[j][k];
            }
        }
        if(stepbull == 1) {
            printf("\n- STEP%d -\n", step);
            printarr(&n, arr);
            step ++;
        }
    }

    printf("\n");
    printf("<Answer>\n");
    for(l=0;l<=n-1;l++) {
        printf("│%15.7f│\n", arr[l][n]);
    }

    return 0;
}

void printarr(int *p, double (*parr)[7])
{
    int i,j;
    for(i = 0; i <= *p-1; i++) {
        if( i == 0)
                printf("┌");
            else if( i == *p-1)
                printf("└");
            else
                printf("│");

        for(j = 0; j <= *p; j++) {
            printf("%15.7lf", parr[i][j]);
            if(j == *p-1)
                printf("│");
        }
    if( i == 0)
            printf("┐");
        else if( i == *p-1)
            printf("┘");
        else
            printf("│");
    printf("\n");
    }
}

/*
  ref = http://prograaammm.blogspot.kr/2015/04/c.html?m=1
  C programming, Electronic engineering, etc
  2015. 4/24
*/
