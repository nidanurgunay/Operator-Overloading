#include <iostream>
#include "Matrix.h"

// default constructer
Matrix:: Matrix()
{
	elements=NULL;
	rowNumber=0;
	columnNumber=0;
}

// constructor
Matrix::Matrix(int x, int y, int e)
{
	if(x>=0 && y>=0)
	{elements=new int*[x];
	for(int i=0; i<x;i++)
	{
		elements[i]=new int[y];
		for(int j=0;j<y;j++)
		{
			elements[i][j]=e;
		}
	}
	rowNumber=x;
	columnNumber=y;}
	else
	{
		elements=NULL;
	rowNumber=0;
	columnNumber=0;
	}
	
}
// copy constructer
Matrix :: Matrix (const Matrix & copy)
{
	createClone(copy);
}

//destructor    ??????????//
Matrix::~Matrix()
{

	for(int i=0; i<rowNumber;i++)
	{
		delete  elements[i];
	}
	delete [] elements;
	elements=NULL;
}




// returns the numver of columns
int Matrix ::  getColumnNumber() const
{
	return columnNumber;
}

// returns the number of rows
int Matrix ::  getRowNumber() const
{
	return rowNumber;
}

// returns the element at the given coordinates 
int Matrix ::  getElementAt(int i, int j) const
{
	return elements[i][j];
}

// sets the elements at given coordinates as e
void Matrix:: setElementAt (int i, int j, int e) const
{
	elements[i][j]=e;
}


/// deep copy constructor
void Matrix::  createClone(const Matrix& copy)
{
	if(copy.elements==NULL)
	{
		elements=NULL;
		rowNumber=0;
		columnNumber=0;
		
	}
	else
	{
		rowNumber=copy.rowNumber;
		columnNumber=copy.columnNumber;
		elements=new int* [rowNumber];
		for(int i=0; i<rowNumber;i++)
		{
			elements[i]=new int[columnNumber];
			for(int j=0;j<columnNumber;j++)
			{
				elements[i][j]=copy.elements[i][j];
			}
		}

	}
}

//print function
void Matrix:: print()
{
	for (int i=0; i<rowNumber; i++)
	{
		for(int j=0; j<columnNumber;j++)
		{
			cout<< elements[i][j]<< " " ;
		}
		cout<<endl;
	}
}

void Matrix :: clear()
{
	
	for(int i=0; i<rowNumber;i++)
	{
		delete  elements[i];
	}
	elements=NULL;
}



const Matrix & Matrix :: operator =(const Matrix & rhs)
{
	if (this != &rhs)
	{
		clear();
		createClone(rhs);
	}
	return * this;
}

bool Matrix :: operator ==(const Matrix & rhs)
{
	int same = rhs.columnNumber*rhs.rowNumber;
	int count=0;
	for(int i=0; i<rowNumber;i++)
	{
		for(int j=0; j<columnNumber; j++)
		{
			if(elements[i][j]== rhs.getElementAt(i,j))
				count++;
		}
	}
	if(same==count)
		return true;
	else
		return false;

}


// free functions///////////
 Matrix  operator + (const Matrix & lhs, const Matrix & rhs)
{
	Matrix result(lhs);
	Matrix rhss(rhs);
	for(int i =0; i<result.getRowNumber();i++)
	{
		for(int j=0; j<result.getColumnNumber(); j++)
		{
			result.setElementAt(i,j,result.getElementAt(i,j)+rhss.getElementAt(i,j));
		}
	}

	return result;
}

  Matrix  operator - (const Matrix & lhs, const Matrix & rhs)
{
	Matrix result(lhs);
	Matrix rhss(rhs);
	for(int i =0; i<result.getRowNumber();i++)
	{
		for(int j=0; j<result.getColumnNumber(); j++)
		{
			result.setElementAt(i,j,result.getElementAt(i,j)-rhss.getElementAt(i,j));
		}
	}

	return result;
}

    Matrix  operator ! (const Matrix & lhs)
	{
		Matrix result (lhs.getColumnNumber(),lhs.getRowNumber(),0);
		for(int i=0;i<lhs.getColumnNumber();i++)
		{
			for(int j=0; j<lhs.getRowNumber(); j++)
			{
				result.setElementAt(i,j,lhs.getElementAt(j,i));
			}
		}

		return result;
	}



