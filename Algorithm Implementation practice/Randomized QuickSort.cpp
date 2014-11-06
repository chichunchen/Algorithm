#include <iostream>
#include <cstdlib>
#include <ctime>
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
	srand(time(NULL));
	int random = p + (rand()%(q-p+1));
	swap(A, random, p);
	//print(A, q+1);
	
	T x = A[p];
	//cout<<"key: "<<x<<endl;
	
	int i  = p;
	for( int j = p+1; j <= q; j++ ) {
		if( A[j] < x ) {
			i++;
			swap( A, i, j );
		}	
	}
	//將pivot跟最末端的比pivot小的直互換 
	swap( A, p, i );
	//print(A, q+1);
	return i;
}

template<class T>
void RandomizedQuickSort( T* A, int p, int q ) {
	if(p < q) {
		int pivot = Partition(A, p, q);
		//print(A, size);
		RandomizedQuickSort(A, p, pivot-1);
		RandomizedQuickSort(A, pivot+1, q);
	}
}

int main() {
	
	int A[size] = {6, 10, 13, 5, 10, 2, 2, 11};
	double B[size] = {2.3, 56.0, 0.0, -312.8, 99.124, 32.111, 898.0, 0.1};
	
	print(A, size);
	RandomizedQuickSort(A, 0, size-1);
	//Partition(A, 0, size-1);
	print(A, size);
	
	
	return 0;
}
