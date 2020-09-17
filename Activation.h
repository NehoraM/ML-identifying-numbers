#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    Relu,
    Softmax
};

/**
 * Activates softmax or relu
 */
class Activation
{
private:
    ActivationType _type;

    /**
     *
     * @param m tha matrix
     * @return relu matrix
     */
    Matrix &_relu(Matrix &m);

    /**
     *
     * @param m matrix
     * @return softmax matrix
     */
    Matrix &_softmax(Matrix &m);

public:
    /**
     *
     * @param t the type
     */
    Activation(ActivationType t);

    /**
     *
     * @return the activation type
     */
    ActivationType getActivationType() const;

    /**
     *
     * @param m the matrix
     * @return matrix after activation function
     */
    Matrix &operator()(Matrix &m);
};

#endif //ACTIVATION_H
