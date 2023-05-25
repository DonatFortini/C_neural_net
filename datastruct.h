#include "matrix.h"

typedef struct
{
    double *inputs;
    double *weights;
    double bias;
} Neuron;

typedef struct
{
    Neuron **neurons;
    // activation func
} Layer;

typedef struct
{
    Layer **layers;
    //layer refs
} NeuralNetwork;

typedef struct
{
    Matrix wm;
} WeightMatrix;

typedef struct
{
    Matrix bs;
} BiasVector;

Neuron neuron(double*inputs,double*weights,double bias);
double output(Neuron n);
