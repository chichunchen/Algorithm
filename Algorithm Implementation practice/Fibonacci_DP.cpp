#include<iostream>
using namespace std;

int fib( int n, int* A ) {

	int i;

	for( i = 2; i <= n; i++ ) {
		A[i] = A[i-1] + A[i-2];
	}

	return A[i-1];
}

int* creatArray( int n ) {
	int* c = new int[n+1];

	c[0] = 0;
	c[1] = 1;

	for( int i = 2; i <= n; i++ )
		c[ i ] = -1;

	return c;
}

void printArray( int n, int* A ) {

	for ( int i = 0; i <= n; i++ ) {
		cout<<A[ i ]<<" ";
	}
	
	cout<<endl;
}

int main() {

	int n;
	cout<<"input n >=0: ";
	
	while( cin >> n ) {
		int *A = creatArray( n );
		cout <<"\nf("<<n<<") = "<< fib( n, A ) << endl;
		printArray( n, A );
		cout<<"input n >=0: ";
	}

	return 0;
}