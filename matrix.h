#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

Matrix matrice(int rows, int cols);
void freeMatrice(Matrix matrix);
void setElement(Matrix matrix, int row, int col, int value);
int getElement(Matrix matrix, int row, int col);
void print(Matrix matrix);
Matrix add(Matrix A,Matrix B);
Matrix multiply(Matrix A,Matrix B);
Matrix inverse(Matrix matrice);
int determinant(Matrix matrice);