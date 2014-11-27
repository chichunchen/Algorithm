#include <iostream>
using namespace std;

template<class T>
T** Input(T s) {
	s+=2;
	T** A = new T*[s];
	for( int i = 0; i < s; i++) {
		A[i] = new int[s];
		for(int j = 0; j < s; j++) {
			if(i>0 && i<s-1 && j>0 && j<s-1) {
				cin >> A[i][j];
			}else A[i][j] = 0;	
		}
	}
	return A;
}


void print(int** A, int s){
	s+=2;
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            cout<<A[i][j]<<" ";
        }    
        cout<<endl;
    }
}


template<class T>
T quick_find_2d_peak(T** A, int i, int j, int c, int d) {	
	int m1 = (i+j)/2;
	int m2 = (c+d)/2;
	int max = 0;
	int a, b;             /* store the dimension of temporary max */

	/* find the maximum in (m, a) */
	for( int x = c; x <= d; x++) {
		if( A[m1][x] > max ) {
			max = A[m1][x];
			a = m1; b = x;
		}
	}
	for( int y = i; y <= j; y++) {
		if( A[y][m2] > max ) {
			max = A[y][m2];
			a = y; b = m2;
		}
	}//a: rows, b: cols
	//cout<<"max of row, col:"<< a <<" "<< b<<endl; 
	
	//if its a peak then return
	if(max>=A[a+1][b] && max>=A[a-1][b] && max>=A[a][b+1] && max>=A[a][b-1]) {
		//cout<<"(rows, cols) = ("<<a<<", "<<b<<") is a peak number, which value is ";
		return max;
	}
	else if(max<A[a+1][b]) {
		if(b<m2) {
			//cout<<"leftdown"<<m1+1<<" "<<j-1<<" "<<c+1<<" "<<m2-1<<endl;
			return quick_find_2d_peak(A, m1+1, j, c, m2-1);		//左下
		}
		else{
			//cout<<"rightdown"<<m1+1<<" "<<j-1<<" "<<m2+1<<" "<<d-1<<endl;
			return quick_find_2d_peak(A, m1+1, j, m2+1, d);		//右下 
		}
	}
	else if(max<A[a-1][b]) {
		if(b<m2){
			//cout<<"leftup"<<i+1<<" "<<m1-1<<" "<<c+1<<" "<<m2-1<<endl;
			return quick_find_2d_peak(A, i, m1-1, c, m2-1);		//左上
		}
		else {
			//cout<<"rightup"<<i+1<<" "<<m1-1<<" "<<m2+1<<" "<<d-1<<endl;
			return quick_find_2d_peak(A, i, m1-1, m2+1, d);		//右上 
		}
	}
	else if(max<A[a][b+1]) {
		if(a<m1) {
			//cout<<"rightup"<<i+1<<" "<<m1-1<<" "<<m2+1<<" "<<d-1<<endl;
			return quick_find_2d_peak(A, i, m1-1, m2+1, d);		//右上
		}
		else {
			//cout<<"rightdown"<<m1+1<<" "<<j-1<<" "<<m2+1<<" "<<d-1<<endl;
			return quick_find_2d_peak(A, m1+1, j, m2+1, d);		//右下 
		}
	}
	//else (max<A[a][b-1]) {
    else {
		if(a<m1) {
			//cout<<"leftup"<<i+1<<" "<<m1-1<<" "<<c+1<<" "<<m2-1<<endl;
			return quick_find_2d_peak(A, i, m1-1, c, m2-1);		//左上
		}
		else {
			//cout<<"leftdown"<<m1+1<<" "<<j-1<<" "<<c+1<<" "<<m2-1<<endl;
			return quick_find_2d_peak(A, m1+1, j, c, m2-1);		//左下
		}
	}
}


int main() 
{
    int size;
    cout << "Input array's size > 0: ";

    while( cin >> size ) {
        int** A = Input(size);
        // print(A, size);
        cout << quick_find_2d_peak(A, 1, size, 1, size) << endl;
        cout << "Input array's size > 0: ";
    }
	
	return 0;
}
