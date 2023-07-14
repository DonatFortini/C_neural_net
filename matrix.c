#include "matrix.h"

Matrix matrice(int rows, int cols)
{
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;

    matrix.data = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        matrix.data[i] = malloc(cols * sizeof(double));
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

double getElement(Matrix matrix, int row, int col)
{
    if (row < matrix.rows && col < matrix.cols)
    {
        return matrix.data[row][col];
    }
    return -1.0;
}

void print(Matrix matrix)
{
    printf("------------------------------------------------------\n");
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            printf("%.1f ", matrix.data[i][j]);
        }
        printf("\n");
    }

    printf("------------------------------------------------------\n");
}

Matrix add(Matrix A, Matrix B)
{
    Matrix m = matrice(A.rows, B.cols);
    if (A.cols == B.rows)
    {
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

    if ((int)determinant(A) != 0 && A.cols == A.rows)
    {
        if (A.cols == 2)
        {
            Matrix m = matrice(2, 2);
            setElement(m, 0, 0, A.data[1][1] * 1 / determinant(A));
            setElement(m, 0, 1, -A.data[0][1] * 1 / determinant(A));
            setElement(m, 1, 0, -A.data[1][0] * 1 / determinant(A));
            setElement(m, 1, 1, A.data[0][0] * 1 / determinant(A));
            return m;
        }
        else if (A.cols == 3)
        {
            int det = determinant(A);
            Matrix adj = adjointe(transpose(A));
            float exp = 1 / det;
            for (int i = 0; i < A.cols; i++)
            {
                for (int j = 0; j < A.rows; j++)
                {
                    adj.data[i][j] = adj.data[i][j] * exp;
                }
            }

            return adj;
        }
    }
    else
    {
        printf("non calculable\n");
    }
}

Matrix transpose(Matrix A)
{
    Matrix trans = matrice(A.cols, A.rows);

    for (int i = 0; i < A.cols; i++)
    {
        for (int j = 0; j < A.rows; j++)
        {
            trans.data[i][j] = A.data[j][i];
        }
    }

    return trans;
}

Matrix adjointe(Matrix A)
{
    if (A.cols == 3 & A.rows == 3)
    {
        int sign = 1;
        int i, j, k, l;
        Matrix cofactor = matrice(2, 2);
        Matrix adj = matrice(3, 3);
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                int subi = 0;
                for (k = 0; k < 3; k++)
                {
                    if (k == i)
                    {
                        continue;
                    }
                    int subj = 0;
                    for (l = 0; l < 3; l++)
                    {
                        if (l == j)
                        {
                            continue;
                        }
                        cofactor.data[subi][subj] = A.data[k][l];
                        subj++;
                    }
                    subi++;
                }
                int cofactor_sign = (i + j) % 2 == 0 ? 1 : -1;
                adj.data[i][j] = cofactor_sign * determinant(cofactor);
            }
        }
        return adj;
    }
}

double determinant(Matrix A)
{
    if (A.cols == 2 && A.rows == 2)
    {
        return A.data[0][0] * A.data[1][1] - A.data[1][0] * A.data[0][1];
    }
    else if (A.cols == 3 && A.rows == 3)
    {
        return A.data[0][0] * (A.data[1][1] * A.data[2][2] - A.data[1][2] * A.data[2][1]) - A.data[0][1] * (A.data[1][0] * A.data[2][2] - A.data[1][2] * A.data[2][0]) + A.data[0][2] * (A.data[1][0] * A.data[2][1] - A.data[1][1] * A.data[2][0]);
    }
    else
    {
        printf("non calculable\n");
    }
}
