#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

const int size = 8;

void print( int* A, int s );

void CountingSort( int* A, int* B, int k ) {
	int Csize = k + 1;
	int* C = new int [Csize];
	
	//fill 0 to C array
	for( int i = 0; i < Csize; i++ ){
		C[i] = 0;
	} 
	print(C, k+1);
	
	//count the element's appearance times
	for( int j = size - 1; j >= 0; j-- ) {
		C[ A[j] ] = C[ A[j] ] + 1;
	}
	print(C, Csize);
	
	//計算出限次數的累積
	for( int i = 1; i < Csize; i++ ) {
		C[i] = C[i-1] + C[i];
	} 
	print(C, Csize);
	print(B, size);
	//put C array's result into B array
	for( int j = size - 1 ; j >= 0; j-- ) {
		B[ C[A[j]] - 1 ] = A[j];
		C[ A[j] ] = C[ A[j] ] - 1;
	}
}

void print( int* A, int s ) {
	for( int i = 0; i < s; i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int main() {
	
	//int A[size] = {7688, 6877, 8786, 7678, 6766};
	int A[size] = {2, 5, 3, 0, 2, 3, 0, 3};
	int B[size] = {0};
	
	print(A, size);
	
	CountingSort( A, B, 5 );
	
	print(B, size);
	
	return 0;
}
