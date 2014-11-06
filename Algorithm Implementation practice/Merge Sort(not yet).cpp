#include <iostream>
#include <iomanip>
using namespace std;

const int size = 3;

template<class T>
void print(T* A, int s);

template<class T>
void swap(T* A, int m, int n) {
	T temp = A[m];
	A[m] = A[n];
	A[n] = temp;
}

template<class T>
void Merge(T* A, int p, int q, int r) {
	int n1 = q;
	int n2 = r-q+1;
	T Left[n1], Right[n2];
	for( int i = 0; i < n1; i++ ) {
		Left[i] = A[i];
	}
	for( int i = 0; i < n2; i++ ) {
		Right[i] = A[n1+i];
	}
	
	int i = 0, j = 0, k;
	for(k=0; k<=r && i < n1 && j < n2; k++) {
		if(Left[i] < Right[j]) {
			A[k] = Left[i];
			i++;
		}else {
			A[k] = Right[j];
			j++;
		}
	}
	//cout<<"i: "<<i<<" j: "<<j<<endl;
	//print(Left, n1);
	//print(Right, n2);
	for(k=i+j; k <= r && i<=n1; k++) {
		A[k] = Left[i];
		i++;
	}
	for(k=i+j; k <= r && j<=n2; k++) {
		A[k] = Right[j];
		j++;
	}
}

template<class T>
void MergeSort(T* A, int m, int n) {
	if(m<n) {
		int middle = (n-m)/2;
		MergeSort(A, m, middle);
		MergeSort(A, middle+1, n-1);
		cout<<"Middle: "<<middle<<endl;
	}
}

template<class T>
void print(T* A, int s) {
	for( int i = 0; i < s; i++) {
		cout<<setw(2)<<A[i]<<" ";
	}
	cout<<endl;
}

int main() {
	
	int A[size] = {1, 2, 3};
	
	print(A, size);
	
	//MergeSort(A, 0, size);
	Merge(A, 0, size/2, size-1);
	print(A, size);
	
	return 0;
}

