#include<iostream>
using namespace std;

void fib_bottom_up( int n, long long int* A ) {

	int i;

	for( i = 2; i <= n; i++ ) {
		A[i] = A[i-1] + A[i-2];
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
		//cout << fib_bottom_up( n, A ) << endl;
		fib_bottom_up( n, A );
		cout << A[ n ] << endl;
		//printArray( n, A );
		//cout<<"input n >=0: ";
	}

	return 0;
}