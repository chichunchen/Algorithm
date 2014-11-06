#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

int* RandomInput(int size,int digits) {
	int range = pow(10, digits);
	int* A = new int[size];
	srand(time(NULL));
	for( int i = 0; i < size; i++) {
		A[i] = rand() % range;
	}
	return A;
}

void PrintArray(int* A, int size) {
	for( int i = 0; i < size; i++ ) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

template<class T>
int quick_find_1d_peak(T* A, int i, int j) {
	int m = (i+j)/2;
	if(A[m]>=A[m-1] && A[m]>=A[m+1]) {
		return m;
	}
	else if(A[m]<A[m-1]) {
		quick_find_1d_peak(A, i, m-1);	
	}
	else if(A[m]<A[m+1]) {
		quick_find_1d_peak(A, m+1, j);
	}
}

int main() {
	
	cout<<"Input the size of array > 0: ";
	while(1) {
		int size, digits;
		cin>>size;
		cout<<"Input the digits > 0: ";
		cin>>digits;
		int* A = RandomInput(size, digits);
		PrintArray(A, size);
		cout<<"One of the peak is A["<<quick_find_1d_peak(A, 0, size)<<"]= "<<A[quick_find_1d_peak(A, 0, size)]<<endl;
	}
	
	return 0;
}
