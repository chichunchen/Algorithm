#include <iostream>
using namespace std;

// Buttom-Up
void BU_Carpenter( int i, int j, int** Cost, int* A ) {

	int n = j - i;

	for( int l = 2; l <= n; l++ ) {

		for( int a = 0; a < ( n - l + 1 ); a++ ) {
			
			int b = a + l;
			Cost[a][b] = 9999;

			for( int k  = a + 1; k < b; k++ ) {

				int q = Cost[a][k] + Cost[k][b] + ( A[b] - A[a] );

				if( q < Cost[a][b] ) {
					Cost[a][b] = q;
				}
			}
		}
	}
}

int** CreateArray( int n ) {

	int** C = new int*[ n ];

	for( int i = 0; i < n; i++) {
		
		C[i] = new int[ n + 1 ];
		
		for(int j = 0; j < n + 1; j++) {
			if( i + 1 == j )
				C[i][j] = 0;
			else
				C[i][j] = -1;	
		}
	}

	return C;
}

void print(int** C, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n + 1; j++){
            cout<<C[i][j]<<" ";
        }    
        cout<<endl;
    }
}

int main() {

	int n, length;

	while( cin >> length ) {

		cin >> n;

		int* A = new int[ n + 2 ];
		A[ 0 ] = 0;
		A[ n + 1 ] = length;

		for( int i = 1; i < n + 1; i++ ) {
			cin >> A[ i ];
		}

		int** Cost = CreateArray( n + 1 );

		//print( Cost, n + 1 );
		BU_Carpenter( 0, n + 1, Cost, A );
		cout << "Minimum cost : " << Cost[0][n+1] << endl;
		//print( Cost, n + 1 );
	
	}

	return 0;
}