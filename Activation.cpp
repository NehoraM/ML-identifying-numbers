#include "Activation.h"
#include <math.h>

/**
     *
     * @param t the type
     */
Activation::Activation(ActivationType t)
{
    if (t != Relu && t != Softmax)
    {
        std::cerr << "ERROR: This Activation does not exist. Activation constructor failed."
                  << std::endl;
        exit(1);
    }
    _type = t;
}

/**
   *
   * @return the activation type
   */
ActivationType Activation::getActivationType() const
{
    return _type;
}


/**
 *
 * @param m tha matrix
 * @return relu matrix
 */
Matrix &Activation::_relu(Matrix &m)
{
    int size = m.getCols() * m.getRows();
    for (int i = 0; i < size; ++i)
    {
        if (m[i] < 0)
        {
            m[i] = 0;
        }
    }
    return m;
}

/**
    *
    * @param m the matrix
    * @return matrix after activation function
    */
Matrix &Activation::operator()(Matrix &m)
{
    if (_type == Relu)
    {
        m = _relu(m);
    }
    else if (_type == Softmax)
    {
        m = _softmax(m);
    }
    return m;
}

/**
   *
   * @param m matrix
   * @return softmax matrix
   */
Matrix &Activation::_softmax(Matrix &m)
{
    int size = m.getCols() * m.getRows();
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        m[i] = std::exp(m[i]);
        sum = sum + m[i];
    }
    m = m * (1.0f / sum);
    return m;
}




