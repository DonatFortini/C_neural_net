#include "matrix.h"

Matrix matrice(int rows, int cols)
{
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;

    matrix.data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix.data[i] = malloc(cols * sizeof(int));
    }

    return matrix;
}

void freeMatrice(Matrix matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

void setElement(Matrix matrix, int row, int col, int value)
{
    if (row < matrix.rows && col < matrix.cols)
    {
        matrix.data[row][col] = value;
    }
    else
    {
        printf("out of bounds\n");
    }
}

int getElement(Matrix matrix, int row, int col)
{
    if (row < matrix.rows && col < matrix.cols)
    {
        return matrix.data[row][col];
    }
    return -1;
}

void print(Matrix matrix)
{
    printf("------------------------------------------------------\n");
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            printf("%d ", matrix.data[i][j]);
        }
        printf("\n");
    }

    printf("------------------------------------------------------\n");
}

Matrix add(Matrix A, Matrix B)
{
    if (A.cols == B.rows)
    {
        Matrix m = matrice(A.rows, B.cols);
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < B.cols; j++)
            {
                m.data[i][j] = A.data[i][j] + B.data[i][j];
            }
        }
        return m;
    }
    printf("matrix can't be added");
}

Matrix multiply(Matrix A, Matrix B)
{
    if (A.cols == B.rows)
    {
        Matrix m = matrice(A.rows, B.cols);

        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < B.cols; j++)
            {
                for (int n = 0; n < A.cols; n++)
                {
                    m.data[i][j] += A.data[i][n] * B.data[n][j];
                }
            }
        }
        return m;
    }
    printf("matrix can't be multiply");
}

Matrix inverse(Matrix A)
{
    Matrix m;
    if (A.cols == 2 && A.rows == 2)
    {
        m = matrice(2, 2);
        setElement(m,0,0,A.data[1][1]*determinant(A));
        setElement(m,0,1,-A.data[0][1]*determinant(A));
        setElement(m,1,0,-A.data[1][0]*determinant(A));
        setElement(m,1,1,A.data[0][0]*determinant(A));
        return m;
    }
    else if (A.cols == 3 && A.rows == 3)
    {
        return m;
    }
    else
    {
        printf("non calculable\n");
    }
}

int determinant(Matrix A)
{
    if (A.cols == 2 && A.rows == 2)
    {
        return A.data[0][0] * A.data[1][1] - A.data[1][0] * A.data[0][1];
    }
    else if (A.cols == 3 && A.rows == 3)
    {
        return A.data[0][0] * (A.data[1][1] * A.data[2][2] - A.data[1][2] * A.data[2][1]) 
             - A.data[0][1] * (A.data[1][0] * A.data[2][2] - A.data[1][2] * A.data[2][0]) 
             + A.data[0][2] * (A.data[1][0] * A.data[2][1] - A.data[1][1] * A.data[2][0]);
    }
    else
    {
        printf("non calculable\n");
    }
}

int main(int argc, char const *argv[])
{
    Matrix m = matrice(2, 2);

    setElement(m, 0, 0, 1);
    setElement(m, 0, 1, 3);
    setElement(m, 1, 0, 2);
    setElement(m, 1, 1, 4);
    print(m);

    Matrix m2 = matrice(2, 2);

    setElement(m2, 0, 0, 2);
    setElement(m2, 0, 1, 4);
    setElement(m2, 1, 0, 6);
    setElement(m2, 1, 1, 8);
    print(m2);

    m2 = multiply(m, m2);
    print(m2);

    m2 = matrice(3, 3);

    setElement(m2, 0, 0, 2);
    setElement(m2, 0, 1, 4);
    setElement(m2, 0, 2, 3);
    setElement(m2, 1, 0, 6);
    setElement(m2, 1, 1, 8);
    setElement(m2, 1, 2, 7);
    setElement(m2, 2, 0, 6);
    setElement(m2, 2, 1, 8);
    setElement(m2, 2, 2, 9);
    print(m2);

    printf("%d\n ", determinant(m));
    printf("%d\n ", determinant(m2));

    print(m);
    m=inverse(m);
    print(m);
    return 0;
}
