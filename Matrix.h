#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows, cols;
} MatrixDims;

/**
 * represent a Matrix and some operation that can be done on a matrix.
 */
class Matrix
{
private:
    int _rows;
    int _cols;
    float *_matrix;
    int _size;

public:

    /**
     * default constructor
     */
    Matrix();

    /**
     *
     * @param rows the row of the matrix
     * @param cols the cols of the matrix
     */
    Matrix(int rows, int cols);

    /**
     *
     * @param m the matrix to copy
     */
    Matrix(const Matrix &m);

    /**
     * Destructor
     */
    ~Matrix();

    /**
     *
     * @return the row of the matrix
     */
    int getRows() const;

    /**
     *
     * @return the cols of the matrix
     */
    int getCols() const;

    /**
     * print float values in matrix.
     */
    void plainPrint() const;

    /**
     *
     * @return refernce to vectorized matrix (1 column form)
     */
    Matrix &vectorize();

    /**
     *
     * @param row the number of row
     * @param col the number of cols
     * @return the value in (row,col)
     */
    float &operator()(int row, int col);

    /**
     *
     * @param row the number of row
     * @param col the number of cols
     * @return the value in (row,col)
     */
    float &operator()(int row, int col) const;

    /**
     *
     * @param element the index
     * @return the value in the element index
     */
    float &operator[](int element);

    /**
     *
     * @param element the index
     * @return the value in the element index
     */
    float &operator[](int element) const;

    /**
     *
     * @param other the other matrix
     * @return makes this equal other matrix
     */
    Matrix &operator=(const Matrix &other);

    /**
     *
     * @param other the other matrix
     * @return  adds other matrix to this matrix and return another one
     */
    Matrix operator+(const Matrix &other) const;

    /**
     *
     * @param other the other matrix
     * @return add the other matrix to the matrix and return another matrix
     */
    Matrix &operator+=(const Matrix &other);

    /**
     *
     * @param other the other matrix
     * @return minus the other matrix to the matrix and return another matrix
     */
    Matrix operator-(const Matrix &other) const;

    /**
     *
     * @param other the other matrix
     * @return minus the other matrix to the matrix and return another matrix
     */
    Matrix &operator-=(const Matrix &other);

    /**
     *
     * @param other the other matrix
     * @return other matrix times this matrix
     */
    Matrix operator*(const Matrix &other) const;

    /**
      *
      * @param other the other matrix
      * @return other matrix times this matrix
      */
    Matrix &operator*=(const Matrix &other);

    /**
     *
     * @param input binary file in ifstream format that represents float numbers
     * @param m matrix of float
     */
    friend void operator>>(std::ifstream &input, Matrix &m);

    /**
     *
     * @param out out ostream
     * @param m matrix
     * @return prints matirx to ostream
     */
    friend std::ostream &operator<<(std::ostream &out, Matrix &m);

    /**
     *
     * @param f float
     * @return matrix times float
     */
    Matrix operator*(float f) const;

    /**
     *
     * @param f float
     * @return matrix times float
     */
    friend Matrix operator*(float f, const Matrix &m);
};

#endif //MATRIX_H


