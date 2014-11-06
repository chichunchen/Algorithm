#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template<class T>
void print( T* A, int s ) {
	for( int i = 0; i < s; i++ ) {
		cout<<A[i]<<" ";
	}
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
int Rand_Partition( T* A, int p, int q ) {
	srand(time(NULL));
	int random = p + (rand()%(q-p+1));
	swap(A, random, p);
	
	T x = A[p];
		
	int i  = p;
	for( int j = p+1; j <= q; j++ ) {
		if( A[j] < x ) {
			i++;
			swap( A, i, j );
		}	
	}
	 
	swap( A, p, i );
	
	return i;
}

template<class T>
T Rand_Select( T* A, int p, int q, int i ) {
	if( p == q )
		return A[p];
	int r = Rand_Partition( A, p, q );
	int k = r - p +1;		//the partition number's rank => k = rank(A[r])
	
	if( i == k ) 
		return A[r];
	if( i < k ) 
		Rand_Select( A, p, r-1, i);
	else 
		Rand_Select( A, r+1, q, i-k );
}

int main() {
	
	int size;
	
	while( cin >> size ) {
		double* A = new double[size];
		input(A, size);
		int Rank;
		cin >> Rank;
		cout<<Rand_Select( A, 0, size-1, Rank )<<endl;
		//print(A, size);
	}

	return 0;
}
