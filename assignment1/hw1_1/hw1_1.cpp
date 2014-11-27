#include <iostream>
using namespace std;
 
int* Input( int size ) {
	int* A = new int[size];
	for( int i = 0; i < size; i++) {
		cin >> A[i];
	}
	return A;
}
 
template<class T>
int findPeakUtil(T arr[], int low, int high, int size)
{
    int mid = low + (high - low)/2; 
 
    if ( ( mid == 0 || arr[mid-1] <= arr[mid] ) && ( mid == size-1 || arr[mid+1] <= arr[mid] ) )
        return mid;
 
    else if (mid > 0 && arr[mid-1] > arr[mid])
        return findPeakUtil(arr, low, (mid -1), size);
 
    else 
		return findPeakUtil(arr, (mid + 1), high, size);
}
 
/* A wrapper over findPeakUtil() */
int quick_find_1d_peak(int arr[], int n) {
    return findPeakUtil(arr, 0, n-1, n);
}
 
/* Driver program to check above functions */
int main() {
	int size;
    cout<<"Input the size of array > 0: ";
	while(cin>>size) {
		
		int* A = Input(size);
		cout<<A[quick_find_1d_peak(A, size)]<<endl;
		cout<<"Input the size of array > 0: ";
	}
	
    return 0;
}
