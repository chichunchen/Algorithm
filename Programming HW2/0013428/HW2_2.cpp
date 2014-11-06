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
T Median_of_3( T* A, int a, int b, int c ) {
	if( (A[a]<=A[b] && A[a] >=A[c]) || (A[a]<=A[c] && A[a] >=A[b]) ) 
		return a;
	if( (A[b]<=A[a] && A[b] >=A[c]) || (A[b]<=A[c] && A[b] >=A[a]) ) 
		return b;
	if( (A[c]<=A[a] && A[c] >=A[b]) || (A[c]<=A[b] && A[c] >=A[a]) ) 
		return c;		
}

template<class T>
int Partition( T* A, int p, int q ) {
	srand( time( NULL ) );
	//three random index
	int x = p + ( rand() % ( q-p+1 ) );
	int y = p + ( rand() % ( q-p+1 ) );
	int z = p + ( rand() % ( q-p+1 ) );
	
	//median of three random index
	int random = Median_of_3( A, x, y, z);
	//cout<<x<<" "<<y<<" "<<z<<" "<<"median"<<random<<endl;
	
	swap( A, random, p );
	
	T pivot = A[p];
	
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
void Median3QuickSort( T* A, int p, int q ) {
	if(p < q) {
		int pivot = Partition(A, p, q);
		Median3QuickSort(A, p, pivot-1);
		Median3QuickSort(A, pivot+1, q);
	}
}

int main() {
	
	int size;
	
	while( cin >> size ) {
		int* A = new int[size];
		input(A, size);
		Median3QuickSort(A, 0, size-1);
		print(A, size);
	}
	
	return 0;
}
