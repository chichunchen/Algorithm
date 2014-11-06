#include <iostream>
using namespace std;

const int size = 8;

template<class T>
void print( T* A, int s ) {
	for( int i = 0; i < s; i++ ) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

template<class T>
void swap( T* A, int n, int m ) {
	T temp = A[n];
	A[n] = A[m];
	A[m] = temp;
}

template<class T>
int Partition( T* A, int p, int q ) {
	T x = A[p];	//pivot
	int i  = p;
	for( int j = p+1; j <= q; j++ ) {
		if( A[j] < x ) {
			i++;
			swap( A, i, j );
		}	
	}
	//將pivot跟最末端的比pivot小的直互換 
	swap( A, p, i );
	
	return i;
}

template<class T>
void QuickSort( T* A, int p, int q ) {
	if(p < q) {
		int pivot = Partition(A, p, q);
		QuickSort(A, p, pivot-1);
		QuickSort(A, pivot+1, q);
	}
}

int main() {
	
	int A[size] = {6, 10, 13, 5, 8, 3, 2, 11};
	double B[size] = {2.3, 56.0, 0.0, -312.8, 99.124, 32.111, 898.0, 0.1};
	
	print(A, size);
	QuickSort(A, 0, size-1);
	print(A, size);
	
	print(B, size);
	QuickSort(B, 0, size-1);
	print(B, size);
	
	return 0;
}
