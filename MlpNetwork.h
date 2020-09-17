#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Digit.h"
#include "Dense.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784},
                                  {64,  128},
                                  {20,  64},
                                  {10,  20}};
const MatrixDims biasDims[] = {{128, 1},
                               {64,  1},
                               {20,  1},
                               {10,  1}};

/**
 * represents the neaural network
 */
class MlpNetwork
{
private:
    Dense _layer1;
    Dense _layer2;
    Dense _layer3;
    Dense _layer4;

public:
    /**
     *
     * @param weighes Array in size of 4 of weight matrix
     * @param biases Arrays in size 4 of biases
     */
    MlpNetwork(Matrix *weighes, Matrix *biases);

    /**
     *
     * @param m the matrix
     * @return the digit int the picture
     */
    Digit operator()(Matrix &m);
};

#endif // MLPNETWORK_H
