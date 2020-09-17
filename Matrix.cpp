#include <iostream>
#include <fstream>
#include "Matrix.h"

/**
     * default constructor
     */
Matrix::Matrix() : _matrix(nullptr)
{
    this->_rows = 1;
    this->_cols = 1;
    this->_size = 1;
    this->_matrix = new float[1];
    this->_matrix[0] = 0;
}

/**
     *
     * @param rows the row of the matrix
     * @param cols the cols of the matrix
     */
Matrix::Matrix(int rows, int cols) : _matrix(nullptr)
{

    if (rows <= 0 || cols <= 0)
    {
        std::cerr
                << "ERROR: Constructor Failed. Rows ot Cols Values are Negative."
                << std::endl;
        exit(1);
    }
    this->_rows = rows;
    this->_cols = cols;
    this->_size = rows * cols;
    this->_matrix = new float[_size];

    for (int i = 0; i < rows * cols; i++)
    {
        this->_matrix[i] = 0;
    }
}

/**
    *
    * @param m the matrix to copy
    */
Matrix::Matrix(const Matrix &m) : _matrix(nullptr)
{
    if (m._size > 0)
    {
        this->_rows = m._rows;
        this->_cols = m._cols;
        this->_size = m._size;
        _matrix = new float[_size];
        for (int i = 0; i < this->_size; i++)
        {
            this->_matrix[i] = m._matrix[i];
        }
    }
    else
    {
        std::cerr
                << "EROOR: Matrix Copy constructor failed. The matrix that should have been copied is of size 0."
                << std::endl;
        exit(1);
    }
}

/**
     * Destructor
     */
Matrix::~Matrix()
{
    delete[] _matrix;

}

/**
     *
     * @return the row of the matrix
     */
int Matrix::getRows() const
{
    return this->_rows;
}

/**
     *
     * @return the cols of the matrix
     */
int Matrix::getCols() const
{
    return this->_cols;
}

/**
     * print float values in matrix.
     */
void Matrix::plainPrint() const
{
    for (int i = 0; i < this->_rows; i++)
    {
        for (int j = 0; j < this->_cols; j++)
        {
            std::cout << (*this)(i, j) << ' ';
        }
        std::cout << std::endl;
    }
}

/**
     *
     * @return refernce to vectorized matrix (1 column form)
     */
Matrix &Matrix::vectorize()
{
    _cols = 1;
    _rows = _size;
    return *this;
}

/**
   *
   * @param row the number of row
   * @param col the number of cols
   * @return the value in (row,col)
   */
float &Matrix::operator()(int row, int col)
{
    if (row >= this->_rows || col >= this->_cols)
    {
        std::cerr
                << "ERROR: Rows or Cols Values are too big for this matrix. Operator Parenthesis Failed."
                << std::endl;
        exit(1);
    }
    if (row < 0 || col < 0)
    {
        std::cerr
                << "ERROR: ERROR: Cols or Rows Values are negative. Operator Parenthesis Failed."
                << std::endl;
        exit(1);
    }
    return this->_matrix[row * _cols + col];
}

/**
    *
    * @param row the number of row
    * @param col the number of cols
    * @return the value in (row,col)
    */
float &Matrix::operator()(int row, int col) const
{
    if (row >= this->_rows || col >= this->_cols)
    {
        std::cerr
                << "ERROR: Rows or Cols Values are too big for this matrix. Operator Parenthesis (const) Failed."
                << std::endl;
        exit(1);
    }
    if (row < 0 || col < 0)
    {
        std::cerr
                << "ERROR: Cols or Rows Values are negative. Operator Parenthesis Failed."
                << std::endl;
        exit(1);
    }
    return this->_matrix[row * _cols + col];
}


/**
    *
    * @param element the index
    * @return the value in the element index
    */
float &Matrix::operator[](int element)
{
    if (element >= _size)
    {
        std::cerr
                << "ERROR: This Element Values are too big for this matrix. Operator Brackets (not const) Failed."
                << std::endl;
        exit(1);
    }
    if (element < 0)
    {
        std::cerr
                << "ERROR: Element Values are Negative. Operator Brackets (not const) Failed."
                << std::endl;
        exit(1);
    }
    return _matrix[element];
}

/**
    *
    * @param element the index
    * @return the value in the element index
    */
float &Matrix::operator[](int element) const
{
    if (element >= _size)
    {
        std::cerr
                << "ERROR: This Element Values are too big for this matrix. Operator Brackets Failed."
                << std::endl;
        exit(1);
    }
    if (element < 0)
    {
        std::cerr
                << "ERROR: Element Values are Negative. Operator Brackets Failed."
                << std::endl;
        exit(1);
    }
    return _matrix[element];
}


/**
     *
     * @param other the other matrix
     * @return makes this equal other matrix
     */
Matrix &Matrix::operator=(const Matrix &other)
{
    if (this == &other)
    {
        return *this;
    }
    if (other._size > 0)
    {
        _rows = other._rows;
        _cols = other._cols;
        _size = other._size;
        delete[] _matrix;
        _matrix = new float[_size];
        for (int i = 0; i < _size; i++)
        {
            this->_matrix[i] = other._matrix[i];
        }
        return *this;
    }
    else
    {
        std::cerr
                << "ERROR: Operator = Failed. Matrix Other Matrix is from size 0."
                << std::endl;
        exit(1);
    }
}

/**
    *
    * @param other the other matrix
    * @return  adds other matrix to this matrix and return another one
    */
Matrix Matrix::operator+(const Matrix &other) const
{
    if ((_size != other._size) || (_rows != other._rows) || (_cols != other._cols))
    {
        std::cerr
                << "ERROR: Operator + Failed. Matrix Sizes didn't Match."
                << std::endl;
        exit(1);
    }
    Matrix sum(_rows, _cols);
    for (int i = 0; i < _size; i++)
    {
        sum._matrix[i] = (*this)[i] + other[i];
    }
    return sum;
}

/**
   *
   * @param other the other matrix
   * @return add the other matrix to the matrix and return another matrix
   */
Matrix &Matrix::operator+=(const Matrix &other)
{
    if ((_size != other._size) || (_rows != other._rows) || (_cols != other._cols))
    {
        std::cerr
                << "ERROR: Operator += Failed. Matrix Sizes didn't Match."
                << std::endl;
        exit(1);
    }
    for (int i = 0; i < _size; i++)
    {
        _matrix[i] += other[i];
    }
    return *this;
}

/**
   *
   * @param other the other matrix
   * @return minus the other matrix to the matrix and return another matrix
   */
Matrix Matrix::operator-(const Matrix &other) const
{
    if ((_size != other._size) || (_rows != other._rows) || (_cols != other._cols))
    {
        std::cerr
                << "ERROR: Operator - Failed. Matrix Sizes didn't Match."
                << std::endl;
        exit(1);
    }
    Matrix sum(_rows, _cols);
    for (int i = 0; i < _size; i++)
    {
        sum._matrix[i] = (*this)[i] - other[i];
    }
    return sum;
}

/**
    *
    * @param other the other matrix
    * @return minus the other matrix to the matrix and return another matrix
    */
Matrix &Matrix::operator-=(const Matrix &other)
{
    if ((_size != other._size) || (_rows != other._rows) || (_cols != other._cols))
    {
        std::cerr
                << "ERROR: Operator -= Failed. Matrix Sizes didn't Match."
                << std::endl;
        exit(1);
    }
    for (int i = 0; i < _size; i++)
    {
        _matrix[i] -= other[i];
    }
    return *this;
}

/**
     *
     * @param other the other matrix
     * @return other matrix times this matrix
     */
Matrix Matrix::operator*(const Matrix &other) const
{
    if (_cols != other._rows)
    {
        std::cerr
                << "ERROR: Operator * Failed. Matrix Sizes didn't Match."
                << std::endl;
        exit(1);
    }
    Matrix sum(_rows, other._cols);
    float temp;

    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < other._cols; j++)
        {
            temp = 0;
            for (int k = 0; k < _cols; k++)
            {
                temp += (*this)(i, k) * other(k, j);
            }
            sum(i, j) = temp;
        }
    }
    return sum;
}

/**
      *
      * @param other the other matrix
      * @return other matrix times this matrix
      */
Matrix &Matrix::operator*=(const Matrix &other)
{
    if (_cols != other._rows)
    {
        std::cerr
                << "ERROR: Operator *= Failed. Matrix Sizes didn't Match."
                << std::endl;
        exit(1);
    }

    Matrix res = *this * other;
    *this = res;
    return *this;
}

/**
    *
    * @param input binary file in ifstream format that represents float numbers
    * @param m matrix of float
    */
void operator>>(std::ifstream &input, Matrix &m)
{

    float f;
    int i = 0;
    while (input.read(reinterpret_cast<char *>(&f), sizeof(float)) && i < m._size)
    {
        m[i] = f;
        ++i;
    }
    if (i < m.getCols() * m.getRows())
    {
        std::cerr << "ERROR: File is too small for matrix." << std::endl;
        exit(1);
    }
}

/**
    *
    * @param out out ostream
    * @param m matrix
    * @return prints matirx to ostream
    */
std::ostream &operator<<(std::ostream &out, Matrix &m)
{
    for (int i = 0; i < m._rows; ++i)
    {
        for (int j = 0; j < m._cols; j++)
        {
            if (m(i, j) <= float(0.1))
            {
                out << "  ";
            }
            else
            {
                out << "**";
            }
        }
        out << std::endl;
    }
    return out;
}

/**
    *
    * @param f float
    * @return matrix times float
    */
Matrix Matrix::operator*(float f) const
{
    Matrix toReturn(*this);
    for (int i = 0; i < _size; i++)
    {
        toReturn[i] = (*this)[i] * f;
    }
    return toReturn;
}

/**
  *
  * @param f float
  * @return matrix times float
  */
Matrix operator*(float f, const Matrix &m)
{
    return m.operator*(f);

}

