#ifndef	MATRIX_H
#define  MATRIX_H

#include <iostream>


using namespace std;

class Matrix{
	public:
		Matrix();
		Matrix(int x, int y, int e);
		Matrix (const Matrix &);

		~Matrix();
		
		const Matrix & Matrix :: operator = (const Matrix& rhs);
		bool Matrix :: operator == (const Matrix & rhs);
		void print();
		int getRowNumber () const;
		int getColumnNumber () const;
		int getElementAt (int i, int j) const;
		void setElementAt (int i, int j, int e) const;
		

	private:
		int ** elements;
		int rowNumber;
		int columnNumber;
		
		
		void createClone (const Matrix & );
		void clear();
};

Matrix operator +(const Matrix & lhs, const Matrix & rhs);
Matrix operator - (const Matrix & lhs, const Matrix & rhs);
Matrix operator ! (const Matrix& lhs);

#endif