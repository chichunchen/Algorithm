#include <iostream>
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
int median3a( T* A, int a, int b, int c ) {
	if( (A[a]<=A[b] && A[a] >=A[c]) || (A[a]<=A[c] && A[a] >=A[b]) ) 
		return a;
	if( (A[b]<=A[a] && A[b] >=A[c]) || (A[b]<=A[c] && A[b] >=A[a]) ) 
		return b;
	if( (A[c]<=A[a] && A[c] >=A[b]) || (A[c]<=A[b] && A[c] >=A[a]) ) 
		return c;		
}

template<class T>
int TukeysNinther( T* A, int lo, int hi ) {
	int N = hi - lo + 1;	//N is size
    int mid = lo + N/2;	
    int delta = N/8;
    int m1 = median3a( A, lo, lo+delta, lo+2*delta );
    int m2 = median3a( A, mid-delta, mid, mid+delta );
    int m3 = median3a( A, hi-2*delta, hi-delta, hi );
    int tn = median3a( A, m1, m2, m3 );
    
	return tn;
}

template<class T>
int Partition( T* A, int p, int q ) {

	int tuckysChoose = TukeysNinther( A, p, q );
	
	swap( A, tuckysChoose, p );
	
	T pivot = A[p];
	
	int i  = p;
	for( int j = p+1; j <= q; j++ ) {
		if( A[j] < pivot ) {
			i++;
			swap( A, i, j );
		}	
	}
	//將pivot跟最末端的比pivot小的值互換 
	swap( A, p, i );

	return i;
}

template<class T>
void NintherQuickSort( T* A, int p, int q ) {
	if(p < q) {
		int pivot = Partition(A, p, q);
		NintherQuickSort(A, p, pivot-1);
		NintherQuickSort(A, pivot+1, q);
	}
}

int main() {
	
	int size;
	
	while( cin >> size ) {
		int* A = new int[size];
		input(A, size);
		NintherQuickSort(A, 0, size-1);
		print(A, size);
	}
	
	return 0;
}
