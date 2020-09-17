#include "Dense.h"

/**
  *
  * @param w weight matrix
  * @param b bias matrix
  * @param t type matrix
  */
Dense::Dense(Matrix &w, Matrix &b, ActivationType t)
{
    _weight = w;
    _bias = b;
    _type = t;
}

/**
     *
     * @return the weight matrix
     */
Matrix &Dense::getWeights()
{
    return _weight;
}

/**
  *
  * @return the bias matrix
  */
Matrix &Dense::getBias()
{
    return _bias;
}

/**
     *
     * @param input input of Layer
     * @return the matrix after the layer
     */
Matrix &Dense::operator()(Matrix &input)
{
    input = _weight * input;
    input = input + _bias;
    Activation activationFunc = Activation(_type);
    input = activationFunc(input);
    return input;
}

/**
  *
  * @return the activation type
  */
ActivationType Dense::getActivation() const
{
    return _type;
}
