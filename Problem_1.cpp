// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 1
// Program: CS213-2018-A1-T1-P1
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
    int* data;       // Pointer to 1-D array that will simulate matrix
    int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g.ٍSarah said Abrahim, 20170111)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g.Shrouk Nady Taha, 20170128)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int data4 [8]= {};

    matrix mat1, mat2, mat3,mat4;
    createMatrix (4, 2, data1, mat1);
    createMatrix (2, 3, data2, mat2);
    createMatrix (4, 2, data3, mat3);

    //The next code will not work until you write the functions
    cout << mat1 << endl;
    cout << mat2 << endl;
    cout << mat3 << endl;

    cout << (mat1 + mat3) << endl << endl;
    cout << (mat3 + mat3) << endl << endl;

    ++mat1;
    cout << mat1 << endl;

    mat1+= mat3 += mat3;
    cout << mat1 << endl;
    cout << mat2 << endl;
    cout << mat3 << endl;
    // Add more examples of using matrix
    // .......
    return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int [row * col];
    for (int i = 0; i < row * col; i++)
        mat.data [i] = num [i];
}
//__________________________________________
matrix operator+  (matrix mat1, matrix mat2)
{
    assert(mat1.row==mat2.row&&mat1.col==mat2.col);
    int a[mat1.col * mat1.row];
    matrix mat3 ;
    createMatrix ( mat1.row, mat1.col, a, mat3 );
    mat3.data=new int[mat3.col * mat3.row];
    for( int i=0 ; i<(mat1.col * mat1.row) ; i++ )
    {
        mat3.data[i]=mat1.data[i]+mat2.data[i];
    }
    return mat3;
}
//__________________________________________
matrix operator-  (matrix mat1, matrix mat2)
{
    //assert(mat1.row==mat2.row && mat1.col==mat2.col);
    int a[mat1.col * mat1.row];
    matrix mat3 ;
    createMatrix ( mat1.row, mat1.col, a, mat3 );
    for( int i=0 ; i<(mat1.col * mat1.row) ; i++ )
    {
        mat3.data[i]=mat1.data[i]+mat2.data[i];
    }
    return mat3;
}
//__________________________________________
matrix operator*  (matrix mat1, matrix mat2)
{
    int a[mat1.row * mat2.col], sum=0 ;
    matrix mat3 ;
    createMatrix ( mat1.row, mat2.col, a, mat3 );
    for( int i=0 ; i<(mat1.row) ; i++ )
    {
        for ( int j=0 ; j<mat2.col; j++ )
        {
            int sum=0 ;
            for ( int k=0 ; k<mat2.row ; k++)
            {
                sum+=( mat1.data[i * mat1.col + k] * mat2.data[k * mat2.col + j]);
            }
            mat3.data[i * mat3.col + j] = sum;
        }
    }
    return mat3;
}
//__________________________________________
matrix operator+  (matrix mat1, int scalar)
{

    for( int i=0 ; i<(mat1.col * mat1.row) ; i++ )
    {
        mat1.data[i]=mat1.data[i]+scalar;
    }
    return mat1;
}
//__________________________________________
matrix operator-  (matrix mat1, int scalar)
{
    for( int i=0 ; i<(mat1.col * mat1.row) ; i++ )
    {
        mat1.data[i]=mat1.data[i]-scalar;
    }
    return mat1;
}
//__________________________________________
matrix operator*  (matrix mat1, int scalar)
{
    for( int i=0 ; i<(mat1.col * mat1.row) ; i++ )
    {
        mat1.data[i]=mat1.data[i]*scalar;
    }
    return mat1;
}
//__________________________________________
matrix operator+= (matrix& mat1, matrix mat2)
{
    assert(mat1.row==mat2.row&&mat1.col==mat2.col);
    for( int i=0 ; i<(mat1.col * mat1.row) ; i++ )
    {
        mat1.data[i]=mat1.data[i]+mat2.data[i];
    }
    return mat1;
}
//__________________________________________
matrix operator-= (matrix& mat1, matrix mat2)
{
    assert(mat1.row==mat2.row&&mat1.col==mat2.col);
    for( int i=0 ; i<(mat1.col * mat1.row) ; i++ )
    {
        mat1.data[i]=mat1.data[i]-mat2.data[i];
    }
    return mat1;
}
//__________________________________________
matrix operator+= (matrix& mat, int scalar)
{
    for( int i=0 ; i<(mat.col * mat.row) ; i++ )
    {
        mat.data[i]=mat.data[i]+scalar;
    }
    return mat;
}
//__________________________________________
matrix operator-= (matrix& mat, int scalar)
{
    for( int i=0 ; i<(mat.col * mat.row) ; i++ )
    {
        mat.data[i]=mat.data[i]-scalar;
    }
    return mat;
}
//__________________________________________
void   operator++ (matrix& mat)
{
    for( int i=0 ; i<(mat.col * mat.row) ; i++ )
    {
        mat.data[i]++;
    }
}
//__________________________________________
void   operator-- (matrix& mat)
{
    for( int i=0 ; i<(mat.col * mat.row) ; i++ )
    {
        mat.data[i]--;
    }
}
//__________________________________________
istream& operator>> (istream& in, matrix& mat)
{
    in>>mat.col>>mat.row;
    for(int i=0; i<(mat.col * mat.row); i++)
    {
        in>>mat.data[i];
    }
    return in;
}
//__________________________________________
ostream& operator<< (ostream& out, matrix mat)
{
    for ( int i=0 ; i<(mat.col*mat.row) ; i++ )
    {
        if ( i%mat.col==0 && i!=0 )
        {
            cout << endl ;
        }
        cout << setw(5) << mat.data[i] << " " ;
    }
    return out;
}
//__________________________________________
bool   operator== (matrix mat1, matrix mat2)
{
    assert(mat1.row==mat2.row&&mat1.col==mat2.col);
    int sum=0;
    for(int i = 0 ; i <(mat1.col * mat1.row); i++)
    {
        if(mat1.data[i]==mat2.data[i])
        {
            sum++;
        }
    }
    return(sum==(mat1.col * mat1.row));
}
//__________________________________________
bool   operator!= (matrix mat1, matrix mat2)
{
    assert(mat1.row==mat2.row&&mat1.col==mat2.col);
    int sum=0;
    for(int i = 0 ; i <(mat1.col * mat1.row); i++)
    {
        if(mat1.data[i]==mat2.data[i])
        {
            sum++;
        }
    }
    return(sum!=(mat1.col * mat1.row));
}
//__________________________________________
bool   isSquare   (matrix mat)
{
    if ( mat.row == mat.col )
        return true ;
    else
        return false ;
}
//__________________________________________
bool   isSymetric (matrix mat)
{
    if ( isSquare(mat)==false )
        return 0 ;
    else
    {
        for ( int i=0 ; i<mat.row ; i++ )
        {
            for ( int j=0 ; j<i ; j++ )
            {
                if ( mat.data[i*mat.col+j]!=mat.data[j*mat.col+i] )
                {
                    return 0;
                }
            }
        }
        return 1 ;
    }
}
//__________________________________________
bool   isIdentity (matrix mat)
{
    if ( isSquare(mat)==false)
        return 0;
    else
    {
        for ( int i=0 ; i<mat.row ; i++ )
        {
            if ( mat.data[i*mat.row+i] != 1 )
            {
                return 0 ;
            }
            for ( int j=0 ; j<i ; j++ )
            {
                if ( mat.data[i*mat.col+j]!=mat.data[j*mat.col+i] || mat.data[i*mat.col+j]!=0 || mat.data[j*mat.col+i]!=0 )
                {
                    return 0;
                }
            }
        }
    }
    return 1 ;
}
//__________________________________________
matrix transpose(matrix mat)
{
    matrix mat1;
    int a[mat.col*mat.row];
    createMatrix(mat.col, mat.row, a, mat1 );
    for ( int i=0 ; i<mat1.row ; i++)
    {
        for ( int j=0 ; j<mat1.col ; j++ )
        {
            mat1.data[i*mat1.col+j]=mat.data[j*mat.col+i];
        }
    }
    return mat1 ;
}
