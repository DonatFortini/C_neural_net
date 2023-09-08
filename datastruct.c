#include "datastruct.h"
//--------------------------------------Neuron---------------------------------------------------------

Neuron neuron(double *inputs, double *weights, double bias, int length)
{
    Neuron n;
    n.inputs = fillArray(inputs, length);
    n.weights = fillArray(weights, length);
    n.bias = bias;
    n.length = length;
    return n;
}

double *fillArray(const double *sourceArray, size_t size)
{
    double *dynamicArray = malloc(size * sizeof(double));
    for (size_t i = 0; i < size; i++)
        dynamicArray[i] = sourceArray[i];
    return dynamicArray;
}

double output(Neuron n)
{
    double result = 0.0;
    printf("%d \n", n.length);
    for (int i = 0; i < n.length; i++)
        result += n.inputs[i] * n.weights[i];
    return result + n.bias;
}

//--------------------------------------Layer---------------------------------------------------------

Layer *layer(int size)
{
    Layer *layer = (Layer *)malloc(sizeof(Layer));
    layer->size = size;
    layer->neurons = (Neuron **)malloc(size * sizeof(Neuron *));
    for (int i = 0; i < size; i++)
        layer->neurons[i] = NULL;
    return layer;
}

void addNeuron(Layer *layer, Neuron *neuron, int index)
{
    layer->neurons[index] = neuron;
}

void printLayer(Layer *layer)
{
    printf("[             TOP            ]\n");
    for (int i = 0; i < layer->size; i++)
    {
        Neuron *neuron = layer->neurons[i];
        if (neuron != NULL)
            printf("[Neuron %d with bias: %lf]\n", i, neuron->bias);
        else
            printf("[----------------------------]\n");
    }
    printf("[           BOTTOM           ]\n");
}

//--------------------------------------Network---------------------------------------------------------

NeuralNetwork *Network(int layerSize)
{

}