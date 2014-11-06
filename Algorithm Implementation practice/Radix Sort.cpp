#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>
using namespace std;

const int size = 10;

void print( int* A, int s );

int getMax( int* A, int n ) {
	int max = 0;
	for( int i = 0; i < n; i++ ) {
		if( A[i] > max ) max = A[i];
	}
	return max;
}

void CountingSort( int* A, int n, int exp ) {
	int output[n];
	int i, bucket[10] = {0};
	
	//store count of occurrence in bucket[]
	for( i = 0; i < n; i++ ) {
		++bucket[ (A[i]/exp)%10 ];
	}
	
	//Change bucket[i] so that bucket[i] has actual position
	for( i = 1; i < 10; i++ ) {
		bucket[i] += bucket[i-1]; 
	}

	for( i = n-1; i >= 0; i-- ) {
		output[ bucket[ (A[i]/exp)%10] - 1 ] = A[i];
		bucket[ (A[i]/exp)%10]--;	
	}
	
	for( i = 0; i < n; i++) {
		A[i] = output[i];
	}
	//print(A, n);
}

void RadixSort( int* A, int n ) {
	int m = getMax(A, n);
	
	for( int exp = 1; m/exp > 0; exp *= 10 ) {
		CountingSort(A, n, exp);	
	}
}

void print( int* A, int s ) {
	for( int i = 0; i < s; i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl<<endl;
}

int main() {
	
	int A[size] = {7688, 6877, 8786, 7678, 6766, 2345, 4532, 5634, 5639, 9999};
	
	print(A, size);
	
	RadixSort(A, size);
	
	print(A, size);
	
	return 0;
}
