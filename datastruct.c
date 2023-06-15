#include "datastruct.h"

Neuron neuron(double *inputs, double *weights, double bias, int length)
{
    Neuron n;
    n.inputs = fillArray(inputs,length);
    n.weights = fillArray(weights,length);
    n.bias = bias;
    n.length = length;
    return n;
}

double* fillArray(const double* sourceArray, size_t size)
{
    double* dynamicArray = malloc(size * sizeof(double));
    for (size_t i = 0; i < size; i++) {
        dynamicArray[i] = sourceArray[i];
    }
    return dynamicArray;
}

double output(Neuron n)
{
    double result = 0.0;
    printf("%d \n", n.length);
    for (int i = 0; i < n.length; i++)
    {
        result += n.inputs[i] * n.weights[i];
    }
    return result + n.bias;
}



