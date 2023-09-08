#include "matrix.h"

typedef struct
{
    double *inputs;
    double *weights;
    double bias;
    int length;
} Neuron;

typedef struct
{
    int size;
    Neuron **neurons;
    // activation func
} Layer;

typedef struct
{
    Layer **layers;
    // layer refs
} NeuralNetwork;

typedef struct
{
    Matrix wm;
} WeightMatrix;

typedef struct
{
    Matrix bs;
} BiasVector;

Neuron neuron(double *inputs, double *weights, double bias, int length);
double output(Neuron n);
double *fillArray(const double *sourceArray, size_t size);

Layer *layer(int size);
void addNeuron(Layer *layer, Neuron *neuron, int index);
void printLayer(Layer *layer);

NeuralNetwork *Network(int layerSize);