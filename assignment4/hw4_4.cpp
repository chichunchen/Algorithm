#include <iostream>
using namespace std;

int TD_Carpenter( int i, int j, int** Cost, int* A ) {

	if( j <= i + 1 ) {
		Cost[ i ][ j ] = 0;
		return 0;
	}
	else {

		int temp1 = TD_Carpenter( i, i + 1, Cost, A ) + TD_Carpenter( i + 1, j, Cost, A );
		int temp2;
		
		for( int k = i + 2; k < j; k++ ) {
			
			temp2 = TD_Carpenter( i, k, Cost, A ) + TD_Carpenter( k, j, Cost, A ); 
			
			if( temp2 < temp1 )
				temp1 = temp2;
		}

		Cost[ i ][ j ] = temp1 + ( A[ j ] - A[ i ] );

		return Cost[ i ][ j ];
	}
}

int** CreateArray( int n ) {

	int** C = new int*[ n ];

	for( int i = 0; i < n; i++) {
		
		C[i] = new int[ n + 1 ];
		
		for(int j = 0; j < n + 1; j++) {
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
		cout << "Minimum cost : " << TD_Carpenter( 0, n + 1, Cost, A ) << endl;
		//print( Cost, n + 1 );
	
	}

	return 0;
}