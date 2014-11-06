#include<iostream>
using namespace std;

int fib_recursive( int n ) {

	if( n == 0 ) 
		return 0;
	
	else if ( n == 1 ) 
		return 1;

	else {
		return fib_recursive( n - 1 ) + fib_recursive( n - 2 );
	}
}


int main() {

	int n;
	//cout<<"input n >=0: ";
	
	while( cin >> n ) {
		
		//cout <<"\nf("<<n<<") = "<< fib_recursive( n ) << endl;
		cout << fib_recursive( n ) << endl;
		//cout<<"input n >=0: ";
	}

	return 0;
}