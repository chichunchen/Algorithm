#include<iostream>
using namespace std;

long long int fib_memoize( int n, long long int* A ) {

	if( A[ n ] == -1 ) {
		A[ n ] = fib_memoize( n - 1, A ) + fib_memoize( n - 2, A );
		return A[ n ];
	}
	else {
		return A[ n ];
	}
}

long long int* creatArray( int n ) {
	long long int* c = new long long int[n+1];

	c[0] = 0;
	c[1] = 1;

	for( int i = 2; i <= n; i++ )
		c[ i ] = -1;

	return c;
}

void printArray( int n, long long int* A ) {

	for ( int i = 0; i <= n; i++ ) {
		cout<<A[ i ]<<" ";
	}
	
	cout<<endl;
}


int main() {

	int n;
	//cout<<"input n >=0: ";
	
	while( cin >> n ) {
		long long int *A = creatArray( n );
		fib_memoize( n, A );
		cout << A[ n ] << endl;
		//printArray( n, A );
		//cout<<"input n >=0: ";
	}

	return 0;
}