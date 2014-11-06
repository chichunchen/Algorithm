#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

int** InputRandomArray(int digits, int rows, int cols) {
	int range = pow(10, digits);
	int m, n;
	srand(time(NULL));
	rows+=2; cols+=2;
	int** A = new int*[rows];
	for( int i = 0; i < rows; i++) {
		A[i] = new int[cols];
		for(int j = 0; j < cols; j++) {
			if(i>0 && i<rows-1 && j>0 && j<cols-1) {
				A[i][j] = rand() % range;
			}else A[i][j] = 0;	
		}
	}
	return A;
}

void print(int** A, int digits,int rows, int cols){
	rows+=2; cols+=2;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<<setw(digits)<<A[i][j]<<" ";
        }    
        cout<<endl;
    }
}

int quick_find_2d_peak(int** A, int i, int j, int c, int d) {
	int m1 = (i+j)/2;
	int m2 = (c+d)/2;
	int max = 0;
	int a, b;	//store the dimension of temporary max
	//find the maximum in (m, a)
	for( int x = c; x <= d; x++) {
		if(A[m1][x]>max) {
			max = A[m1][x];
			a = m1; b = x;
		}
	}
	for( int y = i; y <= j; y++) {
		if(A[y][m2]>max) {
			max = A[y][m2];
			a = y; b = m2;
		}
	}//a: rows, b: cols
	
	//if its a peak then return
	if(max>=A[a+1][b] && max>=A[a-1][b] && max>=A[a][b+1] && max>=A[a][b-1]) {
		cout<<"(rows, cols) = ("<<a<<", "<<b<<") is a peak number, which value is ";
		return max;
	}
	else if(max<A[a+1][b]) {
		if(b<m2) 
			return quick_find_2d_peak(A, m1+1, j-1, c+1, m2-1);		//左下
		else
			return quick_find_2d_peak(A, m1+1, j-1, m2+1, d-1);		//右下 
	}
	else if(max<A[a-1][b]) {
		if(b<m2)
			return quick_find_2d_peak(A, i+1, m1-1, c+1, m2-1);		//左上
		else
			return quick_find_2d_peak(A, i+1, m1-1, m2+1, d-1);		//右上 
	}
	else if(max<A[a][b+1]) {
		if(a<m1)
			return quick_find_2d_peak(A, i+1, m1-1, m2+1, d-1);		//右上
		else
			return quick_find_2d_peak(A, m1+1, j-1, m2+1, d-1);		//右下 
	}
	else if(max<A[a][b-1]) {
		if(a<m1)
			return quick_find_2d_peak(A, i+1, m1-1, c+1, m2-1);		//左上
		else
			return quick_find_2d_peak(A, m1+1, j-1, c+1, m2-1);		//左下
	}
}

int main() {
	
	int r;
	cout<<"Input the number of rows/cols > 0: ";
	
	while(1) {
		cin>>r;
		int digits;
		cout<<"Input the digit > 1: ";
		cin>>digits;
		int** A = InputRandomArray(digits, r, r);
		print(A, digits,r, r);
		cout<<quick_find_2d_peak(A, 1, r, 1, r)<<endl;
		cout<<"Input the number of rows/cols>=0"<<endl;
	}
	
	return 0;
}
