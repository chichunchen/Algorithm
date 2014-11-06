#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

ifstream infile;
//ostream outfile;

int* Input( int size ) {
	int* A = new int[size];
	for( int i = 0; i < size; i++) {
		infile >> A[i];
	}
	return A;
}
 
template<class T>
int findPeakUtil(T arr[], int low, int high, int size)
{
    int mid = low + (high - low)/2; 
 
    if ((mid == 0 || arr[mid-1] <= arr[mid]) &&
            (mid == size-1 || arr[mid+1] <= arr[mid]))
        return mid;
 
    else if (mid > 0 && arr[mid-1] > arr[mid])
        return findPeakUtil(arr, low, (mid -1), size);
 
    else return findPeakUtil(arr, (mid + 1), high, size);
}
 
// A wrapper over recursive function findPeakUtil()
int quick_find_1d_peak(int arr[], int n)
{
    return findPeakUtil(arr, 0, n-1, n);
}
 
/* Driver program to check above functions */
int main()
{
	infile.open("input_1d.txt");
	if(!infile) {
		cerr<<"Error in opening the file for input!";
		exit(1);
	}
	
	while( !infile.eof() ) {
		int size;
		infile>>size;
		int* A = Input(size);
		cout << A[ quick_find_1d_peak(A, size) ] << endl;
	} 
	
	infile.close();
	
    return 0;
}
