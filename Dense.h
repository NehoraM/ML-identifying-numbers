#include "Matrix.h"
#include "Activation.h"

#ifndef EX4_DENSE_H
#define EX4_DENSE_H

/**
 * This class represents one layer in the neural network
 */
class Dense
{
public:
    Matrix _weight;
    Matrix _bias;
    ActivationType _type;

    /**
     *
     * @param w weight matrix
     * @param b bias matrix
     * @param t type matrix
     */
    Dense(Matrix &w, Matrix &b, ActivationType t);

    /**
     *
     * @return the weight matrix
     */
    Matrix &getWeights();

    /**
     *
     * @return the bias matrix
     */
    Matrix &getBias();

    /**
     *
     * @return the activation type
     */
    ActivationType getActivation() const;

    /**
     *
     * @param input input of Layer
     * @return the matrix after the layer
     */
    Matrix &operator()(Matrix &input);
};

#endif //EX4_DENSE_H
