
#include"cppinterface.h"
#pragma warning (disable : 4996)


short // echoes a short
EchoShort(short x // number to be echoed
           )
{
    return x;
}

MyMatrix
MultiplyMatrix(const MyMatrix& MatrixA, const MyMatrix& MatrixB) {
    if (MatrixA.columns() != MatrixB.rows())
        throw("Number of columns of A must equal number of rows of B!");

    MyMatrix result(MatrixA.rows(), MatrixB.columns());

    for (size_t r = 0; r < MatrixA.rows(); ++r) {
        for (size_t c = 0; c < MatrixB.columns(); ++c) {
            result(r, c) = 0; // assumes element type is zero-constructible from 0
            for (size_t k = 0; k < MatrixA.columns(); ++k) {
                result(r, c) += MatrixA(r, k) * MatrixB(k, c);
            }
        }
    }

    return result;
}