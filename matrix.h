#include <stdlib.h>
#include <stdio.h>
#include "util.h"

typedef struct {
    int rows;
    int cols;
    double** data;
} Matrix;

Matrix matrice(int rows, int cols);
void freeMatrice(Matrix matrix);
void setElement(Matrix matrix, int row, int col, int value);
double getElement(Matrix matrix, int row, int col);
void print(Matrix matrix);
Matrix transpose(Matrix A);
Matrix adjointe(Matrix A);
Matrix add(Matrix A,Matrix B);
Matrix multiply(Matrix A,Matrix B);
Matrix inverse(Matrix matrice);
double determinant(Matrix matrice);