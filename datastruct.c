#include "datastruct.h"

Neuron neuron(double*inputs,double*weights,double bias)
{
    Neuron n;
    n.inputs=inputs;
    n.weights=weights;
    n.bias=bias;
    return n;
}

double output(Neuron n)
{
    double result=0.0;
    int len=sizeof(n.inputs);
    printf("%d\n",len);
    for (int i = 0; i <len; i++)
    {
        result+= n.inputs[i]*n.weights[i];
    }
    return result+n.bias;
    
}

int main(int argc, char const *argv[])
{
    double za[]={0.1,0.2,0.3};
    double aa[]={0.3,0.1,0.15};
    Neuron n=neuron(za,aa,0.84);
    printf("%f",output(n));
    return 0;
}
