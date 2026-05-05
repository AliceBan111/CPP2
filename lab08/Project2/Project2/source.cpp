
#include"cppinterface.h"
#pragma warning (disable : 4996)


short // echoes a short
EchoShort(short x // number to be echoed
           )
{
    return x;
}

MyMatrix
AddMatrix(const MyMatrix& MatrixA,
	const MyMatrix& MatrixB) {

	if (MatrixA.rows() != MatrixB.rows())
		throw("Matrices must have the same number of rows!");
	if (MatrixA.columns() != MatrixB.columns())
		throw("Matrices must have the same number of columns!");

	MyMatrix result(MatrixA.rows(), MatrixB.columns());

	for (size_t r = 0; r < MatrixA.rows(); r++) {
		for (size_t c = 0; c < MatrixB.columns(); c++) {
			result(r, c) = MatrixA(r, c) + MatrixB(r, c);
		}
	}

	return result;
}