#include <iostream>

using namespace std;

int** Input(int s) {
	s+=2;
	int** A = new int*[s];
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
	
	int size;
	cout<<"Input array's size > 0: ";
	
	while(1) {
		cin>>size;
		int** A = Input(size);
		print(A, size);
		cout<<quick_find_2d_peak(A, 1, size, 1, size)<<endl;
		cout<<"Input array's size > 0: "<<endl;
	}
	
	return 0;
}
