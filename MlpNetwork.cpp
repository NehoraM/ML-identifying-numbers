#include "MlpNetwork.h"

/**
    *
    * @param weighes Array in size of 4 of weight matrix
    * @param biases Arrays in size 4 of biases
    */
MlpNetwork::MlpNetwork(Matrix *weighes, Matrix *biases) :
        _layer1(weighes[0], biases[0], Relu),
        _layer2(weighes[1], biases[1], Relu),
        _layer3(weighes[2], biases[2], Relu),
        _layer4(weighes[3], biases[3], Softmax)
{
}

/**
 *
 * @param m the matrix
 * @return the digit in the picture
 */
Digit MlpNetwork::operator()(Matrix &m)
{
    Matrix m1 = m;
    m1 = _layer1(m1);
    m1 = _layer2(m1);
    m1 = _layer3(m1);
    m1 = _layer4(m1);

    int size = m1.getRows() * m1.getCols();

    float max = 0;
    int index = 0;
    for (int i = 0; i < size; ++i)
    {
        if (m1[i] > max)
        {
            max = m1[i];
            index = i;
        }
    }

    Digit d;
    d.value = index;
    d.probability = max;
    return d;
}

