#include <iostream>
#include <iomanip>
using namespace std;

const int size = 10;

template<class T>
void swap(T* A, int m, int n) {
	T temp = A[m];
	A[m] = A[n];
	A[n] = temp;
}

template<class T>
void MaxHeapify(T* A, int i, int size) {
	int left = (2*i)+1, right = (2*i)+2;
	int larger;
	
	if(left < size && A[left] > A[i]) {
		larger = left;
	}else larger = i;
	
	if(right < size && A[right] > A[larger])
		larger = right;
	
	if(larger != i) {
		swap(A, i, larger);
		MaxHeapify(A, larger, size);
	}	 
}

template<class T>
void BuildMaxHeap(T* A, int s) {
	for( int i = s/2-1; i >= 0; i-- ) {
		MaxHeapify(A, i, size);
	}
}

template<class T>
void HeapSort(T* A, int s) {
	BuildMaxHeap(A, s);
	for( int i = s; i >= 2; ) {
		swap(A, 0, i-1);
		MaxHeapify(A, 0, --i);
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
	
	int A[size] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	
	print(A, size);
	
	HeapSort(A, size);
	
	print(A, size);
	
	return 0;
}

