/***************************************************************
* INPUT square matrix size & valie[n][n]
*   using cofactor --> calculate determinant
* IN : square matrix size, matrix value[n][n]
* OUT : square matrix, determinant* of Matrix
***************************************************************/

#include <stdio.h>    // standard I/O header file
#include <stdlib.h>   // dynamic memory assign header file
#include <math.h>     // for pow fuction (x^n) header file

void InputMat(double **mat, int size);      // Input matrix value[n][n]
void ShowMat(double **mat, int size);       // Matrix Output function
double DetMat(double **mat, int size);      // Input matrix size and Calc. determinant (return)
double CofacMat(double **mat, int p, int q, int size); // Input matrix size, index, return cofactor

int main(void) {
    int size=2;
    int i=0;
    double **mat;

    printf("Input Size of SQ.matrix >>");
    scanf_s("%d", &size);

 //assign dynamic memory in matrix
    mat = (double**)malloc( sizeof(double*) * size );
    for (i=0 ; i<size ; i++) {
        mat[i] = (double*)malloc( sizeof(double) * size );
    }

    InputMat(mat, size);        //input Matrix size
    ShowMat(mat, size);         //Show assigned Matrix

    printf("\nDeterminant = %.2lf\n", DetMat(mat, size));

 //unassign dynamic memory of Matrix
    for (i=0 ; i<size ; i++) {
        free(mat[i]);
    }

    free(mat);
    return 0;
}

void InputMat(double **mat, int size) {
    int p=0, q=0;

    for (p=0; p<size; p++) {
        for (q=0; q<size; q++) {
             printf("Input ...value of Arr[%d][%d] >>", p+1, q+1);
             scanf_s("%lf", &mat[p][q]);
        }
    }
}

void ShowMat(double **mat, int size) {
    int p=0, q=0;

    printf("\n\nmatrix = \n");
    for (p=0; p<size; p++) {
        if (p == 0) {
            printf("/");
        }
        else if(p == size-1) {
            printf("\\");
        }
        else {
            printf("|");
        }

        for (q=0; q<size; q++) {
            printf(" %.2lf", mat[p][q]);
        }

        if (p == 0) {
            printf(" \\\n");
        }
        else if(p == size-1) {
            printf(" /\n");
        }
        else {
            printf(" |\n");
        }
    }
}

double DetMat(double **mat, int size) {
    int p=0, q=0;
    double det=0;

    if (size == 1) {   //determinant of 1 by 1 matrix
        return mat[0][0];
    }
    else if ( size == 2 ) { //determinant 2 by 2 matrix
        return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
    }
    else {     //more than 3 by 3
        for (q=0, det=0 ; q<size ; q++) {
            det = det + mat[0][q]*CofacMat(mat, 0, q, size);
        }
        return det;
    }
    return 0;
}

double CofacMat(double **mat, int p, int q, int size) {
    int i=0, j=0;  //matrix index from arguments
    int x=0, y=0;  //cmat index
    double **cmat;
    double cofactor=0;

    //Assign dynamic memory of cofactor matrix
    cmat = (double**)malloc( sizeof(double*) * (size-1) );

    for (i=0 ; i<(size-1) ; i++) {
        cmat[i] = (double*)malloc( sizeof(double) * (size-1) );
    }

    // deriving cmat form mat (cmat is consisted with remains
    // which was left after extracting (p-line, q-column value) from matrix
    for (i=0,x=0 ; i<size ; i++) {
        if (i != p) {
            for (j=0,y=0 ; j<size ; j++) {
                if (j != q) {
                    cmat[x][y] = mat[i][j];
                    y++;
                }
            }
            x++;
        }
    }

    //calculate cofactor
    cofactor = pow(-1,p)*pow(-1,q)*DetMat(cmat,size-1);

    //unassign dynamic memory cofactor matrix
    for (i=0 ; i<(size-1) ; i++) {
        free(cmat[i]);
    }

    free(cmat);
    return cofactor;
}

// ref: http://bark10731.tistory.com/101
