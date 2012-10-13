/*
 * matrixhelper.h
 *
 *  Created on: 13.10.2012
 *      Author: mraatika
 */

#ifndef MATRIXHELPER_H_
#define MATRIXHELPER_H_


class MatrixHelper {
public:
	MatrixHelper();
	virtual ~MatrixHelper() {};

	static int** initMatrix(int size);
};

#endif /* MATRIXHELPER_H_ */
