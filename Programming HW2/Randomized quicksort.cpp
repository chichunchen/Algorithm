#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template<class T>
void print( T* A, int s ) {
	for( int i = 0; i < s; i++ ) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

template<class T>
void input( T* A, int s ) {
	for( int i = 0; i < s; i++ ) {
		cin>>A[i];
	}
}

template<class T>
void swap( T* A, int n, int m ) {
	T temp = A[n];
	A[n] = A[m];
	A[m] = temp;
}

template<class T>
int Partition( T* A, int p, int q ) {
	srand( time( NULL ) );
	int random = p + ( rand() % ( q-p+1 ) );
	swap( A, random, p );
	
	T pivot = A[p];
	//cout<<"pivot"<<pivot<<endl;
	
	int i  = p;
	for( int j = p+1; j <= q; j++ ) {
		if( A[j] < pivot ) {
			i++;
			swap( A, i, j );
		}	
	}
	//將pivot跟最末端的比pivot小的直互換 
	swap( A, p, i );

	return i;
}

template<class T>
void RandomizedQuickSort( T* A, int p, int q ) {
	if(p < q) {
		int pivot = Partition(A, p, q);
		RandomizedQuickSort(A, p, pivot-1);
		RandomizedQuickSort(A, pivot+1, q);
	}
}

int main() {
	
	int size;
	
	while( cin >> size ) {
		int* A = new int[size];
		input(A, size);
		RandomizedQuickSort(A, 0, size-1);
		print(A, size);
	}

	return 0;
}
